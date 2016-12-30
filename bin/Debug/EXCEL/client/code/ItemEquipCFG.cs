// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ItemEquipCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ItemEquipCFG : BaseCFG
	{

		public Dictionary<UInt32, ItemEquipVo> items;

		private static ItemEquipCFG _instance = new ItemEquipCFG();

		public static ItemEquipCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ItemEquipCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, ItemEquipVo>();
			while(bytes.bytesAvailable)
			{
				ItemEquipVo obj = new ItemEquipVo();
				obj.ItemID = bytes.ReadUInt32();
				obj.Name = bytes.ReadString();
				obj.Class = bytes.ReadUInt8();
				obj.Needlevel = bytes.ReadUInt16();
				obj.vlevel = bytes.ReadUInt16();
				obj.AdvanceID = bytes.ReadUInt32();
				obj.PowerUp_Max = bytes.ReadUInt8();
				obj.Extar_Prop_Max = bytes.ReadUInt8();
				obj.PropID_7 = bytes.ReadUInt32();
				obj.PropID_8 = bytes.ReadUInt32();
				obj.PropID_9 = bytes.ReadUInt32();
				obj.PropID_10 = bytes.ReadUInt32();
				obj.PropID_11 = bytes.ReadUInt32();
				obj.MaxPropID_12 = bytes.ReadUInt32();
				obj.MaxPropID_13 = bytes.ReadUInt32();
				obj.MaxPropID_14 = bytes.ReadUInt32();
				obj.MaxPropID_15 = bytes.ReadUInt32();
				obj.MaxPropID_16 = bytes.ReadUInt32();
				obj.MaxPropID_17 = bytes.ReadUInt32();
				obj.MaxPropID_18 = bytes.ReadUInt32();
				obj.PropID_12 = bytes.ReadUInt32();
				obj.PropID_13 = bytes.ReadUInt32();
				obj.PropID_14 = bytes.ReadUInt32();
				obj.PropID_15 = bytes.ReadUInt32();
				obj.PropID_16 = bytes.ReadUInt32();
				obj.PropID_17 = bytes.ReadUInt32();
				obj.PropID_18 = bytes.ReadUInt32();
				obj.Decompose = bytes.ReadUInt32();
				items[obj.ItemID] = obj;
			}
			return true;
		}
	}
}
