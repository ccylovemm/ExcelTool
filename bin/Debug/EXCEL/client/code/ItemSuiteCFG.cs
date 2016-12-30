// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ItemSuiteCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ItemSuiteCFG : BaseCFG
	{

		public Dictionary<UInt16, ItemSuiteVo> items;

		private static ItemSuiteCFG _instance = new ItemSuiteCFG();

		public static ItemSuiteCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ItemSuiteCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, ItemSuiteVo>();
			while(bytes.bytesAvailable)
			{
				ItemSuiteVo obj = new ItemSuiteVo();
				obj.SuiteID = bytes.ReadUInt16();
				obj.SuiteName = bytes.ReadString();
				obj.SuiteStage = bytes.ReadUInt8();
				obj.num = bytes.ReadUInt8();
				obj.need1 = bytes.ReadString();
				obj.need2 = bytes.ReadString();
				obj.need3 = bytes.ReadString();
				obj.need4 = bytes.ReadString();
				obj.need5 = bytes.ReadString();
				obj.SuitNum1 = bytes.ReadUInt8();
				obj.PropID1 = bytes.ReadUInt8();
				obj.Value1 = bytes.ReadUInt16();
				obj.SuitNum2 = bytes.ReadUInt8();
				obj.PropID2 = bytes.ReadUInt8();
				obj.Value2 = bytes.ReadUInt16();
				obj.SuitNum3 = bytes.ReadUInt8();
				obj.PropID3 = bytes.ReadUInt8();
				obj.Value3 = bytes.ReadUInt16();
				obj.SuitNum4 = bytes.ReadUInt8();
				obj.PropID4 = bytes.ReadUInt8();
				obj.Value4 = bytes.ReadUInt16();
				obj.SuitNum5 = bytes.ReadUInt8();
				obj.PropID5 = bytes.ReadUInt8();
				obj.Value5 = bytes.ReadUInt16();
				obj.SuitNum6 = bytes.ReadUInt8();
				obj.PropID6 = bytes.ReadUInt8();
				obj.Value6 = bytes.ReadUInt16();
				obj.SuitNum7 = bytes.ReadUInt8();
				obj.PropID7 = bytes.ReadUInt8();
				obj.Value7 = bytes.ReadUInt16();
				obj.SuitNum8 = bytes.ReadUInt8();
				obj.PropID8 = bytes.ReadUInt8();
				obj.Value8 = bytes.ReadUInt16();
				obj.SuitNum9 = bytes.ReadUInt8();
				obj.PropID9 = bytes.ReadUInt8();
				obj.Value9 = bytes.ReadUInt16();
				obj.SuitNum10 = bytes.ReadUInt8();
				obj.PropID10 = bytes.ReadUInt8();
				obj.Value10 = bytes.ReadUInt16();
				items[obj.SuiteID] = obj;
			}
			return true;
		}
	}
}
