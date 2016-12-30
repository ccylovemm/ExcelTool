'如果提示没有权限 在开始-运行中敲入regedit, 然后找到HKEY_CLASSES_ROOT\Scripting.FileSystemObject  右击 点击菜单中的权限 设置好权限
Dim dwBuffID, strName, byType, byAddModel, dwLastTime, byCD, byImmedEffect, byRepeat, byTrigger, strValue, strEndingEffect, strDisplayID
Dim gPath 
Set BuffInfoVec = CreateObject("WIA.Vector")
Out_1()

Sub Out_1()
	gPath = CreateObject("Scripting.FileSystemObject").GetFolder(wscript.arguments(0)).Path

	Dim oSheet,oWb,oExcel
	Set	oExcel = CreateObject("Excel.Application")
	Set oWb = oExcel.Workbooks.Open(gPath & "/SkillBuff.xls")
	Set oSheet = oWb.Sheets("SkillBuff")
    
	ColumnMax = oSheet.UsedRange.Columns.Count
	For i = 1 To ColumnMax
		If oSheet.Cells(1, i).Value = "dwBuffID" Then
			dwBuffID = i
		ElseIf oSheet.Cells(1, i).Value = "strName" Then
			strName = i
		ElseIf oSheet.Cells(1, i).Value = "byType" Then
			byType = i
		ElseIf oSheet.Cells(1, i).Value = "byAddModel" Then
			byAddModel = i
		ElseIf oSheet.Cells(1, i).Value = "dwLastTime" Then
			dwLastTime = i
		ElseIf oSheet.Cells(1, i).Value = "byCD" Then
			byCD = i
		ElseIf oSheet.Cells(1, i).Value = "byImmedEffect" Then
			byImmedEffect = i
		ElseIf oSheet.Cells(1, i).Value = "byRepeat" Then
			byRepeat = i
		ElseIf oSheet.Cells(1, i).Value = "byTrigger" Then
			byTrigger = i
		ElseIf oSheet.Cells(1, i).Value = "strValue" Then
			strValue = i
		ElseIf oSheet.Cells(1, i).Value = "strEndingEffect" Then
			strEndingEffect = i
		ElseIf oSheet.Cells(1, i).Value = "strDisplayID" Then
			strDisplayID = i
		End If
    Next
    Dim pathLen, pathCehua
	pathLen  = Len(gPath)- 5
	pathCehua = Left(gPath, pathLen)
    gPath = pathCehua & "Config/Scripts/Battle" 
	Call GetExcelValue(BuffInfoVec, oSheet)
	Call WriteLuaFile(gPath, BuffInfoVec)
	oExcel.Workbooks.Close
End Sub

Sub GetExcelValue(BuffInfoVec, oSheet)
	Min = 5
    Max = oSheet.UsedRange.Rows.Count
	 For i = Min To Max
		If oSheet.Cells(i, dwBuffID).Value <> "" Then
			Set BuffInfo = CreateObject("Scripting.Dictionary")
			BuffInfo.Add dwBuffID, CLng(oSheet.Cells(i, dwBuffID).Value)
			BuffInfo.Add strName, CStr(oSheet.Cells(i, strName).Value)
			BuffInfo.Add byType, CInt(oSheet.Cells(i, byType).Value)
			BuffInfo.Add byAddModel, CInt(oSheet.Cells(i, byAddModel).Value)
			BuffInfo.Add dwLastTime, CInt(oSheet.Cells(i, dwLastTime).Value)
			BuffInfo.Add byCD, CInt(oSheet.Cells(i, byCD).Value)
			BuffInfo.Add byImmedEffect, CInt(oSheet.Cells(i, byImmedEffect).Value)
			BuffInfo.Add byRepeat, CInt(oSheet.Cells(i, byRepeat).Value)
			BuffInfo.Add byTrigger, CInt(oSheet.Cells(i, byTrigger).Value)
			BuffInfo.Add strValue, CStr(oSheet.Cells(i, strValue).Value)
			BuffInfo.Add strEndingEffect, CStr(oSheet.Cells(i, strEndingEffect).Value)
			BuffInfo.Add strDisplayID, CStr(oSheet.Cells(i, strDisplayID).Value)
			BuffInfoVec.Add BuffInfo 
		End If
    Next
End Sub

Sub WriteLuaFile(Path, BuffInfoVec)
	dim adodbStream
	set adodbStream = CreateObject("ADODB.Stream")
	adodbStream.Type=2
	adodbStream.Charset = "UTF-8"
	adodbStream.Open

	adodbStream.WriteText "BuffTable= {", 1
	For Each BuffInfo In BuffInfoVec
		adodbStream.WriteText "    [" & BuffInfo.Item(dwBuffID) & "]= {", 0
		adodbStream.WriteText " name = """ & BuffInfo.Item(strName)  & """,", 0
		adodbStream.WriteText " type_ = " & BuffInfo.Item(byType)  & ",", 0
		adodbStream.WriteText " addModel = " & BuffInfo.Item(byAddModel)  & ",", 0
		adodbStream.WriteText " last = " & BuffInfo.Item(dwLastTime)  & ",", 0
		adodbStream.WriteText " cd = " & BuffInfo.Item(byCD)  & ",", 0
		adodbStream.WriteText " imm = " & BuffInfo.Item(byImmedEffect) & ",", 0
		adodbStream.WriteText " byRepeat = " & BuffInfo.Item(byRepeat) & ",", 0
		adodbStream.WriteText " byTrigger = " & BuffInfo.Item(byTrigger) & ",", 0
		adodbStream.WriteText " values = {" & BuffInfo.Item(strValue) & "},", 0
		adodbStream.WriteText " endEfs = {" & BuffInfo.Item(strEndingEffect) & "},", 0
		adodbStream.WriteText " displayIDs = {" & BuffInfo.Item(strDisplayID) & "},", 0
		adodbStream.WriteText " },", 1
	Next
	adodbStream.WriteText	"};", 1
	SaveFile Path & "/BuffTable.lua", adodbStream
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
