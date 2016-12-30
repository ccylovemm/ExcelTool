// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     LotteryItemCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class LotteryItemCFG : BaseCFG
	{

		public Dictionary<UInt32, LotteryItemVo> items;

		private static LotteryItemCFG _instance = new LotteryItemCFG();

		public static LotteryItemCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public LotteryItemCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, LotteryItemVo>();
			while(bytes.bytesAvailable)
			{
				LotteryItemVo obj = new LotteryItemVo();
				obj.id = bytes.ReadUInt32();
				obj.set = bytes.ReadUInt8();
				obj.itemid = bytes.ReadUInt32();
				obj.bind = bytes.ReadUInt8();
				obj.number = bytes.ReadUInt32();
				obj.type = bytes.ReadUInt8();
				obj.rate = bytes.ReadUInt16();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
