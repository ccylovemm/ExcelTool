//************************************************************
// Auto Generated Code By ExcelTool
// Copyright(c) Cao ChunYang  All rights reserved.
//************************************************************

using System;
using System.Xml;
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

	override public void Read(XmlDocument xml)
	{
		foreach(XmlNode point in xml.ChildNodes)
		{
			MapVo vo = new MapVo();
			vo.Id = 序号.Parse(point.Attributes["Id"].Value);
			vo.Type = 类型.Parse(point.Attributes["Type"].Value);
			vo.Num = 数量.Parse(point.Attributes["Num"].Value);
			vo.Desc = 描述.Parse(point.Attributes["Desc"].Value);
		}
	}
}
