// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     LotteryVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class LotteryVo
	{
		/**
		福袋编号id
		**/
		public Byte set;

		/**
		福袋种类
		**/
		public Byte type;

		/**
		积分段
		**/
		public UInt32 grade;

		/**
		需求等级
		**/
		public UInt16 needlvl;

		/**
		抽一次免费次数
		**/
		public UInt16 time1;

		/**
		冷却时间（秒）
		**/
		public UInt16 CD1;

		/**
		抽一次消耗数量
		**/
		public string cost1;

		/**
		抽10次消耗数量
		**/
		public string cost10;

		/**
		概率
		**/
		public string rates;

		/**
		保底品质
		**/
		public Byte protect;

		/**
		日志类型
		**/
		public Byte logtype;

		/**
		福袋活动名称
		**/
		public string activity;

		/**
		福袋名称
		**/
		public string name;
	}
}
