// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     CollectLineCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class CollectLineCFG : BaseCFG
	{

		public Dictionary<UInt32, CollectLineVo> items;

		private static CollectLineCFG _instance = new CollectLineCFG();

		public static CollectLineCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public CollectLineCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, CollectLineVo>();
			while(bytes.bytesAvailable)
			{
				CollectLineVo obj = new CollectLineVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.pictureID = bytes.ReadUInt32();
				obj.addPropertyID = bytes.ReadUInt32();
				obj.value = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
