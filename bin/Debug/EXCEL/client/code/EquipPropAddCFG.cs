// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     EquipPropAddCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class EquipPropAddCFG : BaseCFG
	{

		public  List<EquipPropAddVo> items;

		private static EquipPropAddCFG _instance = new EquipPropAddCFG();

		public static EquipPropAddCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public EquipPropAddCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new List<EquipPropAddVo>();
			while(bytes.bytesAvailable)
			{
				EquipPropAddVo obj = new EquipPropAddVo();
				obj.level = bytes.ReadUInt8();
				obj.rat = bytes.ReadUInt16();
				obj.backlevel = bytes.ReadUInt8();
				obj.param1 = bytes.ReadString();
				obj.param2 = bytes.ReadString();
				obj.param3 = bytes.ReadString();
				obj.param4 = bytes.ReadString();
				obj.param5 = bytes.ReadString();
				obj.param6 = bytes.ReadString();
				obj.param7 = bytes.ReadString();
				obj.param8 = bytes.ReadString();
				obj.param9 = bytes.ReadString();
				obj.param10 = bytes.ReadString();
				obj.needgold = bytes.ReadUInt16();
				obj.needmat1 = bytes.ReadUInt16();
				obj.num1 = bytes.ReadUInt16();
				items.Add(obj);
			}
			return true;
		}
	}
}
