'如果提示没有权限 在开始-运行中敲入regedit, 然后找到HKEY_CLASSES_ROOT\Scripting.FileSystemObject  右击 点击菜单中的权限 设置好权限
Dim dwSkillID, strName, byType, priority1, priority2, byInitCD, byCD, iAnger, wAnger, strEffect
Dim gPath 
Set SkillInfoVec = CreateObject("WIA.Vector")
Out_1()

Sub Out_1()
	gPath = CreateObject("Scripting.FileSystemObject").GetFolder(wscript.arguments(0)).Path

	Dim oSheet,oWb,oExcel
	Set	oExcel = CreateObject("Excel.Application")
	Set oWb = oExcel.Workbooks.Open(gPath & "/Skill.xlsx")
	Set oSheet = oWb.Sheets("Skill")
    
	ColumnMax = oSheet.UsedRange.Columns.Count
	For i = 1 To ColumnMax
		If oSheet.Cells(1, i).Value = "dwSkillID" Then
			dwSkillID = i
		ElseIf oSheet.Cells(1, i).Value = "strName" Then
			strName = i
		ElseIf oSheet.Cells(1, i).Value = "byType" Then
			byType = i
		ElseIf oSheet.Cells(1, i).Value = "priority1" Then
			priority1 = i
		ElseIf oSheet.Cells(1, i).Value = "priority2" Then
			priority2 = i
		ElseIf oSheet.Cells(1, i).Value = "byInitCD" Then
			byInitCD = i
		ElseIf oSheet.Cells(1, i).Value = "byCD" Then
			byCD = i
		ElseIf oSheet.Cells(1, i).Value = "iAnger" Then
			iAnger = i
		ElseIf oSheet.Cells(1, i).Value = "wAnger" Then
			wAnger = i
		ElseIf oSheet.Cells(1, i).Value = "strEffect" Then
			strEffect = i
		End If
    Next
    Dim pathLen, pathCehua
	pathLen  = Len(gPath)- 5
	pathCehua = Left(gPath, pathLen)
    gPath = pathCehua & "Config/Scripts/Battle" 
	Call GetExcelValue(SkillInfoVec, oSheet)
	Call WriteLuaFile(gPath, SkillInfoVec)
	oExcel.Workbooks.Close
End Sub

Sub GetExcelValue(SkillInfoVec, oSheet)
	Min = 5
    Max = oSheet.UsedRange.Rows.Count
	 For i = Min To Max
		If oSheet.Cells(i, dwSkillID).Value <> "" Then
			Set SkillInfo = CreateObject("Scripting.Dictionary")
			SkillInfo.Add dwSkillID, CInt(oSheet.Cells(i, dwSkillID).Value)
			SkillInfo.Add strName, CStr(oSheet.Cells(i, strName).Value)
			SkillInfo.Add byType, CInt(oSheet.Cells(i, byType).Value)
			SkillInfo.Add priority1, CInt(oSheet.Cells(i, priority1).Value)
			SkillInfo.Add priority2, CInt(oSheet.Cells(i, priority2).Value)
			SkillInfo.Add byInitCD, CInt(oSheet.Cells(i, byInitCD).Value)
			SkillInfo.Add byCD, CInt(oSheet.Cells(i, byCD).Value)
			SkillInfo.Add iAnger, CInt(oSheet.Cells(i, iAnger).Value)
			SkillInfo.Add wAnger, CInt(oSheet.Cells(i, wAnger).Value)
			SkillInfo.Add strEffect, CStr(oSheet.Cells(i, strEffect).Value)
			SkillInfoVec.Add SkillInfo 
		End If
    Next
End Sub

Sub WriteLuaFile(Path, SkillInfoVec)
	dim adodbStream
	set adodbStream = CreateObject("ADODB.Stream")
	adodbStream.Type=2
	adodbStream.Charset = "UTF-8"
	adodbStream.Open
	adodbStream.WriteText "require ""EffectTable""", 1
	adodbStream.WriteText "", 1

	adodbStream.WriteText "SkillTable= {", 1
	For Each SkillInfo In SkillInfoVec
		adodbStream.WriteText "    [" & SkillInfo.Item(dwSkillID) & "]= {", 0
		adodbStream.WriteText " name = """ & SkillInfo.Item(strName)  & """,", 0
		adodbStream.WriteText " type_ = " & SkillInfo.Item(byType)  & ",", 0
		adodbStream.WriteText " priority1 = " & SkillInfo.Item(priority1)  & ",", 0
		adodbStream.WriteText " priority2 = " & SkillInfo.Item(priority2)  & ",", 0
		adodbStream.WriteText " initcd = " & SkillInfo.Item(byInitCD) & ",", 0
		adodbStream.WriteText " cd = " & SkillInfo.Item(byCD) & ",", 0
		adodbStream.WriteText " genRages = " & SkillInfo.Item(iAnger) & ",", 0
		adodbStream.WriteText " needRages = " & SkillInfo.Item(wAnger) & ",", 0
		adodbStream.WriteText " effect = {" & SkillInfo.Item(strEffect) & "},", 0
		adodbStream.WriteText " },", 1
	Next
	adodbStream.WriteText	"};", 1
	SaveFile Path & "/SkillTable.lua", adodbStream
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
