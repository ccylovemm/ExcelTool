//************************************************************
// Auto Generated Code By ExcelTool
// Copyright(c) Cao ChunYang  All rights reserved.
//************************************************************

using System;
using System.Collections.Generic;

public class MapVo
{
	public Id 序号; // uint  (key)
	public Type 类型; // int 
	public Num 数量; // uint 
	public Desc 描述; // string
}

public class MapCFG : BaseCFG
{
	static public Dictionary<string , MapVo> items;

	static private MapCFG _instance = new MapCFG();

	static public MapCFG Instance
	{
		get
		{
			return _instance;
		}
	}

	override public void Read(string str)
	{
		items = Json.Deserialize(str) as Dictionary<string, MapVo>;
	}
}
