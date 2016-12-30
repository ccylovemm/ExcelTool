// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TribeBuildingFuncCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TribeBuildingFuncCFG : BaseCFG
	{

		public Dictionary<UInt16, TribeBuildingFuncVo> items;

		private static TribeBuildingFuncCFG _instance = new TribeBuildingFuncCFG();

		public static TribeBuildingFuncCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TribeBuildingFuncCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, TribeBuildingFuncVo>();
			while(bytes.bytesAvailable)
			{
				TribeBuildingFuncVo obj = new TribeBuildingFuncVo();
				obj.id = bytes.ReadUInt16();
				obj.name = bytes.ReadString();
				obj.FUN1 = bytes.ReadUInt32();
				obj.FUN2 = bytes.ReadUInt32();
				obj.FUN3 = bytes.ReadUInt32();
				obj.FUN4 = bytes.ReadUInt32();
				obj.FUN5 = bytes.ReadUInt32();
				obj.FUN6 = bytes.ReadUInt32();
				obj.FUN7 = bytes.ReadUInt32();
				obj.FUN8 = bytes.ReadUInt32();
				obj.FUN9 = bytes.ReadUInt32();
				obj.FUN10 = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
