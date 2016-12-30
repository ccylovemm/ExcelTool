// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     PropValueCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class PropValueCFG : BaseCFG
	{

		public Dictionary<UInt16, PropValueVo> items;

		private static PropValueCFG _instance = new PropValueCFG();

		public static PropValueCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public PropValueCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, PropValueVo>();
			while(bytes.bytesAvailable)
			{
				PropValueVo obj = new PropValueVo();
				obj.PropID = bytes.ReadUInt16();
				obj.PropName = bytes.ReadString();
				obj.PropType = bytes.ReadUInt8();
				obj.PropParam = bytes.ReadUInt8();
				obj.Value1 = bytes.ReadUInt32();
				obj.Value2 = bytes.ReadUInt32();
				obj.EquipValue = bytes.ReadUInt32();
				items[obj.PropID] = obj;
			}
			return true;
		}
	}
}
