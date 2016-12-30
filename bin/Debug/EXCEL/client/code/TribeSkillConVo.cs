// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TribeSkillConVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class TribeSkillConVo
	{
		/**
		帮会技能id
		**/
		public UInt16 id;

		/**
		名字
		**/
		public string name;

		/**
		技能等级
		**/
		public Byte level;

		/**
		升级消耗银币
		**/
		public UInt32 silver;

		/**
		升级消耗贡献
		**/
		public UInt32 contribution;

		/**
		需求书院等级
		**/
		public Byte libLevel;

		/**
		需要玩家等级
		**/
		public Byte playerLevel;
	}
}
