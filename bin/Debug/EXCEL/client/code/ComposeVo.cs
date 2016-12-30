// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ComposeVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class ComposeVo
	{
		/**
		合成ID
		**/
		public UInt32 itemid;

		/**
		分类
		**/
		public Byte type;

		/**
		合成名称
		**/
		public string name;

		/**
		合成需要玩家等级
		**/
		public UInt16 level;

		/**
		成功概率
		**/
		public UInt16 rat;

		/**
		成功道具数量
		**/
		public Byte num;

		/**
		失败生成道具
		**/
		public UInt32 falitemid;

		/**
		失败道具数量
		**/
		public Byte falnum;

		/**
		是否绑定
		**/
		public Byte bind;

		/**
		原料1
		**/
		public UInt32 needmat1;

		/**
		数量1
		**/
		public UInt16 num1;

		/**
		原料2
		**/
		public UInt32 needmat2;

		/**
		数量2
		**/
		public UInt16 num2;

		/**
		原料3
		**/
		public UInt32 needmat3;

		/**
		数量3
		**/
		public UInt16 num3;

		/**
		需要金钱数量
		**/
		public UInt32 needgold;
	}
}
