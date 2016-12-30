// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TaskChapterCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TaskChapterCFG : BaseCFG
	{

		public Dictionary<UInt16, TaskChapterVo> items;

		private static TaskChapterCFG _instance = new TaskChapterCFG();

		public static TaskChapterCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TaskChapterCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, TaskChapterVo>();
			while(bytes.bytesAvailable)
			{
				TaskChapterVo obj = new TaskChapterVo();
				obj.id = bytes.ReadUInt16();
				obj.name = bytes.ReadString();
				obj.describe = bytes.ReadString();
				obj.count = bytes.ReadUInt16();
				obj.TaskIdBank = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
