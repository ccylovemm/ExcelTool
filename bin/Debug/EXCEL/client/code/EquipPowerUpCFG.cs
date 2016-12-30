// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     EquipPowerUpCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class EquipPowerUpCFG : BaseCFG
	{

		public Dictionary<Byte, EquipPowerUpVo> items;

		private static EquipPowerUpCFG _instance = new EquipPowerUpCFG();

		public static EquipPowerUpCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public EquipPowerUpCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<Byte, EquipPowerUpVo>();
			while(bytes.bytesAvailable)
			{
				EquipPowerUpVo obj = new EquipPowerUpVo();
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
				obj.param10 = bytes.ReadString();
				obj.param11 = bytes.ReadString();
				obj.needgold = bytes.ReadUInt16();
				obj.needmat1 = bytes.ReadUInt32();
				obj.num1 = bytes.ReadUInt16();
				obj.needmat2 = bytes.ReadUInt32();
				obj.num2 = bytes.ReadUInt16();
				obj.needmat3 = bytes.ReadUInt32();
				obj.num3 = bytes.ReadUInt16();
				obj.protectionid = bytes.ReadUInt32();
				obj.protectionnum = bytes.ReadUInt16();
				items[obj.level] = obj;
			}
			return true;
		}
	}
}
