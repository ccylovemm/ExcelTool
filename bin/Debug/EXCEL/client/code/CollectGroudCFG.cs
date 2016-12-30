// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     CollectGroudCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class CollectGroudCFG : BaseCFG
	{

		public Dictionary<UInt32, CollectGroudVo> items;

		private static CollectGroudCFG _instance = new CollectGroudCFG();

		public static CollectGroudCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public CollectGroudCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, CollectGroudVo>();
			while(bytes.bytesAvailable)
			{
				CollectGroudVo obj = new CollectGroudVo();
				obj.id = bytes.ReadUInt32();
				obj.name = bytes.ReadString();
				obj.valume = bytes.ReadUInt32();
				obj.needItem = bytes.ReadUInt32();
				obj.needItemNum = bytes.ReadUInt32();
				obj.greenShow = bytes.ReadUInt32();
				obj.blueShow = bytes.ReadUInt32();
				obj.purpleShow = bytes.ReadUInt32();
				obj.goldenShow = bytes.ReadUInt32();
				obj.greenPercent = bytes.ReadUInt32();
				obj.bluePercent = bytes.ReadUInt32();
				obj.purplePercent = bytes.ReadUInt32();
				obj.goldenPercent = bytes.ReadUInt32();
				obj.story = bytes.ReadString();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
