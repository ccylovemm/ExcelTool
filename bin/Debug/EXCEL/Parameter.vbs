'如果提示没有权限 在开始-运行中敲入regedit, 然后找到HKEY_CLASSES_ROOT\Scripting.FileSystemObject  右击 点击菜单中的权限 设置好权限
Dim dwID, strName, dwValue
Dim gPath 
Set ParamInfoVec = CreateObject("WIA.Vector")
Out_1()

Sub Out_1()
	gPath = CreateObject("Scripting.FileSystemObject").GetFolder(wscript.arguments(0)).Path

	Dim oSheet,oWb,oExcel
	Set	oExcel = CreateObject("Excel.Application")
	Set oWb = oExcel.Workbooks.Open(gPath & "/Parameter.xlsx")
	Set oSheet = oWb.Sheets("Parameter")
    
	ColumnMax = oSheet.UsedRange.Columns.Count
	For i = 1 To ColumnMax
		If oSheet.Cells(1, i).Value = "ID" Then
			dwID = i
		ElseIf oSheet.Cells(1, i).Value = "Name" Then
			strName = i
		ElseIf oSheet.Cells(1, i).Value = "value" Then
			dwValue = i
		End If
    Next
    Dim pathLen, pathCehua
	pathLen  = Len(gPath)- 5
	pathCehua = Left(gPath, pathLen)
    gPath = pathCehua & "Config/Scripts/Battle" 
	Call GetExcelValue(ParamInfoVec, oSheet)
	Call WriteLuaFile(gPath, ParamInfoVec)
	oExcel.Workbooks.Close
End Sub

Sub GetExcelValue(ParamInfoVec, oSheet)
	Min = 5
    Max = oSheet.UsedRange.Rows.Count
	 For i = Min To Max
        Dim id
        id = CLng(oSheet.Cells(i, dwID).Value)
		If id >= 1700 and id < 1800 Then
			Set ParamInfo = CreateObject("Scripting.Dictionary")
			ParamInfo.Add dwID, id
			ParamInfo.Add strName, CStr(oSheet.Cells(i, strName).Value)
			ParamInfo.Add dwValue, CInt(oSheet.Cells(i, dwValue).Value)
			ParamInfoVec.Add ParamInfo 
		End If
    Next
End Sub

Sub WriteLuaFile(Path, ParamInfoVec)
	dim adodbStream
	set adodbStream = CreateObject("ADODB.Stream")
	adodbStream.Type=2
	adodbStream.Charset = "UTF-8"
	adodbStream.Open

	adodbStream.WriteText "ParamTable= {", 1
	For Each ParamInfo In ParamInfoVec
		adodbStream.WriteText "    [" & ParamInfo.Item(dwID) & "]= {", 0
		adodbStream.WriteText " name = """ & ParamInfo.Item(strName)  & """,", 0
		adodbStream.WriteText " value = " & ParamInfo.Item(dwValue) & ",", 0
		adodbStream.WriteText " },", 1
	Next
	adodbStream.WriteText	"};", 1
	SaveFile Path & "/ParamTable.lua", adodbStream
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
