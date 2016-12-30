// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     RefineryFireCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class RefineryFireCFG : BaseCFG
	{

		public  List<RefineryFireVo> items;

		private static RefineryFireCFG _instance = new RefineryFireCFG();

		public static RefineryFireCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public RefineryFireCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new List<RefineryFireVo>();
			while(bytes.bytesAvailable)
			{
				RefineryFireVo obj = new RefineryFireVo();
				obj.id1 = bytes.ReadUInt32();
				obj.id2 = bytes.ReadUInt32();
				obj.fireid1 = bytes.ReadUInt32();
				obj.fireid2 = bytes.ReadUInt32();
				obj.fireid3 = bytes.ReadUInt32();
				obj.fireid4 = bytes.ReadUInt32();
				obj.fireid5 = bytes.ReadUInt32();
				items.Add(obj);
			}
			return true;
		}
	}
}
