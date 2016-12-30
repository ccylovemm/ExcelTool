// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     CopyConfigVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class CopyConfigVo
	{
		/**
		副本id
		**/
		public UInt32 id;

		/**
		前置副本id
		**/
		public UInt32 denyCopyId;

		/**
		前置任务
		**/
		public UInt32 task;

		/**
		奖励界面
		**/
		public Byte showPassWin;

		/**
		副本类型
		**/
		public Byte copyType;

		/**
		奖励信息
		**/
		public string drop1;

		/**
		推荐战力
		**/
		public string battlePoint;

		/**
		可否扫荡
		**/
		public Byte clean;

		/**
		副本组
		**/
		public UInt32 group;

		/**
		信息类型
		**/
		public Byte infoType;

		/**
		信息标题
		**/
		public string infoTitle;

		/**
		信息提示内容
		**/
		public string infoStr;

		/**
		星级
		**/
		public string Stars;

		/**
		门票
		**/
		public UInt32 needItem;
	}
}
