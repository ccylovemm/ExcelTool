// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     SkillListCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class SkillListCFG : BaseCFG
	{

		public Dictionary<UInt16, SkillListVo> items;

		private static SkillListCFG _instance = new SkillListCFG();

		public static SkillListCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public SkillListCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, SkillListVo>();
			while(bytes.bytesAvailable)
			{
				SkillListVo obj = new SkillListVo();
				obj.skill = bytes.ReadUInt16();
				obj.occu = bytes.ReadUInt8();
				obj.type = bytes.ReadUInt8();
				obj.needlevel = bytes.ReadUInt16();
				obj.stage = bytes.ReadUInt8();
				obj.item = bytes.ReadUInt16();
				items[obj.skill] = obj;
			}
			return true;
		}
	}
}
