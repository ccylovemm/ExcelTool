// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     SkillLevelCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class SkillLevelCFG : BaseCFG
	{

		public  List<SkillLevelVo> items;

		private static SkillLevelCFG _instance = new SkillLevelCFG();

		public static SkillLevelCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public SkillLevelCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new List<SkillLevelVo>();
			while(bytes.bytesAvailable)
			{
				SkillLevelVo obj = new SkillLevelVo();
				obj.id = bytes.ReadUInt16();
				obj.name = bytes.ReadString();
				obj.level = bytes.ReadUInt16();
				obj.playerLevel = bytes.ReadUInt8();
				obj.taskId = bytes.ReadUInt32();
				obj.needSilver = bytes.ReadUInt32();
				obj.needCrystal = bytes.ReadUInt32();
				obj.canforget = bytes.ReadUInt8();
				obj.forgetmoney = bytes.ReadUInt32();
				obj.needhp = bytes.ReadUInt32();
				obj.cd = bytes.ReadUInt32();
				obj.preparetime = bytes.ReadUInt32();
				obj.function1 = bytes.ReadUInt8();
				obj.param11 = bytes.ReadUInt32();
				obj.param12 = bytes.ReadUInt32();
				obj.param13 = bytes.ReadUInt32();
				obj.function2 = bytes.ReadUInt8();
				obj.param21 = bytes.ReadUInt32();
				obj.param22 = bytes.ReadUInt32();
				obj.param23 = bytes.ReadUInt32();
				obj.function3 = bytes.ReadUInt8();
				obj.param31 = bytes.ReadUInt32();
				obj.param32 = bytes.ReadUInt32();
				obj.param33 = bytes.ReadUInt32();
				obj.desc = bytes.ReadString();
				items.Add(obj);
			}
			return true;
		}
	}
}
