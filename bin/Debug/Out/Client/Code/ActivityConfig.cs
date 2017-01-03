//************************************************************
// Auto Generated Code By ExcelTool
// Copyright(c) Cao ChunYang  All rights reserved.
//************************************************************

using System;
using System.Collections.Generic;

public class ActivityConfig
{
	static public Dictionary<string , ActivityVo> items;

	static public void Read()
	{
		string json = ResourceManager.ReadText("Activity.json");
		items = Json.Deserialize(jsont) as Dictionary<string, ActivityVo>;
	}
}
