// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ChallengeLevelCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ChallengeLevelCFG : BaseCFG
	{

		public Dictionary<UInt32, ChallengeLevelVo> items;

		private static ChallengeLevelCFG _instance = new ChallengeLevelCFG();

		public static ChallengeLevelCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ChallengeLevelCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, ChallengeLevelVo>();
			while(bytes.bytesAvailable)
			{
				ChallengeLevelVo obj = new ChallengeLevelVo();
				obj.id = bytes.ReadUInt32();
				obj.level = bytes.ReadString();
				obj.needCredit = bytes.ReadUInt32();
				obj.phyattack = bytes.ReadUInt32();
				obj.magattack = bytes.ReadUInt32();
				obj.phydefense = bytes.ReadUInt32();
				obj.magdefense = bytes.ReadUInt32();
				obj.maxhp = bytes.ReadUInt32();
				obj.hit = bytes.ReadUInt32();
				obj.damageBonus = bytes.ReadUInt32();
				obj.crit = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
