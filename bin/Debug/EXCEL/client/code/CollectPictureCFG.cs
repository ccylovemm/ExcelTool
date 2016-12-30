// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     CollectPictureCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class CollectPictureCFG : BaseCFG
	{

		public Dictionary<UInt32, CollectPictureVo> items;

		private static CollectPictureCFG _instance = new CollectPictureCFG();

		public static CollectPictureCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public CollectPictureCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, CollectPictureVo>();
			while(bytes.bytesAvailable)
			{
				CollectPictureVo obj = new CollectPictureVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.level = bytes.ReadUInt32();
				obj.group = bytes.ReadUInt32();
				obj.addPropertyID = bytes.ReadUInt32();
				obj.value = bytes.ReadUInt32();
				obj.explain = bytes.ReadString();
				obj.actor = bytes.ReadString();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
