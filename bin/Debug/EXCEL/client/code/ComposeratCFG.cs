// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ComposeratCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ComposeratCFG : BaseCFG
	{

		public Dictionary<UInt32, ComposeratVo> items;

		private static ComposeratCFG _instance = new ComposeratCFG();

		public static ComposeratCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ComposeratCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, ComposeratVo>();
			while(bytes.bytesAvailable)
			{
				ComposeratVo obj = new ComposeratVo();
				obj.ItemLevel = bytes.ReadUInt32();
				obj.miradd = bytes.ReadUInt16();
				obj.poweradd = bytes.ReadUInt16();
				obj.propadd = bytes.ReadUInt16();
				items[obj.ItemLevel] = obj;
			}
			return true;
		}
	}
}
