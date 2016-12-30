// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     CollectPoolCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class CollectPoolCFG : BaseCFG
	{

		public Dictionary<UInt32, CollectPoolVo> items;

		private static CollectPoolCFG _instance = new CollectPoolCFG();

		public static CollectPoolCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public CollectPoolCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, CollectPoolVo>();
			while(bytes.bytesAvailable)
			{
				CollectPoolVo obj = new CollectPoolVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.ghostID = bytes.ReadUInt32();
				obj.pictureID = bytes.ReadUInt32();
				obj.line = bytes.ReadString();
				obj.volume = bytes.ReadUInt32();
				obj.addPropertyID = bytes.ReadUInt32();
				obj.value = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
