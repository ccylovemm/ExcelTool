// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TaskCycleVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class TaskCycleVo
	{
		/**
		任务链ID
		**/
		public UInt16 ID;

		/**
		名称
		**/
		public UInt16 name;

		/**
		最小等级
		**/
		public UInt16 MinLevel;

		/**
		最大等级
		**/
		public UInt16 MaxLevel;

		/**
		任务环数
		**/
		public UInt16 count;

		/**
		任务ID库
		**/
		public string TaskIdBank;

		/**
		10环额外奖励
		**/
		public string rewardsStr;

		/**
		任务类别
		**/
		public UInt16 Type;

		/**
		计数键
		**/
		public string key;

		/**
		活跃度事件id
		**/
		public UInt32 activeEventId;
	}
}
