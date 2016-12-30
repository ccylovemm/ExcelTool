// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     GiftBoxCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class GiftBoxCFG : BaseCFG
	{

		public Dictionary<UInt16, GiftBoxVo> items;

		private static GiftBoxCFG _instance = new GiftBoxCFG();

		public static GiftBoxCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public GiftBoxCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, GiftBoxVo>();
			while(bytes.bytesAvailable)
			{
				GiftBoxVo obj = new GiftBoxVo();
				obj.id = bytes.ReadUInt16();
				obj.name = bytes.ReadString();
				obj.content = bytes.ReadString();
				obj.clientContent = bytes.ReadString();
				obj.icon = bytes.ReadUInt16();
				obj.P1 = bytes.ReadUInt32();
				obj.P2 = bytes.ReadUInt32();
				obj.P3 = bytes.ReadUInt32();
				obj.exp = bytes.ReadString();
				obj.description = bytes.ReadString();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
