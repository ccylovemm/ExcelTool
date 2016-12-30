// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     AchieveCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class AchieveCFG : BaseCFG
	{

		public Dictionary<UInt32, AchieveVo> items;

		private static AchieveCFG _instance = new AchieveCFG();

		public static AchieveCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public AchieveCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, AchieveVo>();
			while(bytes.bytesAvailable)
			{
				AchieveVo obj = new AchieveVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.grade = bytes.ReadString();
				obj.describe = bytes.ReadString();
				obj.limit = bytes.ReadUInt32();
				obj.reward1 = bytes.ReadUInt32();
				obj.num1 = bytes.ReadUInt32();
				obj.reward2 = bytes.ReadUInt32();
				obj.num2 = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
