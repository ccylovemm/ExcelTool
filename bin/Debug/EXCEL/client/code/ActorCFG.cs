// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ActorCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ActorCFG : BaseCFG
	{

		public Dictionary<UInt32, ActorVo> items;

		private static ActorCFG _instance = new ActorCFG();

		public static ActorCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ActorCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, ActorVo>();
			while(bytes.bytesAvailable)
			{
				ActorVo obj = new ActorVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.subname = bytes.ReadString();
				obj.modelName = bytes.ReadString();
				obj.icon = bytes.ReadString();
				obj.modelEffect = bytes.ReadString();
				obj.actorType = bytes.ReadUInt8();
				obj.pathID = bytes.ReadUInt32();
				obj.gatherTime = bytes.ReadUInt32();
				obj.gatherMsg = bytes.ReadString();
				obj.bornType = bytes.ReadUInt8();
				obj.deadSkillId = bytes.ReadUInt32();
				obj.drop = bytes.ReadUInt32();
				obj.dropType = bytes.ReadString();
				obj.scale = bytes.ReadInt32();
				obj.iconID = bytes.ReadUInt32();
				obj.lifeCount = bytes.ReadUInt32();
				obj.description = bytes.ReadString();
				obj.level = bytes.ReadUInt16();
				obj.type = bytes.ReadUInt8();
				obj.action = bytes.ReadString();
				obj.quality = bytes.ReadUInt8();
				obj.size = bytes.ReadUInt8();
				obj.moveSpeed = bytes.ReadUInt32();
				obj.attackMode = bytes.ReadUInt32();
				obj.moveInterval = bytes.ReadUInt16();
				obj.viewRadius = bytes.ReadUInt16();
				obj.moveRadius = bytes.ReadUInt16();
				obj.approachRadius = bytes.ReadUInt16();
				obj.reviveTime = bytes.ReadUInt32();
				obj.skills = bytes.ReadString();
				obj.exp = bytes.ReadUInt32();
				obj.dropGroup = bytes.ReadUInt32();
				obj.atk = bytes.ReadUInt32();
				obj.def = bytes.ReadUInt32();
				obj.maxhp = bytes.ReadUInt32();
				obj.hit = bytes.ReadUInt16();
				obj.evd = bytes.ReadUInt16();
				obj.cri = bytes.ReadUInt16();
				obj.crires = bytes.ReadUInt16();
				obj.pri = bytes.ReadUInt16();
				obj.hitrate = bytes.ReadUInt32();
				obj.dodgerate = bytes.ReadUInt32();
				obj.crirate = bytes.ReadUInt32();
				obj.crireducerate = bytes.ReadUInt32();
				obj.piercerate = bytes.ReadUInt32();
				obj.critimes = bytes.ReadUInt32();
				obj.resistrate = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
