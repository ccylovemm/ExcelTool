// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     CollectGhostCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class CollectGhostCFG : BaseCFG
	{

		public Dictionary<UInt32, CollectGhostVo> items;

		private static CollectGhostCFG _instance = new CollectGhostCFG();

		public static CollectGhostCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public CollectGhostCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, CollectGhostVo>();
			while(bytes.bytesAvailable)
			{
				CollectGhostVo obj = new CollectGhostVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.green = bytes.ReadUInt32();
				obj.blue = bytes.ReadUInt32();
				obj.purple = bytes.ReadUInt32();
				obj.golden = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
