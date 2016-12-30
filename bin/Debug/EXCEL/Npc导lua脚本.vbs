'如果提示没有权限 在开始-运行中敲入regedit, 然后找到HKEY_CLASSES_ROOT\Scripting.FileSystemObject  右击 点击菜单中的权限 设置好权限
Dim luaType, id, normalTalk
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
		If oSheet.Cells(1, i).Value = "luaType" Then
			luaType = i
		ElseIf oSheet.Cells(1, i).Value = "id" Then
			id = i
		ElseIf oSheet.Cells(1, i).Value = "normalTalk" Then
			normalTalk = i
		End If
    Next
    Dim pathLen, pathCehua
	pathLen  = Len(gPath)- 5
	pathCehua = Left(gPath, pathLen)
    gPath = pathCehua & "Config/Scripts/Npc"
    For i = Min To Max
        '普通功能npc
        If oSheet.Cells(i, luaType).Value = "1" Then
            Call WriteLuaFile_1(oSheet,oSheet.Cells(i, id).Value, i, gPath)
        End If
    Next
	oExcel.Workbooks.Close
End Sub


Sub WriteLuaFile_1(oSheet, FileName, Index, Path)
	dim adodbStream
	set adodbStream = CreateObject("ADODB.Stream")
	adodbStream.Type=2
	adodbStream.Charset = "UTF-8"
	adodbStream.Open
	adodbStream.WriteText "require(""Npc_Base"")", 1
	adodbStream.WriteText	"", 1
	If normalTalk > 0 And oSheet.Cells(Index, normalTalk).Value <> ""  Then
		adodbStream.WriteText	"function OnNormalTalk(dialog, player)", 1
		adodbStream.WriteText	"    dialog:AddWord(""" & oSheet.Cells(Index, normalTalk).Value & """);", 1
		adodbStream.WriteText	"end", 1
    End If

	SaveFile Path & "\" & "npc_" & FileName & ".lua", adodbStream
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