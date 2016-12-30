// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     RefineryAddCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class RefineryAddCFG : BaseCFG
	{

		public Dictionary<UInt32, RefineryAddVo> items;

		private static RefineryAddCFG _instance = new RefineryAddCFG();

		public static RefineryAddCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public RefineryAddCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, RefineryAddVo>();
			while(bytes.bytesAvailable)
			{
				RefineryAddVo obj = new RefineryAddVo();
				obj.id2 = bytes.ReadUInt32();
				obj.fireid2 = bytes.ReadUInt32();
				obj.fireid3 = bytes.ReadUInt32();
				obj.fireid4 = bytes.ReadUInt32();
				obj.fireid5 = bytes.ReadUInt32();
				items[obj.id2] = obj;
			}
			return true;
		}
	}
}
