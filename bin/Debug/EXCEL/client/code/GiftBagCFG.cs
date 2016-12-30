// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     GiftBagCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class GiftBagCFG : BaseCFG
	{

		public Dictionary<UInt32, GiftBagVo> items;

		private static GiftBagCFG _instance = new GiftBagCFG();

		public static GiftBagCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public GiftBagCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, GiftBagVo>();
			while(bytes.bytesAvailable)
			{
				GiftBagVo obj = new GiftBagVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.icon = bytes.ReadUInt16();
				obj.param1 = bytes.ReadUInt32();
				obj.param2 = bytes.ReadUInt32();
				obj.param3 = bytes.ReadUInt32();
				obj.reward = bytes.ReadString();
				obj.clientContent = bytes.ReadString();
				obj.exp = bytes.ReadString();
				obj.description = bytes.ReadString();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
