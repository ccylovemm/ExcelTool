// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ChallengeLightCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ChallengeLightCFG : BaseCFG
	{

		public Dictionary<UInt32, ChallengeLightVo> items;

		private static ChallengeLightCFG _instance = new ChallengeLightCFG();

		public static ChallengeLightCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ChallengeLightCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, ChallengeLightVo>();
			while(bytes.bytesAvailable)
			{
				ChallengeLightVo obj = new ChallengeLightVo();
				obj.id = bytes.ReadUInt32();
				obj.reason = bytes.ReadString();
				obj.likeTime = bytes.ReadUInt32();
				obj.belikeTime = bytes.ReadUInt32();
				obj.loseTime = bytes.ReadUInt32();
				obj.beworshipTime = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
