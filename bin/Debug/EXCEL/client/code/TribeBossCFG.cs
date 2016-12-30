// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TribeBossCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TribeBossCFG : BaseCFG
	{

		public Dictionary<UInt32, TribeBossVo> items;

		private static TribeBossCFG _instance = new TribeBossCFG();

		public static TribeBossCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TribeBossCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, TribeBossVo>();
			while(bytes.bytesAvailable)
			{
				TribeBossVo obj = new TribeBossVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.totemlevel = bytes.ReadUInt8();
				obj.money = bytes.ReadUInt32();
				obj.wood = bytes.ReadUInt32();
				obj.soul = bytes.ReadUInt32();
				obj.metal = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
