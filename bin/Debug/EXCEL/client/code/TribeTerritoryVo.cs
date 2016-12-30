// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TribeTerritoryVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class TribeTerritoryVo
	{
		/**
		领土id
		**/
		public UInt32 id;

		/**
		名称
		**/
		public string name;

		/**
		领土等级
		**/
		public Byte level;

		/**
		每周出产的木头
		**/
		public UInt32 uWoods;

		/**
		每周出产的石块
		**/
		public UInt32 uRocks;

		/**
		每周出产的金属
		**/
		public UInt32 uMetal;

		/**
		每周产出的金币
		**/
		public UInt32 uSilver;

		/**
		战争时间段
		**/
		public Byte uWarTime;

		/**
		领土对应的地图ID
		**/
		public UInt32 uMapId;
	}
}
