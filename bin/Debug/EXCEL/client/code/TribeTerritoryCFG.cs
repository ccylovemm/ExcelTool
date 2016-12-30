// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TribeTerritoryCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TribeTerritoryCFG : BaseCFG
	{

		public Dictionary<UInt32, TribeTerritoryVo> items;

		private static TribeTerritoryCFG _instance = new TribeTerritoryCFG();

		public static TribeTerritoryCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TribeTerritoryCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, TribeTerritoryVo>();
			while(bytes.bytesAvailable)
			{
				TribeTerritoryVo obj = new TribeTerritoryVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.level = bytes.ReadUInt8();
				obj.uWoods = bytes.ReadUInt32();
				obj.uRocks = bytes.ReadUInt32();
				obj.uMetal = bytes.ReadUInt32();
				obj.uSilver = bytes.ReadUInt32();
				obj.uWarTime = bytes.ReadUInt8();
				obj.uMapId = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
