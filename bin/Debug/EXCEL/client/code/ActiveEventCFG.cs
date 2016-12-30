// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ActiveEventCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ActiveEventCFG : BaseCFG
	{

		public Dictionary<Byte, ActiveEventVo> items;

		private static ActiveEventCFG _instance = new ActiveEventCFG();

		public static ActiveEventCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ActiveEventCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<Byte, ActiveEventVo>();
			while(bytes.bytesAvailable)
			{
				ActiveEventVo obj = new ActiveEventVo();
				obj.id = bytes.ReadUInt8();
				obj.name = bytes.ReadString();
				obj.icon = bytes.ReadString();
				obj.times = bytes.ReadUInt8();
				obj.activeDegree = bytes.ReadUInt32();
				obj.reward = bytes.ReadString();
				obj.retrieveSilver = bytes.ReadUInt32();
				obj.retrieveGold = bytes.ReadUInt32();
				obj.isRetrieve = bytes.ReadUInt8();
				obj.retrieveReward = bytes.ReadString();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
