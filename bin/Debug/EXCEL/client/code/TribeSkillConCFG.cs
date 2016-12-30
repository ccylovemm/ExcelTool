// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TribeSkillConCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TribeSkillConCFG : BaseCFG
	{

		public  List<TribeSkillConVo> items;

		private static TribeSkillConCFG _instance = new TribeSkillConCFG();

		public static TribeSkillConCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TribeSkillConCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new List<TribeSkillConVo>();
			while(bytes.bytesAvailable)
			{
				TribeSkillConVo obj = new TribeSkillConVo();
				obj.id = bytes.ReadUInt16();
				obj.name = bytes.ReadString();
				obj.level = bytes.ReadUInt8();
				obj.silver = bytes.ReadUInt32();
				obj.contribution = bytes.ReadUInt32();
				obj.libLevel = bytes.ReadUInt8();
				obj.playerLevel = bytes.ReadUInt8();
				items.Add(obj);
			}
			return true;
		}
	}
}
