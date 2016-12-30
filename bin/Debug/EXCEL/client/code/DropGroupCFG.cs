// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     DropGroupCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class DropGroupCFG : BaseCFG
	{

		public Dictionary<UInt32, DropGroupVo> items;

		private static DropGroupCFG _instance = new DropGroupCFG();

		public static DropGroupCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public DropGroupCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, DropGroupVo>();
			while(bytes.bytesAvailable)
			{
				DropGroupVo obj = new DropGroupVo();
				obj.id = bytes.ReadUInt32();
				obj.dropmethod = bytes.ReadUInt8();
				obj.products = bytes.ReadString();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
