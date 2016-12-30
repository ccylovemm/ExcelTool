// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     CfgFiles.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	public class CfgFiles
	{
		public Dictionary<String,BaseCFG> infos = null;
		private static CfgFiles _instance = new CfgFiles();

		public static CfgFiles Instance
		{
			get
			{
				if(_instance.infos == null)
				{
					_instance.infos = new Dictionary<String,BaseCFG>();
					_instance.Init();
				}
				return _instance;
			}
		}

	protected void Init(){

			infos["Achieve.dat"] = AchieveCFG.Instance;
			infos["ActiveEvent.dat"] = ActiveEventCFG.Instance;
			infos["Activity.dat"] = ActivityCFG.Instance;
			infos["Actor.dat"] = ActorCFG.Instance;
			infos["ActorGrow.dat"] = ActorGrowCFG.Instance;
			infos["AutoPoint.dat"] = AutoPointCFG.Instance;
			infos["Buff.dat"] = BuffCFG.Instance;
			infos["ChallengeLevel.dat"] = ChallengeLevelCFG.Instance;
			infos["ChallengeLight.dat"] = ChallengeLightCFG.Instance;
			infos["ChallengeReport.dat"] = ChallengeReportCFG.Instance;
			infos["ChallengeReward.dat"] = ChallengeRewardCFG.Instance;
			infos["ChallengeTask.dat"] = ChallengeTaskCFG.Instance;
			infos["ChallengeWorship.dat"] = ChallengeWorshipCFG.Instance;
			infos["CollectGhost.dat"] = CollectGhostCFG.Instance;
			infos["CollectGroud.dat"] = CollectGroudCFG.Instance;
			infos["CollectLine.dat"] = CollectLineCFG.Instance;
			infos["CollectPicture.dat"] = CollectPictureCFG.Instance;
			infos["CollectPool.dat"] = CollectPoolCFG.Instance;
			infos["Compose.dat"] = ComposeCFG.Instance;
			infos["Composerat.dat"] = ComposeratCFG.Instance;
			infos["ComposeType.dat"] = ComposeTypeCFG.Instance;
			infos["CopyConfig.dat"] = CopyConfigCFG.Instance;
			infos["CopyGroup.dat"] = CopyGroupCFG.Instance;
			infos["DailyTask.dat"] = DailyTaskCFG.Instance;
			infos["DropGroup.dat"] = DropGroupCFG.Instance;
			infos["DropRandom.dat"] = DropRandomCFG.Instance;
			infos["EquipLuckyAttr.dat"] = EquipLuckyAttrCFG.Instance;
			infos["EquipPowerUp.dat"] = EquipPowerUpCFG.Instance;
			infos["EquipPropAdd.dat"] = EquipPropAddCFG.Instance;
			infos["Exp.dat"] = ExpCFG.Instance;
			infos["FuncNotify.dat"] = FuncNotifyCFG.Instance;
			infos["GiftBag.dat"] = GiftBagCFG.Instance;
			infos["GiftBox.dat"] = GiftBoxCFG.Instance;
			infos["Item.dat"] = ItemCFG.Instance;
			infos["ItemEquip.dat"] = ItemEquipCFG.Instance;
			infos["ItemSuite.dat"] = ItemSuiteCFG.Instance;
			infos["Lottery.dat"] = LotteryCFG.Instance;
			infos["LotteryItem.dat"] = LotteryItemCFG.Instance;
			infos["MainIcon.dat"] = MainIconCFG.Instance;
			infos["MallItem.dat"] = MallItemCFG.Instance;
			infos["MallType.dat"] = MallTypeCFG.Instance;
			infos["Message.dat"] = MessageCFG.Instance;
			infos["MirRandom.dat"] = MirRandomCFG.Instance;
			infos["Occu.dat"] = OccuCFG.Instance;
			infos["OccuProp.dat"] = OccuPropCFG.Instance;
			infos["Parameter.dat"] = ParameterCFG.Instance;
			infos["PropValue.dat"] = PropValueCFG.Instance;
			infos["RandomName.dat"] = RandomNameCFG.Instance;
			infos["RefineryAdd.dat"] = RefineryAddCFG.Instance;
			infos["RefineryFire.dat"] = RefineryFireCFG.Instance;
			infos["RefineryItem.dat"] = RefineryItemCFG.Instance;
			infos["Scene.dat"] = SceneCFG.Instance;
			infos["Skill.dat"] = SkillCFG.Instance;
			infos["SkillLevel.dat"] = SkillLevelCFG.Instance;
			infos["SkillList.dat"] = SkillListCFG.Instance;
			infos["SpecialMallItem.dat"] = SpecialMallItemCFG.Instance;
			infos["SpecialMallType.dat"] = SpecialMallTypeCFG.Instance;
			infos["Task.dat"] = TaskCFG.Instance;
			infos["TaskChapter.dat"] = TaskChapterCFG.Instance;
			infos["TaskCycle.dat"] = TaskCycleCFG.Instance;
			infos["TaskToLua.dat"] = TaskToLuaCFG.Instance;
			infos["Trap.dat"] = TrapCFG.Instance;
			infos["TribeBoss.dat"] = TribeBossCFG.Instance;
			infos["TribeBuildingCon.dat"] = TribeBuildingConCFG.Instance;
			infos["TribeBuildingFunc.dat"] = TribeBuildingFuncCFG.Instance;
			infos["TribeDonate.dat"] = TribeDonateCFG.Instance;
			infos["TribeLogo.dat"] = TribeLogoCFG.Instance;
			infos["TribeShop.dat"] = TribeShopCFG.Instance;
			infos["TribeSkillCon.dat"] = TribeSkillConCFG.Instance;
			infos["TribeTerritory.dat"] = TribeTerritoryCFG.Instance;
			infos["WingPowerUp.dat"] = WingPowerUpCFG.Instance;
			infos["WingStagelUp.dat"] = WingStagelUpCFG.Instance;
		}
	}
}
