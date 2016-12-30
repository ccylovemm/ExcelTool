// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ChallengeReportCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ChallengeReportCFG : BaseCFG
	{

		public Dictionary<UInt32, ChallengeReportVo> items;

		private static ChallengeReportCFG _instance = new ChallengeReportCFG();

		public static ChallengeReportCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ChallengeReportCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, ChallengeReportVo>();
			while(bytes.bytesAvailable)
			{
				ChallengeReportVo obj = new ChallengeReportVo();
				obj.id = bytes.ReadUInt32();
				obj.worldWin = bytes.ReadString();
				obj.worldLose = bytes.ReadString();
				obj.worldTop = bytes.ReadString();
				obj.selfWin = bytes.ReadString();
				obj.selfLose = bytes.ReadString();
				obj.selfBeWin = bytes.ReadString();
				obj.selfBeLose = bytes.ReadString();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
