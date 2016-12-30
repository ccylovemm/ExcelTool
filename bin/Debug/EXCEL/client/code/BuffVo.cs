// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     BuffVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class BuffVo
	{
		/**
		BUFFID
		**/
		public UInt32 id;

		/**
		buff名称
		**/
		public string buffname;

		/**
		组别
		**/
		public Byte group;

		/**
		益害类型
		**/
		public Byte goodtype;

		/**
		中途取消方式
		**/
		public Byte canceltype;

		/**
		效果函数1
		**/
		public Byte effectid;

		/**
		参数1
		**/
		public UInt32 effectparams1;

		/**
		参数2
		**/
		public UInt32 effectparams2;

		/**
		参数3
		**/
		public UInt32 effectparams3;

		/**
		buff消失时触发buffid
		**/
		public UInt32 triggerbuff;

		/**
		最大累加时间
		**/
		public UInt32 maxlasttime;

		/**
		最大累加效果值
		**/
		public UInt32 maxvalue;

		/**
		buffICON
		**/
		public UInt32 icon;

		/**
		buff描述
		**/
		public string bufftips;

		/**
		buff特效id
		**/
		public UInt16 haseffect;

		/**
		特效位置
		**/
		public Byte effectpos;
	}
}
