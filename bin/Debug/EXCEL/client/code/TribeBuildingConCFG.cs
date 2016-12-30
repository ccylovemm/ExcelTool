// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TribeBuildingConCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TribeBuildingConCFG : BaseCFG
	{

		public  List<TribeBuildingConVo> items;

		private static TribeBuildingConCFG _instance = new TribeBuildingConCFG();

		public static TribeBuildingConCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TribeBuildingConCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new List<TribeBuildingConVo>();
			while(bytes.bytesAvailable)
			{
				TribeBuildingConVo obj = new TribeBuildingConVo();
				obj.id = bytes.ReadUInt8();
				obj.name = bytes.ReadString();
				obj.level = bytes.ReadUInt8();
				obj.effect = bytes.ReadString();
				obj.money = bytes.ReadUInt32();
				obj.wood = bytes.ReadUInt32();
				obj.stone = bytes.ReadUInt32();
				obj.cost = bytes.ReadUInt32();
				items.Add(obj);
			}
			return true;
		}
	}
}
