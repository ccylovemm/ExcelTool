// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ChallengeTaskCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ChallengeTaskCFG : BaseCFG
	{

		public Dictionary<UInt32, ChallengeTaskVo> items;

		private static ChallengeTaskCFG _instance = new ChallengeTaskCFG();

		public static ChallengeTaskCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ChallengeTaskCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, ChallengeTaskVo>();
			while(bytes.bytesAvailable)
			{
				ChallengeTaskVo obj = new ChallengeTaskVo();
				obj.id = bytes.ReadUInt32();
				obj.taskName = bytes.ReadString();
				obj.taskDescribe = bytes.ReadString();
				obj.spanMin = bytes.ReadUInt32();
				obj.spanMax = bytes.ReadUInt32();
				obj.rewardType = bytes.ReadUInt32();
				obj.rewardID = bytes.ReadUInt32();
				obj.rewardQuantity = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
