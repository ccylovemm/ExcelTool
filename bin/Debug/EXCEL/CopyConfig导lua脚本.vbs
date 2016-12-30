'如果提示没有权限 在开始-运行中敲入regedit, 然后找到HKEY_CLASSES_ROOT\Scripting.FileSystemObject  右击 点击菜单中的权限 设置好权限
Dim denyCopyId, id, showPassWin, totalTime, drop2, boxDrop, clean, taskId,activeEventId,rewardsStr
Dim gPath 
Set CopyConfigInfoVec = CreateObject("WIA.Vector")
Out_1()

Sub Out_1()
	gPath = CreateObject("Scripting.FileSystemObject").GetFolder(wscript.arguments(0)).Path

	Dim oSheet,oWb,oExcel
	Set	oExcel = CreateObject("Excel.Application")
	Set oWb = oExcel.Workbooks.Open(gPath & "\CopyConfig.xlsx")
	Set oSheet = oWb.Sheets("CopyConfig")
    
	ColumnMax = oSheet.UsedRange.Columns.Count
	For i = 1 To ColumnMax
		If oSheet.Cells(1, i).Value = "denyCopyId" Then
			denyCopyId = i
		ElseIf oSheet.Cells(1, i).Value = "id" Then
			id = i
		ElseIf oSheet.Cells(1, i).Value = "showPassWin" Then
			showPassWin = i
		ElseIf oSheet.Cells(1, i).Value = "totalTime" Then
			totalTime = i
		ElseIf oSheet.Cells(1, i).Value = "drop2" Then
			drop2 = i
		ElseIf oSheet.Cells(1, i).Value = "boxDrop" Then
			boxDrop = i
		ElseIf oSheet.Cells(1, i).Value = "clean" Then
			clean = i
		ElseIf oSheet.Cells(1, i).Value = "task" Then
			taskId = i
		ElseIf oSheet.Cells(1, i).Value = "activeEventId" Then
			activeEventId = i
		ElseIf oSheet.Cells(1, i).Value = "rewardsStr" Then
			rewardsStr = i
		End If
    Next
    Dim pathLen, pathCehua
	pathLen  = Len(gPath)- 5
	pathCehua = Left(gPath, pathLen)
    gPath = pathCehua & "Config/Scripts/Scene" 
	Call GetExcelValue(CopyConfigInfoVec, oSheet)
	Call WriteLuaFile(gPath, CopyConfigInfoVec)
	oExcel.Workbooks.Close
End Sub

Sub GetExcelValue(CopyConfigInfoVec, oSheet)
	Min = 5
    Max = oSheet.UsedRange.Rows.Count
	 For i = Min To Max
		If oSheet.Cells(i, id).Value <> "" Then
			Set CopyConfigInfo = CreateObject("Scripting.Dictionary")
			CopyConfigInfo.Add id, CInt(oSheet.Cells(i, id).Value)
			CopyConfigInfo.Add denyCopyId, CInt(oSheet.Cells(i, denyCopyId).Value)
			CopyConfigInfo.Add showPassWin, CInt(oSheet.Cells(i, showPassWin).Value)
			CopyConfigInfo.Add taskId, CInt(oSheet.Cells(i, taskId).Value)
			CopyConfigInfo.Add totalTime, CInt(oSheet.Cells(i, totalTime).Value)
			CopyConfigInfo.Add drop2, CInt(oSheet.Cells(i, drop2).Value)
			CopyConfigInfo.Add boxDrop, (oSheet.Cells(i, boxDrop).Value)
			CopyConfigInfo.Add clean, CInt(oSheet.Cells(i, clean).Value)
			CopyConfigInfo.Add activeEventId, CInt(oSheet.Cells(i, activeEventId).Value)
			CopyConfigInfo.Add rewardsStr, (oSheet.Cells(i, rewardsStr).Value)
			CopyConfigInfoVec.Add CopyConfigInfo 
		End If
    Next
End Sub

Sub WriteLuaFile(Path, CopyConfigInfoVec)
	dim adodbStream
	set adodbStream = CreateObject("ADODB.Stream")
	adodbStream.Type=2
	adodbStream.Charset = "UTF-8"
	adodbStream.Open
	adodbStream.WriteText "--初始化", 1
	adodbStream.WriteText "function Init(script)", 1
	adodbStream.WriteText "", 1

	adodbStream.WriteText "	--副本配置", 1
	adodbStream.WriteText "	local COPY_CONFIG_MAP =", 1
	adodbStream.WriteText "	{", 1
	For Each CopyConfigInfo In CopyConfigInfoVec
		adodbStream.WriteText "		{" & "[""id""]= " & CopyConfigInfo.Item(id) & ", [""denyId""]= " & CopyConfigInfo.Item(denyCopyId) & ", ", 0
		adodbStream.WriteText "[""show""]= " & CopyConfigInfo.Item(showPassWin)  & ", [""taskId""]= " & CopyConfigInfo.Item(taskId) & ",", 0
		adodbStream.WriteText "[""totalTime""]= " & CopyConfigInfo.Item(totalTime) & ", [""drop2""]= " & CopyConfigInfo.Item(drop2) & ",", 0
		adodbStream.WriteText "[""activeEventId""]= " & CopyConfigInfo.Item(activeEventId) & ",", 0
		adodbStream.WriteText "[""rewardsStr""]= """ & CopyConfigInfo.Item(rewardsStr) & """" & ",", 0
		adodbStream.WriteText "[""boxDrop""]= """ & CopyConfigInfo.Item(boxDrop)  & """" & ", [""clean""]= " & CopyConfigInfo.Item(clean) & "},", 1
	Next
	adodbStream.WriteText	"	};", 1
	adodbStream.WriteText	"", 1
	adodbStream.WriteText	"	for i = 1, table.getn(COPY_CONFIG_MAP) do", 1
	adodbStream.WriteText	"		if COPY_CONFIG_MAP[i][""denyId""] > 0 then", 1
	adodbStream.WriteText	"			script:AddCopyDeny(COPY_CONFIG_MAP[i][""id""], COPY_CONFIG_MAP[i][""denyId""]);", 1
	adodbStream.WriteText	"		end", 1
	adodbStream.WriteText	"		if COPY_CONFIG_MAP[i][""show""] > 0 then", 1
	adodbStream.WriteText	"			script:AddShowResultCopy(COPY_CONFIG_MAP[i][""id""], COPY_CONFIG_MAP[i][""show""]);", 1
	adodbStream.WriteText	"		end", 1
	adodbStream.WriteText	"		script:AddCopyParam(COPY_CONFIG_MAP[i][""id""], COPY_CONFIG_MAP[i][""totalTime""], COPY_CONFIG_MAP[i][""drop2""], COPY_CONFIG_MAP[i][""boxDrop""], COPY_CONFIG_MAP[i][""clean""]);", 1
	adodbStream.WriteText	"		script:AddCopyParam2(COPY_CONFIG_MAP[i][""id""], COPY_CONFIG_MAP[i][""taskId""], COPY_CONFIG_MAP[i][""activeEventId""], COPY_CONFIG_MAP[i][""rewardsStr""]);", 1
	
	adodbStream.WriteText	"	end", 1
	adodbStream.WriteText	"", 1

	adodbStream.WriteText "end", 1
	SaveFile Path & "\" & "CopyConfig.lua", adodbStream
	adodbStream.Close()
	set adodbStream = Nothing
End Sub

Sub SaveFile(Path, txtStream)
	dim f
	set f = CreateObject("ADODB.Stream")
	f.Type=1
	f.Open
	txtStream.position = 3
	txtStream.CopyTo f,txtStream.size-3
	f.SaveToFile Path, 2
	f.Close()
	set f = Nothing
End Sub