'如果提示没有权限 在开始-运行中敲入regedit, 然后找到HKEY_CLASSES_ROOT\Scripting.FileSystemObject  右击 点击菜单中的权限 设置好权限
Dim luaType, id, param1, param2, param3, abandomTimeLimit
Dim gPath
Out_1()

Sub Out_1()
	gPath = CreateObject("Scripting.FileSystemObject").GetFolder(wscript.arguments(0)).Path

	Dim oSheet,oWb,oExcel
	Set	oExcel = CreateObject("Excel.Application")
	Set oWb = oExcel.Workbooks.Open(gPath & "\Task.xlsx")
	Set oSheet = oWb.Sheets("Task")
    Min = 5
    Max = oSheet.UsedRange.Rows.Count
	ColumnMax = oSheet.UsedRange.Columns.Count
	For i = 1 To ColumnMax
		If oSheet.Cells(1, i).Value = "luaType" Then
			luaType = i
		ElseIf oSheet.Cells(1, i).Value = "id" Then
			id = i
		ElseIf oSheet.Cells(1, i).Value = "parameter1" Then
			param1 = i
		ElseIf oSheet.Cells(1, i).Value = "parameter2" Then
			param2 = i
		ElseIf oSheet.Cells(1, i).Value = "parameter3" Then
			param3 = i
		ElseIf oSheet.Cells(1, i).Value = "abandomTimeLimit" Then
			abandomTimeLimit = i
		End If
    Next

    Dim pathLen, pathCehua, luaTypeValue, luaExtendType
	pathLen  = Len(gPath)- 5
	pathCehua = Left(gPath, pathLen)
    gPath = pathCehua & "Config/Scripts/Task"
    For i = Min To Max
		If oSheet.Cells(i, luaType).Value > 0 And oSheet.Cells(i, id).Value <> ""  Then
			luaTypeValue = oSheet.Cells(i, luaType).Value
			luaExtendType = 1
			
			'对话任务
			If luaTypeValue = "1" Then
				Call WriteLuaFile_1(oSheet,oSheet.Cells(i, id).Value, i, gPath, luaExtendType)
			'任务绑定
			Else
				Call WriteLuaFile_Bind(oSheet,oSheet.Cells(i, id).Value, i, gPath, luaExtendType)
			End If
		End If
    Next
	oExcel.Workbooks.Close
    MsgBox "OK"
End Sub


Sub WriteLuaFile_1(Sheet, FileName, Index, Path, luaExtendType)
	dim f
	set f = CreateObject("ADODB.Stream")
	f.Type=2
	f.Charset = "UTF-8"
	f.Open

    f.WriteText "require(""Task_Base"")", 1
	f.WriteText "local TaskId = nil", 1
    f.WriteText "", 1
	f.WriteText "function Init(task, taskId)", 1
	f.WriteText "   TaskId = taskId", 1
	f.WriteText "end", 1
	f.WriteText "", 1
    f.WriteText "function OnAccepted(player)  ---    接受任务时需要执行的操作", 1
    f.WriteText "   local task = player:FindTask(TaskId);", 1
    f.WriteText "   task:SetStatus(2);", 1
    f.WriteText "end", 1
    f.WriteText "", 1

	Call WriteCommon(Sheet, f, index, luaExtendType)

    SaveFile Path & "\" & "task_" & FileName & ".lua", f
	f.Close()
	set f = Nothing
End Sub


Sub WriteLuaFile_Bind(Sheet, FileName, Index, Path, luaExtendType)
  
	 dim f
	set f = CreateObject("ADODB.Stream")
	f.Type=2
	f.Charset = "UTF-8"
	f.Open

    Dim sad(50)
	Dim count
	count = 0
    sad(count) = "function Init(task, taskId)"
	count = count + 1
    sad(count) = "TaskId = taskId"
	count = count + 1
    sad(count) = "task:BindTaskEvent(" & Sheet.Cells(Index, luaType).Value & "," & Sheet.Cells(Index, param1).Value & "," & Sheet.Cells(Index, param2).Value & "," & Sheet.Cells(Index, param3).Value & ")"
	count = count + 1
	sad(count) = "end"
	count = count + 1
	sad(count) = ""
	count = count + 1

    
    f.WriteText "require(""Task_Base"")", 1
	f.WriteText "", 1
	f.WriteText "local TaskId = nil", 1
	f.WriteText "", 1

    For i = LBound(sad) To count - 1
        f.WriteText sad(i), 1
    Next

	Call WriteCommon(Sheet, f, index, luaExtendType)

    SaveFile Path & "\" & "task_" & FileName & ".lua", f
	f.Close()
	set f = Nothing
End Sub

Sub WriteCommon(Sheet, f, index, luaExtendType)
	Call WriteOnTimeOut(Sheet, f, Index)
	Select case luaExtendType Mod 10
		Case 1
			Call WriteAutoAccept(Sheet, f, index)
	End Select

End Sub

Sub WriteOnTimeOut(Sheet, f, index)
	If Sheet.Cells(index, abandomTimeLimit).Value > 0 Then
		f.WriteText "function OnTimeout(player)", 1
		f.WriteText "   player:AbandonTask(TaskId);", 1
		f.WriteText "end", 1
		f.WriteText "", 1
	End If
End Sub

Sub WriteAutoAccept(Sheet, f, index)
	f.WriteText "function AutoAccept(player)  ---	自动接任务", 1
	f.WriteText "   player:AcceptTask(TaskId);", 1
	f.WriteText "end", 1
	f.WriteText "", 1
End Sub

Sub SaveFile(Path, txtStream)
	dim f
	set f = CreateObject("ADODB.Stream")
	f.Type=1
	f.Open
	txtStream.position = 3  'utf-8文件头偏移3个字节
	txtStream.CopyTo f,txtStream.size-3
	f.SaveToFile Path, 2
	f.Close()
	set f = Nothing
End Sub
