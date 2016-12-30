// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     SkillCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class SkillCFG : BaseCFG
	{

		public Dictionary<UInt16, SkillVo> items;

		private static SkillCFG _instance = new SkillCFG();

		public static SkillCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public SkillCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, SkillVo>();
			while(bytes.bytesAvailable)
			{
				SkillVo obj = new SkillVo();
				obj.id = bytes.ReadUInt16();
				obj.name = bytes.ReadString();
				obj.occu = bytes.ReadUInt8();
				obj.usetype = bytes.ReadUInt8();
				obj.type = bytes.ReadUInt8();
				obj.attribute = bytes.ReadUInt8();
				obj.distance = bytes.ReadUInt16();
				obj.scope = bytes.ReadUInt8();
				obj.movetype = bytes.ReadUInt8();
				obj.lasttime = bytes.ReadUInt16();
				obj.damageinterval = bytes.ReadString();
				obj.buffflag = bytes.ReadString();
				obj.radius = bytes.ReadUInt16();
				obj.nearwidth = bytes.ReadUInt16();
				obj.farwidth = bytes.ReadUInt16();
				obj.targetflag = bytes.ReadUInt16();
				obj.pkattr = bytes.ReadUInt8();
				obj.icon = bytes.ReadUInt32();
				obj.skillLabType = bytes.ReadUInt32();
				obj.skillLab = bytes.ReadString();
				obj.skillMainHurtLab = bytes.ReadString();
				obj.skillOffHurtLab = bytes.ReadString();
				obj.autohook = bytes.ReadUInt8();
				obj.skillBar = bytes.ReadUInt8();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
