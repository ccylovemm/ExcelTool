// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     WingPowerUpCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class WingPowerUpCFG : BaseCFG
	{

		public Dictionary<UInt16, WingPowerUpVo> items;

		private static WingPowerUpCFG _instance = new WingPowerUpCFG();

		public static WingPowerUpCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public WingPowerUpCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, WingPowerUpVo>();
			while(bytes.bytesAvailable)
			{
				WingPowerUpVo obj = new WingPowerUpVo();
				obj.id = bytes.ReadUInt16();
				obj.rat = bytes.ReadUInt16();
				obj.PropID1 = bytes.ReadUInt32();
				obj.Value1 = bytes.ReadUInt32();
				obj.PropID2 = bytes.ReadUInt32();
				obj.Value2 = bytes.ReadUInt32();
				obj.PropID3 = bytes.ReadUInt32();
				obj.Value3 = bytes.ReadUInt32();
				obj.PropID4 = bytes.ReadUInt32();
				obj.Value4 = bytes.ReadUInt32();
				obj.PropID5 = bytes.ReadUInt32();
				obj.Value5 = bytes.ReadUInt32();
				obj.PropID6 = bytes.ReadUInt32();
				obj.Value6 = bytes.ReadUInt32();
				obj.PropID7 = bytes.ReadUInt32();
				obj.Value7 = bytes.ReadUInt32();
				obj.needmat1 = bytes.ReadUInt32();
				obj.num1 = bytes.ReadUInt16();
				obj.needgold = bytes.ReadUInt16();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
