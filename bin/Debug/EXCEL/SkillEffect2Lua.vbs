'如果提示没有权限 在开始-运行中敲入regedit, 然后找到HKEY_CLASSES_ROOT\Scripting.FileSystemObject  右击 点击菜单中的权限 设置好权限
Dim dwID, strName, wCond, wCondValue, wRate, byTargetType, byTargetValue, wTrigger, strFactor, byType, vPercent, vNumber, byExType, exValue
Dim gPath 
Set EffectInfoVec = CreateObject("WIA.Vector")
Out_1()

Sub Out_1()
	gPath = CreateObject("Scripting.FileSystemObject").GetFolder(wscript.arguments(0)).Path

	Dim oSheet,oWb,oExcel
	Set	oExcel = CreateObject("Excel.Application")
	Set oWb = oExcel.Workbooks.Open(gPath & "/SkillEffect.xls")
	Set oSheet = oWb.Sheets("SkillEffect")
    
	ColumnMax = oSheet.UsedRange.Columns.Count
	For i = 1 To ColumnMax
		If oSheet.Cells(1, i).Value = "dwID" Then
			dwID = i
		ElseIf oSheet.Cells(1, i).Value = "strName" Then
			strName = i
		ElseIf oSheet.Cells(1, i).Value = "wCond" Then
			wCond = i
		ElseIf oSheet.Cells(1, i).Value = "wCondValue" Then
			wCondValue = i
		ElseIf oSheet.Cells(1, i).Value = "wRate" Then
			wRate = i
		ElseIf oSheet.Cells(1, i).Value = "byTargetType" Then
			byTargetType = i
		ElseIf oSheet.Cells(1, i).Value = "byTargetValue" Then
			byTargetValue = i
		ElseIf oSheet.Cells(1, i).Value = "wTrigger" Then
			wTrigger = i
		ElseIf oSheet.Cells(1, i).Value = "strFactor" Then
			strFactor = i
		ElseIf oSheet.Cells(1, i).Value = "byType" Then
			byType = i
		ElseIf oSheet.Cells(1, i).Value = "vPercent" Then
			vPercent = i
		ElseIf oSheet.Cells(1, i).Value = "vNumber" Then
			vNumber = i
		ElseIf oSheet.Cells(1, i).Value = "byExType" Then
			byExType = i
		ElseIf oSheet.Cells(1, i).Value = "exValue" Then
			exValue = i
		End If
    Next
    Dim pathLen, pathCehua
	pathLen  = Len(gPath)- 5
	pathCehua = Left(gPath, pathLen)
    gPath = pathCehua & "Config/Scripts/Battle" 
	Call GetExcelValue(EffectInfoVec, oSheet)
	Call WriteLuaFile(gPath, EffectInfoVec)
	oExcel.Workbooks.Close
End Sub

Sub GetExcelValue(EffectInfoVec, oSheet)
	Min = 5
    Max = oSheet.UsedRange.Rows.Count
	 For i = Min To Max
		If oSheet.Cells(i, dwID).Value <> "" Then
			Set EffectInfo = CreateObject("Scripting.Dictionary")
			EffectInfo.Add dwID, CLng(oSheet.Cells(i, dwID).Value)
			EffectInfo.Add strName, CStr(oSheet.Cells(i, strName).Value)
			EffectInfo.Add wCond, CInt(oSheet.Cells(i, wCond).Value)
			EffectInfo.Add wCondValue, CInt(oSheet.Cells(i, wCondValue).Value)
			EffectInfo.Add wRate, CInt(oSheet.Cells(i, wRate).Value)
			EffectInfo.Add byTargetType, CInt(oSheet.Cells(i, byTargetType).Value)
			EffectInfo.Add byTargetValue, CInt(oSheet.Cells(i, byTargetValue).Value)
			EffectInfo.Add wTrigger, CInt(oSheet.Cells(i, wTrigger).Value)
			EffectInfo.Add strFactor, CStr(oSheet.Cells(i, strFactor).Value)
			EffectInfo.Add byType, CInt(oSheet.Cells(i, byType).Value)
			EffectInfo.Add vPercent, CStr(oSheet.Cells(i, vPercent).Value)
			EffectInfo.Add vNumber, CStr(oSheet.Cells(i, vNumber).Value)
			EffectInfo.Add byExType, CInt(oSheet.Cells(i, byExType).Value)
			EffectInfo.Add exValue, CStr(oSheet.Cells(i, exValue).Value)
			EffectInfoVec.Add EffectInfo 
		End If
    Next
End Sub

Sub WriteLuaFile(Path, EffectInfoVec)
	dim adodbStream
	set adodbStream = CreateObject("ADODB.Stream")
	adodbStream.Type=2
	adodbStream.Charset = "UTF-8"
	adodbStream.Open
	adodbStream.WriteText "require ""TargetTable""", 1
	adodbStream.WriteText "require ""Effect""", 1
	adodbStream.WriteText "require ""CondTable""", 1
	adodbStream.WriteText "", 1

	adodbStream.WriteText "EffectTable= {", 1
	For Each EffectInfo In EffectInfoVec
		adodbStream.WriteText "    [" & EffectInfo.Item(dwID) & "]= {", 0
		adodbStream.WriteText " name = """ & EffectInfo.Item(strName)  & """,", 0
		adodbStream.WriteText " GetAtkList = TargetType[" & EffectInfo.Item(byTargetType) & "],", 0
		adodbStream.WriteText " byTargetType = " & EffectInfo.Item(byTargetType) & ",", 0
		adodbStream.WriteText " byTargetValue = " & EffectInfo.Item(byTargetValue) & ",", 0
		adodbStream.WriteText " Do = Effect[" & EffectInfo.Item(byType) & "],", 0
		adodbStream.WriteText " wTrigger = " & EffectInfo.Item(wTrigger) & ",", 0
		adodbStream.WriteText " Cond = CondTable[" & EffectInfo.Item(wCond) & "],", 0
		adodbStream.WriteText " wCond = " & EffectInfo.Item(wCond) & ",", 0
		adodbStream.WriteText " condValue = " & EffectInfo.Item(wCondValue) & ",", 0
		adodbStream.WriteText " rate = " & EffectInfo.Item(wRate) & ",", 0
		adodbStream.WriteText " factor = {" & EffectInfo.Item(strFactor) & "},", 0
		adodbStream.WriteText " efP = {" & EffectInfo.Item(vPercent) & "},", 0
		adodbStream.WriteText " efV = {" & EffectInfo.Item(vNumber) & "},", 0
		adodbStream.WriteText " extType = " & EffectInfo.Item(byExType) & ",", 0
		adodbStream.WriteText " extValue = {" & EffectInfo.Item(exValue) & "},", 0
		adodbStream.WriteText " },", 1
	Next
	adodbStream.WriteText	"};", 1
	SaveFile Path & "/EffectTable.lua", adodbStream
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
