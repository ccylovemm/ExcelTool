// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     CopyGroupCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class CopyGroupCFG : BaseCFG
	{

		public Dictionary<UInt32, CopyGroupVo> items;

		private static CopyGroupCFG _instance = new CopyGroupCFG();

		public static CopyGroupCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public CopyGroupCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, CopyGroupVo>();
			while(bytes.bytesAvailable)
			{
				CopyGroupVo obj = new CopyGroupVo();
				obj.groupId = bytes.ReadUInt32();
				obj.starList = bytes.ReadString();
				obj.boxDrop = bytes.ReadString();
				items[obj.groupId] = obj;
			}
			return true;
		}
	}
}
