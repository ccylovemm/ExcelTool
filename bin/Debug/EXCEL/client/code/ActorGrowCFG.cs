// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ActorGrowCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ActorGrowCFG : BaseCFG
	{

		public Dictionary<UInt16, ActorGrowVo> items;

		private static ActorGrowCFG _instance = new ActorGrowCFG();

		public static ActorGrowCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ActorGrowCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, ActorGrowVo>();
			while(bytes.bytesAvailable)
			{
				ActorGrowVo obj = new ActorGrowVo();
				obj.occu = bytes.ReadUInt16();
				obj.basePoint = bytes.ReadUInt16();
				obj.Stren = bytes.ReadUInt16();
				obj.Intel = bytes.ReadUInt16();
				obj.Agil = bytes.ReadUInt16();
				obj.Vital = bytes.ReadUInt16();
				obj.phyattack = bytes.ReadUInt32();
				obj.magattack = bytes.ReadUInt32();
				obj.phydefense = bytes.ReadUInt32();
				obj.magdefense = bytes.ReadUInt32();
				obj.maxhp = bytes.ReadUInt32();
				obj.fruitStren = bytes.ReadUInt16();
				obj.fruitIntel = bytes.ReadUInt16();
				obj.fruitAgil = bytes.ReadUInt16();
				obj.fruitVital = bytes.ReadUInt16();
				items[obj.occu] = obj;
			}
			return true;
		}
	}
}
