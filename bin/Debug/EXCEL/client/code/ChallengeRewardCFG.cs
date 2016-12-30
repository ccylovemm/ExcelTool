// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ChallengeRewardCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ChallengeRewardCFG : BaseCFG
	{

		public Dictionary<UInt32, ChallengeRewardVo> items;

		private static ChallengeRewardCFG _instance = new ChallengeRewardCFG();

		public static ChallengeRewardCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ChallengeRewardCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, ChallengeRewardVo>();
			while(bytes.bytesAvailable)
			{
				ChallengeRewardVo obj = new ChallengeRewardVo();
				obj.id = bytes.ReadUInt32();
				obj.rankMin = bytes.ReadUInt16();
				obj.rankMax = bytes.ReadUInt16();
				obj.rewardCredit = bytes.ReadUInt32();
				obj.rewardToken = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
