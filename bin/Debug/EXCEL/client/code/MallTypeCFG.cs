// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     MallTypeCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class MallTypeCFG : BaseCFG
	{

		public Dictionary<UInt16, MallTypeVo> items;

		private static MallTypeCFG _instance = new MallTypeCFG();

		public static MallTypeCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public MallTypeCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, MallTypeVo>();
			while(bytes.bytesAvailable)
			{
				MallTypeVo obj = new MallTypeVo();
				obj.ID = bytes.ReadUInt16();
				obj.name = bytes.ReadString();
				obj.level = bytes.ReadUInt8();
				obj.subTab = bytes.ReadString();
				items[obj.ID] = obj;
			}
			return true;
		}
	}
}