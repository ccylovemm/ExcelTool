// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TaskCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TaskCFG : BaseCFG
	{

		public Dictionary<UInt32, TaskVo> items;

		private static TaskCFG _instance = new TaskCFG();

		public static TaskCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TaskCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, TaskVo>();
			while(bytes.bytesAvailable)
			{
				TaskVo obj = new TaskVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.chapter = bytes.ReadUInt8();
				obj.progress = bytes.ReadUInt16();
				obj.type = bytes.ReadUInt8();
				obj.triggerLevel = bytes.ReadUInt16();
				obj.preTask = bytes.ReadUInt32();
				obj.timeLimit = bytes.ReadUInt32();
				obj.abandomTimeLimit = bytes.ReadUInt32();
				obj.rewardsStr = bytes.ReadString();
				obj.describe = bytes.ReadString();
				obj.acceptNpc = bytes.ReadUInt32();
				obj.initTarget = bytes.ReadString();
				obj.unfinishedTarget = bytes.ReadString();
				obj.submitNpc = bytes.ReadUInt32();
				obj.finishedTarget = bytes.ReadString();
				obj.state = bytes.ReadUInt32();
				obj.publishWord = bytes.ReadString();
				obj.publishReply = bytes.ReadString();
				obj.publishReward = bytes.ReadBool();
				obj.unfinishWord = bytes.ReadString();
				obj.unfinishReply = bytes.ReadString();
				obj.unfinishReward = bytes.ReadBool();
				obj.submitWord = bytes.ReadString();
				obj.submitReply = bytes.ReadString();
				obj.submitReward = bytes.ReadBool();
				obj.failedWord = bytes.ReadString();
				obj.failedReply = bytes.ReadString();
				obj.failedReward = bytes.ReadBool();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
