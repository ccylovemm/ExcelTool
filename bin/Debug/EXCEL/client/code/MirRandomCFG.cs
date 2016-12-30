// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     MirRandomCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class MirRandomCFG : BaseCFG
	{

		public Dictionary<UInt16, MirRandomVo> items;

		private static MirRandomCFG _instance = new MirRandomCFG();

		public static MirRandomCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public MirRandomCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, MirRandomVo>();
			while(bytes.bytesAvailable)
			{
				MirRandomVo obj = new MirRandomVo();
				obj.proid = bytes.ReadUInt16();
				obj.name = bytes.ReadString();
				obj.value = bytes.ReadUInt16();
				obj.index = bytes.ReadUInt16();
				obj.phy_weapon1 = bytes.ReadUInt16();
				obj.phy_weapon2 = bytes.ReadUInt16();
				obj.phy_weapon3 = bytes.ReadUInt16();
				obj.mag_weapon1 = bytes.ReadUInt16();
				obj.mag_weapon2 = bytes.ReadUInt16();
				obj.mag_weapon3 = bytes.ReadUInt16();
				obj.against1 = bytes.ReadUInt16();
				obj.against2 = bytes.ReadUInt16();
				obj.against3 = bytes.ReadUInt16();
				obj.ring1 = bytes.ReadUInt16();
				obj.ring2 = bytes.ReadUInt16();
				obj.ring3 = bytes.ReadUInt16();
				obj.necklace1 = bytes.ReadUInt16();
				obj.necklace2 = bytes.ReadUInt16();
				obj.necklace3 = bytes.ReadUInt16();
				items[obj.proid] = obj;
			}
			return true;
		}
	}
}
