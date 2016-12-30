'�����ʾû��Ȩ�� �ڿ�ʼ-����������regedit, Ȼ���ҵ�HKEY_CLASSES_ROOT\Scripting.FileSystemObject  �һ� ����˵��е�Ȩ�� ���ú�Ȩ��
Dim luaType, id,itemid,num,price,discountprice,moneytype
Dim totalnum,limitnum,bBind,bLimit,hide,festival
luaType = 0
Dim gPath 
Out_1()

Sub Out_1()
	gPath = CreateObject("Scripting.FileSystemObject").GetFolder(wscript.arguments(0)).Path

	Dim oSheet,oWb,oExcel
	Set	oExcel = CreateObject("Excel.Application")
	Set oWb = oExcel.Workbooks.Open(gPath & "\MallItem.xlsx")
	Set oSheet = oWb.Sheets("MallItem")
	
	ColumnMax = oSheet.UsedRange.Columns.Count

	For i = 1 To ColumnMax
		If oSheet.Cells(1, i).Value = "luaType" Then
			luaType = i
		ElseIf oSheet.Cells(1, i).Value = "id" Then
			id = i
		ElseIf oSheet.Cells(1, i).Value = "itemid" Then
			itemid = i
		ElseIf oSheet.Cells(1, i).Value = "num" Then
			num = i
		ElseIf oSheet.Cells(1, i).Value = "price" Then
			price = i
		ElseIf oSheet.Cells(1, i).Value = "discountprice" Then
			discountprice = i
		ElseIf oSheet.Cells(1, i).Value = "moneytype" Then
			moneytype = i
		ElseIf oSheet.Cells(1, i).Value = "totalnum" Then
			totalnum = i
		ElseIf oSheet.Cells(1, i).Value = "limitnum" Then
			limitnum = i
		ElseIf oSheet.Cells(1, i).Value = "bBind" Then
			bBind = i
		ElseIf oSheet.Cells(1, i).Value = "bLimit" Then
			bLimit = i
		ElseIf oSheet.Cells(1, i).Value = "hide" Then
			hide = i
		ElseIf oSheet.Cells(1, i).Value = "festival" Then
			festival = i
		End If
    Next
	If luaType > 0 Then
		Dim pathLen, pathCehua
		pathLen  = Len(gPath)- 5
		pathCehua = Left(gPath, pathLen)
		gPath = pathCehua & "Config/Scripts"
		Call WriteLuaFile_1(oSheet, gPath)
	End If
	oExcel.Workbooks.Close
End Sub


Sub WriteLuaFile_1(Sheet, path)
	Min = 5
    Max = Sheet.UsedRange.Rows.Count
	Set ItemInfo = CreateObject("Scripting.Dictionary")
	Set GS_ITEM = CreateObject("WIA.Vector")
	Set NORMAL_ITEM_1 = CreateObject("WIA.Vector")
	Set NORMAL_ITEM_2 = CreateObject("WIA.Vector")
	Set NORMAL_ITEM_3 = CreateObject("WIA.Vector")
	Set NORMAL_ITEM_4 = CreateObject("WIA.Vector")
	Set FESTIVAL_ITEM = CreateObject("WIA.Vector")
	Set GOLDSTONE_MALL = CreateObject("WIA.Vector")
	Set BINDGOLDSTONE_MALL = CreateObject("WIA.Vector")
	Set SILVERSTONE_MALL = CreateObject("WIA.Vector")
	ItemInfo.Add "GS_ITEM", GS_ITEM
	ItemInfo.Add "NORMAL_ITEM_1", NORMAL_ITEM_1
	ItemInfo.Add "NORMAL_ITEM_2", NORMAL_ITEM_2
	ItemInfo.Add "NORMAL_ITEM_3", NORMAL_ITEM_3
	ItemInfo.Add "NORMAL_ITEM_4", NORMAL_ITEM_4
	ItemInfo.Add "FESTIVAL_ITEM", FESTIVAL_ITEM
	ItemInfo.Add "GOLDSTONE_MALL", GOLDSTONE_MALL
	ItemInfo.Add "BINDGOLDSTONE_MALL", BINDGOLDSTONE_MALL
	ItemInfo.Add "SILVERSTONE_MALL", SILVERSTONE_MALL
	For i = Min To Max
		If Sheet.Cells(i, luaType).Value = 1 Then
			Call GS_ITEM.Add(GetItemInfo(sheet, i))
		ElseIf Sheet.Cells(i, luaType).Value = 2 Then
			Call NORMAL_ITEM_1.Add(GetItemInfo(sheet, i))
		ElseIf Sheet.Cells(i, luaType).Value = 3 Then
			Call NORMAL_ITEM_2.Add(GetItemInfo(sheet, i))
		ElseIf Sheet.Cells(i, luaType).Value = 4 Then
			Call NORMAL_ITEM_3.Add(GetItemInfo(sheet, i))
		ElseIf Sheet.Cells(i, luaType).Value = 5 Then
			Call NORMAL_ITEM_4.Add(GetItemInfo(sheet, i))
		ElseIf Sheet.Cells(i, luaType).Value = 6 Then
			Call FESTIVAL_ITEM.Add("{""" & Sheet.Cells(i, festival).Value & """, " & GetItemInfo(sheet, i) & "}")
		ElseIf Sheet.Cells(i, luaType).Value = 7 Then
			Call GOLDSTONE_MALL.Add(GetItemInfo(sheet, i))
		ElseIf Sheet.Cells(i, luaType).Value = 8 Then
			Call BINDGOLDSTONE_MALL.Add(GetItemInfo(sheet, i))
		ElseIf Sheet.Cells(i, luaType).Value = 9 Then
			Call SILVERSTONE_MALL.Add(GetItemInfo(sheet, i))
		End If
	Next
	Call WriteLuaMall(ItemInfo, path)
End Sub

Function GetItemInfo(Sheet, i)
	Dim result
	result = """"
	result = result & Sheet.Cells(i, id).Value & ", " & Sheet.Cells(i, itemid).Value & ", " & Sheet.Cells(i, num).Value & ", " & Sheet.Cells(i, price).Value & ", "
	result = result & Sheet.Cells(i, discountprice).Value & ", " & Sheet.Cells(i, moneytype).Value & ", " & Sheet.Cells(i, totalnum).Value & ", " & Sheet.Cells(i, limitnum).Value & ","
	result = result & Sheet.Cells(i, bBind).Value & ", " & Sheet.Cells(i, bLimit).Value & ", " & Sheet.Cells(i, hide).Value & """"
	GetItemInfo = result
End Function

Sub WriteLuaMall(ItemInfo, Path)
	dim f
	set f = CreateObject("ADODB.Stream")
	f.Type=2
	f.Charset = "UTF-8"
	f.Open

	f.WriteText "--���߸�ʽ:�̳�ID(�������10000),����ID,һ������,ԭ��,�ۿۼ�,��������,��������,ÿ������,�Ƿ��,�Ƿ�����,�ͻ����Ƿ�����", 1
	f.WriteText "--��������:�� 3��Q�� 7", 1
	f.WriteText "", 1
	f.WriteText "--��������������Ϣ���̳�ID��10000��10999�����30��", 1
	f.WriteText "local GS_ITEM = {", 1
			Call WriteItem(f, ItemInfo, "GS_ITEM")
	f.WriteText "		};", 1
	f.WriteText ""	, 1
	f.WriteText "--��ͨ��������1��Ϣ���̳�ID��11000��11999�����30��", 1
	f.WriteText "local NORMAL_ITEM_1 = {", 1
			Call WriteItem(f, ItemInfo, "NORMAL_ITEM_1")
	f.WriteText "		};", 1
	f.WriteText "", 1
	f.WriteText "--��ͨ��������2��Ϣ���̳�ID��12000��12999�����30��", 1
	f.WriteText "local NORMAL_ITEM_2 = {", 1
			Call WriteItem(f, ItemInfo, "NORMAL_ITEM_2")
	f.WriteText "		};", 1
	f.WriteText "", 1
	f.WriteText "--��ͨ��������3��Ϣ���̳�ID��13000��13999�����30��", 1
	f.WriteText "local NORMAL_ITEM_3 = {", 1
			Call WriteItem(f, ItemInfo, "NORMAL_ITEM_3")
	f.WriteText "		};", 1
	f.WriteText "", 1
	f.WriteText "--��ͨ��������4��Ϣ���̳�ID��14000��14999�����30��", 1
	f.WriteText "local NORMAL_ITEM_4 = {", 1
            Call WriteItem(f, ItemInfo, "NORMAL_ITEM_4")
	f.WriteText "		};", 1
	f.WriteText "", 1
	f.WriteText "--��������������Ϣ���̳�ID��20000��29999", 1
	f.WriteText "local FESTIVAL_ITEM = {", 1
		Call WriteItem(f, ItemInfo, "FESTIVAL_ITEM")	
	f.WriteText ""	, 1				
	f.WriteText "		};", 1
	f.WriteText "--���߸�ʽ:�̳�ID,����ID,һ������,Ʒ��,ԭ��,�ۿۼ�,��������,��������,ÿ������,�Ƿ��,�Ƿ�����,�ͻ����Ƿ�����", 1
	f.WriteText "--��������:�� 3��Q�� 7 ���߶һ� 21", 1
	f.WriteText ""	, 1
	f.WriteText "--��ʯ�̳ǵ�����Ϣ���̳�ID��30000��39999", 1
	f.WriteText "local GOLDSTONE_MALL = {", 1
			Call WriteItem(f, ItemInfo, "GOLDSTONE_MALL")
	f.WriteText "", 1
	f.WriteText "		};", 1
	f.WriteText "--��שʯ�̳ǵ�����Ϣ���̳�ID��40000��49999", 1
	f.WriteText "local BINDGOLDSTONE_MALL = {", 1
			Call WriteItem(f, ItemInfo, "BINDGOLDSTONE_MALL")
	f.WriteText "", 1
	f.WriteText "		};", 1
	f.WriteText "--��ʯ�̳ǵ�����Ϣ���̳�ID��50000��59999", 1
	f.WriteText "local SILVERSTONE_MALL = {", 1
			Call WriteItem(f, ItemInfo, "SILVERSTONE_MALL")
	f.WriteText "", 1
	f.WriteText "		};", 1
	f.WriteText "", 1
	f.WriteText "--��ʼ���̳���������", 1
	f.WriteText "function Init(script)"	, 1
	f.WriteText "	--�����������������Ϣ", 1
	f.WriteText "	--script:AddNormalLimitSet(1, 3,""�����̳����ڴ��۳��� {I 0 21111 3 1},{I 0 21103 3 1},{I 0 404 4 1}ֻ��3�죬��Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "	--script:AddNormalLimitSet(2, 1,""�����̳����ڴ��۳��� {I 0 689 1 1},{I 0 21111 3 1},{I 0 404 4 1},ÿ���޹�1������Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "				--{I ������Ψһid��Ĭ��0�� ���߱�id Ʒ�� �Ƿ�� ����id(����ﵰ��ӦNPC)   ��Դ(1��ʾ������)}", 1
	f.WriteText "	--script:AddNormalLimitSet(3, 3,""�����̳����ڴ��۳��� {I 0 33 4 1},{I 0 21111 3 1},{I 0 404 4 1},ÿ���޹�1������Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "	--script:AddNormalLimitSet(4, 365,""�����̳����ڴ��۳��� {I 0 32125 3 1},{I 0 32063 3 1},{I 0 32064 3 1},ÿ���������ޣ���Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "	--script:AddNormalLimitSet(2, 1, ""�����̳����ڴ��۳��� {I 0 43216 3 1 102036},{I 0 43219 3 1 102036},{I 0 32033 4 1}ֻ��1�죬��Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "	--script:AddNormalLimitSet(3, 1, ""�����̳����ڴ��۳��� {I 0 32032 4 1},{I 0 32034 3 1},{I 0 32035 3 1}ֻ��1�죬��Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "	--script:AddNormalLimitSet(4, 1, ""�����̳����ڴ��۳��� {I 0 32032 4 1},{I 0 32036 3 1},{I 0 32037 3 1}ֻ��1�죬��Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "	--script:AddNormalLimitSet(5, 1, ""�����̳����ڴ��۳��� {I 0 32032 4 1},{I 0 32038 3 1},{I 0 32039 3 1}ֻ��1�죬��Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "	--script:AddNormalLimitSet(6, 1, ""�����̳����ڴ��۳��� {I 0 32040 2 1},{I 0 32041 3 1},{I 0 32042 4 1}ֻ��1�죬��Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "	--script:AddNormalLimitSet(7, 5, ""�����̳����ڴ��۳��� {I 0 32043 4 1},{I 0 32044 3 1},{I 0 32045 3 1}ֻ��1�죬��Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "	--script:AddNormalLimitSet(8, 5, ""�����̳����ڴ��۳��� {I 0 32046 5 1},{I 0 32047 5 1},{I 0 32048 3 1}ֻ��1�죬��Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "	--script:AddNormalLimitSet(9, 5, ""�����̳����ڴ��۳��� {I 0 32049 4 1},{I 0 32050 3 1},{I 0 32051 3 1}ֻ��1�죬��Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "	--script:AddNormalLimitSet(10, 365, ""�����̳����ڴ��۳��� {I 0 43216 3 1 102036},{I 0 43219 3 1 102036},{I 0 404 4 1}��Ҫ����ˣ�{L event:quickMall 4|����鿴}"");", 1
	f.WriteText "", 1
	f.WriteText "	--��ͨ�������ߣ����������쿪ʼ����", 1
	f.WriteText "	for i = 1, table.getn(NORMAL_ITEM_1) do", 1
	f.WriteText "		script:AddNormalLimitItem(1, NORMAL_ITEM_1[i]);", 1
	f.WriteText "	end", 1
	f.WriteText "	for i = 1, table.getn(NORMAL_ITEM_2) do", 1
	f.WriteText "		script:AddNormalLimitItem(2, NORMAL_ITEM_2[i]);", 1
	f.WriteText "	end", 1
	f.WriteText "	for i = 1, table.getn(NORMAL_ITEM_3) do", 1
	f.WriteText "		script:AddNormalLimitItem(3, NORMAL_ITEM_3[i]);", 1
	f.WriteText "	end", 1
	f.WriteText "	for i = 1, table.getn(NORMAL_ITEM_4) do", 1
	f.WriteText "		script:AddNormalLimitItem(4, NORMAL_ITEM_4[i]);", 1
	f.WriteText "	end", 1
	f.WriteText "", 1
	f.WriteText "	--�����������ߣ�����ǰ5�����", 1
	f.WriteText "	for i = 1, table.getn(GS_ITEM) do", 1
	f.WriteText "		script:AddGSLimitItem(GS_ITEM[i]);", 1
	f.WriteText "	end", 1
	f.WriteText "", 1
	f.WriteText "	--��ӽ�����������", 1
	f.WriteText "	for i = 1, table.getn(FESTIVAL_ITEM) do", 1
	f.WriteText "		script:AddFestivalLimitItem(FESTIVAL_ITEM[i][1], FESTIVAL_ITEM[i][2]);", 1
	f.WriteText "	end", 1
	f.WriteText ""
	f.WriteText "	--��ӽ�ʯ�̳ǵ���", 1
	f.WriteText "	for i = 1, table.getn(GOLDSTONE_MALL) do", 1
	f.WriteText "		script:AddGoldStoneItem(GOLDSTONE_MALL[i]);", 1
	f.WriteText "	end", 1
	f.WriteText "", 1
	f.WriteText "	--��Ӱ�שʯ�̳ǵ���", 1
	f.WriteText "	for i = 1, table.getn(BINDGOLDSTONE_MALL) do", 1
	f.WriteText "		script:AddBindGoldStoneItem(BINDGOLDSTONE_MALL[i]);", 1
	f.WriteText "	end", 1
	f.WriteText "", 1
	f.WriteText "	--�����ʯ�̳ǵ���", 1
	f.WriteText "	for i = 1, table.getn(SILVERSTONE_MALL) do", 1
	f.WriteText "		script:AddSilverStoneItem(SILVERSTONE_MALL[i]);", 1
	f.WriteText "	end", 1
	f.WriteText "", 1
	f.WriteText "	script:SetCurLimitedItems();", 1
	f.WriteText "end", 1

	SaveFile Path & "\" & "Mall.lua", f
	f.Close()
	set f = Nothing
End Sub

Sub WriteItem(f, ItemInfo, name)
	Dim sad(50)
	Dim count
	count = 0

	Set Item = ItemInfo.Item(name)
	For i = 1 To Item.Count
		sad(count) = Item(i)
		count = count + 1
	Next
	For i = LBound(sad) To count - 1
        f.WriteText "			" & sad(i) & ",", 1
    Next
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