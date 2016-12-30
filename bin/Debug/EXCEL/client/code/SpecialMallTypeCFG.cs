// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     SpecialMallTypeCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class SpecialMallTypeCFG : BaseCFG
	{

		public Dictionary<UInt16, SpecialMallTypeVo> items;

		private static SpecialMallTypeCFG _instance = new SpecialMallTypeCFG();

		public static SpecialMallTypeCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public SpecialMallTypeCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, SpecialMallTypeVo>();
			while(bytes.bytesAvailable)
			{
				SpecialMallTypeVo obj = new SpecialMallTypeVo();
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
