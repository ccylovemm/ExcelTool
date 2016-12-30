// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     WingStagelUpCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class WingStagelUpCFG : BaseCFG
	{

		public Dictionary<Byte, WingStagelUpVo> items;

		private static WingStagelUpCFG _instance = new WingStagelUpCFG();

		public static WingStagelUpCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public WingStagelUpCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<Byte, WingStagelUpVo>();
			while(bytes.bytesAvailable)
			{
				WingStagelUpVo obj = new WingStagelUpVo();
				obj.id = bytes.ReadUInt8();
				obj.rat = bytes.ReadUInt16();
				obj.needmat1 = bytes.ReadUInt32();
				obj.num1 = bytes.ReadUInt16();
				obj.progress = bytes.ReadUInt8();
				obj.needgold = bytes.ReadUInt16();
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
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
