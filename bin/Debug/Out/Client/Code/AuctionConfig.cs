//************************************************************
// Auto Generated Code By ExcelTool
// Copyright(c) Cao ChunYang  All rights reserved.
//************************************************************

using System;
using System.Collections.Generic;

public class AuctionConfig
{
	static public Dictionary<string , AuctionVo> items;

	static public void Read()
	{
		string json = ResourceManager.ReadText("Auction.json");
		items = Json.Deserialize(jsont) as Dictionary<string, AuctionVo>;
	}
}
