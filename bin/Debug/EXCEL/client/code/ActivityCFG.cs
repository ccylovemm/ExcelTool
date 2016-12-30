// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ActivityCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ActivityCFG : BaseCFG
	{

		public Dictionary<UInt32, ActivityVo> items;

		private static ActivityCFG _instance = new ActivityCFG();

		public static ActivityCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ActivityCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, ActivityVo>();
			while(bytes.bytesAvailable)
			{
				ActivityVo obj = new ActivityVo();
				obj.id = bytes.ReadUInt32();
				obj.grade = bytes.ReadUInt32();
				obj.reward1 = bytes.ReadUInt32();
				obj.num1 = bytes.ReadUInt32();
				obj.reward2 = bytes.ReadUInt32();
				obj.num2 = bytes.ReadUInt32();
				obj.reward3 = bytes.ReadUInt32();
				obj.num3 = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
