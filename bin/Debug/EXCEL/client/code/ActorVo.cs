// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ActorVo.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	public sealed class ActorVo
	{
		/**
		序号
		**/
		public UInt32 id;

		/**
		名称
		**/
		public string name;

		/**
		子名称
		**/
		public string subname;

		/**
		模型名(对应Model表)
		**/
		public string modelName;

		/**
		头像
		**/
		public string icon;

		/**
		模型特效(对应Model表)
		**/
		public string modelEffect;

		/**
		客户端类型
		**/
		public Byte actorType;

		/**
		路径ID
		**/
		public UInt32 pathID;

		/**
		采集类读条时间
		**/
		public UInt32 gatherTime;

		/**
		采集类读条提示
		**/
		public string gatherMsg;

		/**
		出生特效
		**/
		public Byte bornType;

		/**
		死亡特效
		**/
		public UInt32 deadSkillId;

		/**
		掉落出处111
		**/
		public UInt32 drop;

		/**
		掉落类型
		**/
		public string dropType;

		/**
		模型缩小
		**/
		public Int32 scale;

		/**
		头像ID
		**/
		public UInt32 iconID;

		/**
		生命层数
		**/
		public UInt32 lifeCount;

		/**
		描述
		**/
		public string description;

		/**
		等级
		**/
		public UInt16 level;

		/**
		类型
		**/
		public Byte type;

		/**
		功能
		**/
		public string action;

		/**
		品质
		**/
		public Byte quality;

		/**
		体型
		**/
		public Byte size;

		/**
		移动速度
		**/
		public UInt32 moveSpeed;

		/**
		攻击模式
		**/
		public UInt32 attackMode;

		/**
		移动间隔
		**/
		public UInt16 moveInterval;

		/**
		视野范围
		**/
		public UInt16 viewRadius;

		/**
		巡逻范围
		**/
		public UInt16 moveRadius;

		/**
		追击范围
		**/
		public UInt16 approachRadius;

		/**
		复活时间
		**/
		public UInt32 reviveTime;

		/**
		携带技能
		**/
		public string skills;

		/**
		经验
		**/
		public UInt32 exp;

		/**
		掉落组
		**/
		public UInt32 dropGroup;

		/**
		攻击
		**/
		public UInt32 atk;

		/**
		防御
		**/
		public UInt32 def;

		/**
		生命上限
		**/
		public UInt32 maxhp;

		/**
		命中
		**/
		public UInt16 hit;

		/**
		闪避
		**/
		public UInt16 evd;

		/**
		暴击
		**/
		public UInt16 cri;

		/**
		抗暴
		**/
		public UInt16 crires;

		/**
		破防
		**/
		public UInt16 pri;

		/**
		命中率
		**/
		public UInt32 hitrate;

		/**
		闪避率
		**/
		public UInt32 dodgerate;

		/**
		暴击率
		**/
		public UInt32 crirate;

		/**
		抗暴率
		**/
		public UInt32 crireducerate;

		/**
		破防率
		**/
		public UInt32 piercerate;

		/**
		暴击伤害倍率
		**/
		public UInt32 critimes;

		/**
		控制抵抗率
		**/
		public UInt32 resistrate;
	}
}
