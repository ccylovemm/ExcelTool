// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ActiveEventVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class ActiveEventVo
	{
		/**
		活跃度事件id
		**/
		public Byte id;

		/**
		名称
		**/
		public string name;

		/**
		图标
		**/
		public string icon;

		/**
		次数
		**/
		public Byte times;

		/**
		完成一次活跃度
		**/
		public UInt32 activeDegree;

		/**
		奖励
		**/
		public string reward;

		/**
		单次找回银币花费
		**/
		public UInt32 retrieveSilver;

		/**
		单次找回元宝花费
		**/
		public UInt32 retrieveGold;

		/**
		能否找回
		**/
		public Byte isRetrieve;

		/**
		单次找回资源奖励
		**/
		public string retrieveReward;
	}
}
