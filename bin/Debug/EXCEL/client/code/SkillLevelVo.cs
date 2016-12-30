// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     SkillLevelVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class SkillLevelVo
	{
		/**
		技能id
		**/
		public UInt16 id;

		/**
		名称
		**/
		public string name;

		/**
		技能级别
		**/
		public UInt16 level;

		/**
		开启等级
		**/
		public Byte playerLevel;

		/**
		开启任务
		**/
		public UInt32 taskId;

		/**
		银币消耗
		**/
		public UInt32 needSilver;

		/**
		玄晶消耗
		**/
		public UInt32 needCrystal;

		/**
		是否可以遗忘
		**/
		public Byte canforget;

		/**
		遗忘金钱消耗
		**/
		public UInt32 forgetmoney;

		/**
		生命消耗
		**/
		public UInt32 needhp;

		/**
		技能cd
		**/
		public UInt32 cd;

		/**
		吟唱时间
		**/
		public UInt32 preparetime;

		/**
		效果函数1
		**/
		public Byte function1;

		/**
		效果函数1参数1
		**/
		public UInt32 param11;

		/**
		效果函数1参数2
		**/
		public UInt32 param12;

		/**
		效果函数1参数3
		**/
		public UInt32 param13;

		/**
		效果函数2
		**/
		public Byte function2;

		/**
		效果函数2参数1
		**/
		public UInt32 param21;

		/**
		效果函数2参数2
		**/
		public UInt32 param22;

		/**
		效果函数2参数3
		**/
		public UInt32 param23;

		/**
		效果函数3
		**/
		public Byte function3;

		/**
		效果函数3参数1
		**/
		public UInt32 param31;

		/**
		效果函数3参数2
		**/
		public UInt32 param32;

		/**
		效果函数3参数3
		**/
		public UInt32 param33;

		/**
		描述
		**/
		public string desc;
	}
}
