// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     SceneCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class SceneCFG : BaseCFG
	{

		public Dictionary<UInt32, SceneVo> items;

		private static SceneCFG _instance = new SceneCFG();

		public static SceneCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public SceneCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, SceneVo>();
			while(bytes.bytesAvailable)
			{
				SceneVo obj = new SceneVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.sceneName = bytes.ReadString();
				obj.icon = bytes.ReadUInt16();
				obj.type = bytes.ReadUInt8();
				obj.minlevel = bytes.ReadUInt16();
				obj.maxlevel = bytes.ReadUInt16();
				obj.option = bytes.ReadUInt16();
				obj.majorCity = bytes.ReadUInt32();
				obj.camp = bytes.ReadUInt8();
				obj.syncRange = bytes.ReadUInt32();
				obj.maxPlayerNum = bytes.ReadUInt32();
				obj.reviveTime = bytes.ReadUInt32();
				obj.recoverPercent = bytes.ReadUInt32();
				obj.revivePosX1 = bytes.ReadFloat();
				obj.revivePosY1 = bytes.ReadFloat();
				obj.revivePosX2 = bytes.ReadFloat();
				obj.revivePosY2 = bytes.ReadFloat();
				obj.revivePosX3 = bytes.ReadFloat();
				obj.revivePosY3 = bytes.ReadFloat();
				obj.enterScene = bytes.ReadUInt16();
				obj.enterX = bytes.ReadFloat();
				obj.enterY = bytes.ReadFloat();
				obj.enterZ = bytes.ReadFloat();
				obj.enterNpc = bytes.ReadUInt32();
				obj.itemId = bytes.ReadUInt32();
				obj.dailytimes = bytes.ReadUInt8();
				obj.mapIntroduction = bytes.ReadString();
				obj.worldCoordinare = bytes.ReadString();
				obj.sceneLevel = bytes.ReadString();
				obj.astrolabeType = bytes.ReadUInt8();
				obj.mapGroup = bytes.ReadUInt8();
				obj.pickupRange = bytes.ReadUInt8();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
