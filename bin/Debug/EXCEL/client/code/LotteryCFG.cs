// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     LotteryCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class LotteryCFG : BaseCFG
	{

		public Dictionary<Byte, LotteryVo> items;

		private static LotteryCFG _instance = new LotteryCFG();

		public static LotteryCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public LotteryCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<Byte, LotteryVo>();
			while(bytes.bytesAvailable)
			{
				LotteryVo obj = new LotteryVo();
				obj.set = bytes.ReadUInt8();
				obj.type = bytes.ReadUInt8();
				obj.grade = bytes.ReadUInt32();
				obj.needlvl = bytes.ReadUInt16();
				obj.time1 = bytes.ReadUInt16();
				obj.CD1 = bytes.ReadUInt16();
				obj.cost1 = bytes.ReadString();
				obj.cost10 = bytes.ReadString();
				obj.rates = bytes.ReadString();
				obj.protect = bytes.ReadUInt8();
				obj.logtype = bytes.ReadUInt8();
				obj.activity = bytes.ReadString();
				obj.name = bytes.ReadString();
				items[obj.set] = obj;
			}
			return true;
		}
	}
}
