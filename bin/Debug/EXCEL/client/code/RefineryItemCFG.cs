// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     RefineryItemCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class RefineryItemCFG : BaseCFG
	{

		public Dictionary<UInt32, RefineryItemVo> items;

		private static RefineryItemCFG _instance = new RefineryItemCFG();

		public static RefineryItemCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public RefineryItemCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, RefineryItemVo>();
			while(bytes.bytesAvailable)
			{
				RefineryItemVo obj = new RefineryItemVo();
				obj.id = bytes.ReadUInt32();
				obj.lootid = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
