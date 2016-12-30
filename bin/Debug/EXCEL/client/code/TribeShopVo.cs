// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TribeShopVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class TribeShopVo
	{
		/**
		部落商店物品id
		**/
		public UInt32 id;

		/**
		所需宝库等级
		**/
		public Byte tslevel;

		/**
		是否限量
		**/
		public Byte bLimit;

		/**
		出售总量
		**/
		public UInt16 sum;

		/**
		每人限购数量
		**/
		public UInt16 buynum;

		/**
		所需贡献
		**/
		public UInt32 price;
	}
}
