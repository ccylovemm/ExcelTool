// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TribeDonateCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TribeDonateCFG : BaseCFG
	{

		public Dictionary<UInt32, TribeDonateVo> items;

		private static TribeDonateCFG _instance = new TribeDonateCFG();

		public static TribeDonateCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TribeDonateCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, TribeDonateVo>();
			while(bytes.bytesAvailable)
			{
				TribeDonateVo obj = new TribeDonateVo();
				obj.id = bytes.ReadUInt32();
				obj.item1 = bytes.ReadUInt8();
				obj.type1 = bytes.ReadUInt8();
				obj.number1 = bytes.ReadUInt8();
				obj.con1 = bytes.ReadUInt8();
				obj.fund1 = bytes.ReadUInt32();
				obj.item2 = bytes.ReadUInt8();
				obj.type2 = bytes.ReadUInt8();
				obj.number2 = bytes.ReadUInt8();
				obj.con2 = bytes.ReadUInt8();
				obj.fund2 = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
