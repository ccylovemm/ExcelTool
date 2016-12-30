// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ComposeCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ComposeCFG : BaseCFG
	{

		public Dictionary<UInt32, ComposeVo> items;

		private static ComposeCFG _instance = new ComposeCFG();

		public static ComposeCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ComposeCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, ComposeVo>();
			while(bytes.bytesAvailable)
			{
				ComposeVo obj = new ComposeVo();
				obj.itemid = bytes.ReadUInt32();
				obj.type = bytes.ReadUInt8();
				obj.name = bytes.ReadString();
				obj.level = bytes.ReadUInt16();
				obj.rat = bytes.ReadUInt16();
				obj.num = bytes.ReadUInt8();
				obj.falitemid = bytes.ReadUInt32();
				obj.falnum = bytes.ReadUInt8();
				obj.bind = bytes.ReadUInt8();
				obj.needmat1 = bytes.ReadUInt32();
				obj.num1 = bytes.ReadUInt16();
				obj.needmat2 = bytes.ReadUInt32();
				obj.num2 = bytes.ReadUInt16();
				obj.needmat3 = bytes.ReadUInt32();
				obj.num3 = bytes.ReadUInt16();
				obj.needgold = bytes.ReadUInt32();
				items[obj.itemid] = obj;
			}
			return true;
		}
	}
}
