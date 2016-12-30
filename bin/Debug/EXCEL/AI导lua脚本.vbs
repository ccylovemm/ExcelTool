'如果提示没有权限 在开始-运行中敲入regedit, 然后找到HKEY_CLASSES_ROOT\Scripting.FileSystemObject  右击 点击菜单中的权限 设置好权限
Dim aiType,id
Dim gPath 
Out_1()

Sub Out_1()
	gPath = CreateObject("Scripting.FileSystemObject").GetFolder(wscript.arguments(0)).Path

	Dim oSheet,oWb,oExcel
	Set	oExcel = CreateObject("Excel.Application")
	Set oWb = oExcel.Workbooks.Open(gPath & "\Actor.xlsx")
	Set oSheet = oWb.Sheets("Actor")
    Min = 5
    Max = oSheet.UsedRange.Rows.Count
	ColumnMax = oSheet.UsedRange.Columns.Count
	For i = 1 To ColumnMax
		If oSheet.Cells(1, i).Value = "aiID" Then
			aiType = i
		ElseIf oSheet.Cells(1, i).Value = "id" Then
			id = i
		End If
    Next
    Dim pathLen, pathCehua
	pathLen  = Len(gPath)- 5
	pathCehua = Left(gPath, pathLen)
    gPath = pathCehua & "Config/Scripts/AI"
	Call WriteAIBind(oSheet, gPath, Min, Max)
	oExcel.Workbooks.Close
End Sub


Sub WriteAIBind(oSheet,Path, Min, Max)
	dim adodbStream
	set adodbStream = CreateObject("ADODB.Stream")
	adodbStream.Type=2
	adodbStream.Charset = "UTF-8"
	adodbStream.Open

	adodbStream.WriteText "--初始化", 1
	adodbStream.WriteText "", 1
	adodbStream.WriteText	"function Init(scriptMgr)", 1
    For i = Min To Max
        If oSheet.Cells(i, aiType).Value > 0  And oSheet.Cells(i, id).Value > 0 Then
			adodbStream.WriteText	"scriptMgr:BindAI(" & oSheet.Cells(i, id).Value & ", " & oSheet.Cells(i, aiType).Value & ");", 1
        End If	
    Next

	adodbStream.WriteText	"end", 1
	
	SaveFile Path & "\" & "AI_Bind_Auto.lua", adodbStream
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