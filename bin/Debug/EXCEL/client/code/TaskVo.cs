// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TaskVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class TaskVo
	{
		/**
		任务id
		**/
		public UInt32 id;

		/**
		任务名
		**/
		public string name;

		/**
		章节TaskChapter
		**/
		public Byte chapter;

		/**
		任务进度
		**/
		public UInt16 progress;

		/**
		任务类型
		**/
		public Byte type;

		/**
		触发等级
		**/
		public UInt16 triggerLevel;

		/**
		前置任务
		**/
		public UInt32 preTask;

		/**
		限时
		**/
		public UInt32 timeLimit;

		/**
		放弃限时
		**/
		public UInt32 abandomTimeLimit;

		/**
		奖励
		**/
		public string rewardsStr;

		/**
		描述
		**/
		public string describe;

		/**
		接取npc
		**/
		public UInt32 acceptNpc;

		/**
		未接任务目标
		**/
		public string initTarget;

		/**
		未完成任务目标
		**/
		public string unfinishedTarget;

		/**
		提交npc
		**/
		public UInt32 submitNpc;

		/**
		完成任务目标
		**/
		public string finishedTarget;

		/**
		是否自动挂机
		**/
		public UInt32 state;

		/**
		发布任务对话
		**/
		public string publishWord;

		/**
		发布任务对话回复
		**/
		public string publishReply;

		/**
		是否显示发布任务奖励
		**/
		public Boolean publishReward;

		/**
		进行中任务对话
		**/
		public string unfinishWord;

		/**
		进行中任务对话回复
		**/
		public string unfinishReply;

		/**
		是否显示进行中任务奖励
		**/
		public Boolean unfinishReward;

		/**
		完成任务对话
		**/
		public string submitWord;

		/**
		完成任务对话回复
		**/
		public string submitReply;

		/**
		是否显示完成任务奖励
		**/
		public Boolean submitReward;

		/**
		失败任务对话
		**/
		public string failedWord;

		/**
		失败任务对话回复
		**/
		public string failedReply;

		/**
		是否显示失败任务奖励
		**/
		public Boolean failedReward;
	}
}
