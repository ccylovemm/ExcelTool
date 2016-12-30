// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     SkillVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class SkillVo
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
		职业
		**/
		public Byte occu;

		/**
		释放方式
		**/
		public Byte usetype;

		/**
		类型
		**/
		public Byte type;

		/**
		攻击类型
		**/
		public Byte attribute;

		/**
		释放距离
		**/
		public UInt16 distance;

		/**
		释放范围
		**/
		public Byte scope;

		/**
		是否可以移动
		**/
		public Byte movetype;

		/**
		技能持续时间
		**/
		public UInt16 lasttime;

		/**
		伤害间隔
		**/
		public string damageinterval;

		/**
		是否调用BUFF效果
		**/
		public string buffflag;

		/**
		半径
		**/
		public UInt16 radius;

		/**
		梯形近底
		**/
		public UInt16 nearwidth;

		/**
		梯形远底
		**/
		public UInt16 farwidth;

		/**
		目标类型
		**/
		public UInt16 targetflag;

		/**
		有益或有害技能
		**/
		public Byte pkattr;

		/**
		icon
		**/
		public UInt32 icon;

		/**
		技能目标表现类型
		**/
		public UInt32 skillLabType;

		/**
		技能动作和效果库
		**/
		public string skillLab;

		/**
		技能第一次伤害效果
		**/
		public string skillMainHurtLab;

		/**
		被击效果
		**/
		public string skillOffHurtLab;

		/**
		自动挂机
		**/
		public Byte autohook;

		/**
		按键位置
		**/
		public Byte skillBar;
	}
}
