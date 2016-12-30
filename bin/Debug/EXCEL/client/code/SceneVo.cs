// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     SceneVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class SceneVo
	{
		/**
		ID
		**/
		public UInt32 id;

		/**
		名称
		**/
		public string name;

		/**
		缩写
		**/
		public string sceneName;

		/**
		图片
		**/
		public UInt16 icon;

		/**
		类型
		**/
		public Byte type;

		/**
		最小等级
		**/
		public UInt16 minlevel;

		/**
		最大等级
		**/
		public UInt16 maxlevel;

		/**
		选项
		**/
		public UInt16 option;

		/**
		主城
		**/
		public UInt32 majorCity;

		/**
		阵营
		**/
		public Byte camp;

		/**
		同步范围
		**/
		public UInt32 syncRange;

		/**
		最大人数
		**/
		public UInt32 maxPlayerNum;

		/**
		场景复活时间
		**/
		public UInt32 reviveTime;

		/**
		场景复活恢复比
		**/
		public UInt32 recoverPercent;

		/**
		复活点X1
		**/
		public float revivePosX1;

		/**
		复活点Z1
		**/
		public float revivePosY1;

		/**
		复活点X2
		**/
		public float revivePosX2;

		/**
		复活点Z2
		**/
		public float revivePosY2;

		/**
		复活点X3
		**/
		public float revivePosX3;

		/**
		复活点Z3
		**/
		public float revivePosY3;

		/**
		入口地图
		**/
		public UInt16 enterScene;

		/**
		入口点X
		**/
		public float enterX;

		/**
		入口点Y
		**/
		public float enterY;

		/**
		入口点Z
		**/
		public float enterZ;

		/**
		入口NPC
		**/
		public UInt32 enterNpc;

		/**
		消耗道具
		**/
		public UInt32 itemId;

		/**
		副本次数
		**/
		public Byte dailytimes;

		/**
		地图介绍
		**/
		public string mapIntroduction;

		/**
		世界地图坐标
		**/
		public string worldCoordinare;

		/**
		场景等级
		**/
		public string sceneLevel;

		/**
		星盘类型
		**/
		public Byte astrolabeType;

		/**
		地图组
		**/
		public Byte mapGroup;

		/**
		自动拾取范围
		**/
		public Byte pickupRange;
	}
}
