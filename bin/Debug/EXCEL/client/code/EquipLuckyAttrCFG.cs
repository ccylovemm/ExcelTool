// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     EquipLuckyAttrCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class EquipLuckyAttrCFG : BaseCFG
	{

		public  List<EquipLuckyAttrVo> items;

		private static EquipLuckyAttrCFG _instance = new EquipLuckyAttrCFG();

		public static EquipLuckyAttrCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public EquipLuckyAttrCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new List<EquipLuckyAttrVo>();
			while(bytes.bytesAvailable)
			{
				EquipLuckyAttrVo obj = new EquipLuckyAttrVo();
				obj.EquipLevel = bytes.ReadUInt32();
				obj.Model = bytes.ReadUInt8();
				obj.Occu = bytes.ReadUInt8();
				obj.minPropID_7 = bytes.ReadUInt32();
				obj.minPropID_8 = bytes.ReadUInt32();
				obj.minPropID_9 = bytes.ReadUInt32();
				obj.minPropID_10 = bytes.ReadUInt32();
				obj.minPropID_11 = bytes.ReadUInt32();
				obj.minPropID_12 = bytes.ReadUInt32();
				obj.minPropID_13 = bytes.ReadUInt32();
				obj.minPropID_14 = bytes.ReadUInt32();
				obj.minPropID_15 = bytes.ReadUInt32();
				obj.minPropID_16 = bytes.ReadUInt32();
				obj.maxPropID_7 = bytes.ReadUInt32();
				obj.maxPropID_8 = bytes.ReadUInt32();
				obj.maxPropID_9 = bytes.ReadUInt32();
				obj.maxPropID_10 = bytes.ReadUInt32();
				obj.maxPropID_11 = bytes.ReadUInt32();
				obj.maxPropID_12 = bytes.ReadUInt32();
				obj.maxPropID_13 = bytes.ReadUInt32();
				obj.maxPropID_14 = bytes.ReadUInt32();
				obj.maxPropID_15 = bytes.ReadUInt32();
				obj.maxPropID_16 = bytes.ReadUInt32();
				obj.SpecialPropID = bytes.ReadString();
				obj.SpecialPropChance = bytes.ReadString();
				obj.SpecialProp = bytes.ReadString();
				items.Add(obj);
			}
			return true;
		}
	}
}
