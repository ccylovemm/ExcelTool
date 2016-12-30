// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TaskCycleCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TaskCycleCFG : BaseCFG
	{

		public Dictionary<UInt16, TaskCycleVo> items;

		private static TaskCycleCFG _instance = new TaskCycleCFG();

		public static TaskCycleCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TaskCycleCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, TaskCycleVo>();
			while(bytes.bytesAvailable)
			{
				TaskCycleVo obj = new TaskCycleVo();
				obj.ID = bytes.ReadUInt16();
				obj.name = bytes.ReadUInt16();
				obj.MinLevel = bytes.ReadUInt16();
				obj.MaxLevel = bytes.ReadUInt16();
				obj.count = bytes.ReadUInt16();
				obj.TaskIdBank = bytes.ReadString();
				obj.rewardsStr = bytes.ReadString();
				obj.Type = bytes.ReadUInt16();
				obj.key = bytes.ReadString();
				obj.activeEventId = bytes.ReadUInt32();
				items[obj.ID] = obj;
			}
			return true;
		}
	}
}
