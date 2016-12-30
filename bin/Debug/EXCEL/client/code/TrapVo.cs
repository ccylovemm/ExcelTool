// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TrapVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class TrapVo
	{
		/**
		陷阱id
		**/
		public UInt32 id;

		/**
		类型
		**/
		public Byte type;

		/**
		形状
		**/
		public Byte shape;

		/**
		圆的半径或者矩形的高
		**/
		public float radius1;

		/**
		矩形的宽
		**/
		public float radius2;

		/**
		持续陷阱伤害心跳间隔
		**/
		public UInt32 intervalTime;

		/**
		直接伤害
		**/
		public UInt32 directDmg;

		/**
		buffid
		**/
		public UInt16 buffid1;

		/**
		目标类型掩码
		**/
		public UInt16 targetFlag1;

		/**
		buffid
		**/
		public UInt16 buffid2;

		/**
		目标类型掩码
		**/
		public UInt16 targetFlag2;

		/**
		buffid
		**/
		public UInt16 buffid3;

		/**
		目标类型掩码
		**/
		public UInt16 targetFlag3;

		/**
		目标数量上限
		**/
		public UInt32 maxTargetNum;

		/**
		预览特效持续时间
		**/
		public UInt32 prevLastTime;
	}
}
