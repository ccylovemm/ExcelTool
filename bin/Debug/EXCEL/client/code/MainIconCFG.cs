// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     MainIconCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class MainIconCFG : BaseCFG
	{

		public Dictionary<UInt16, MainIconVo> items;

		private static MainIconCFG _instance = new MainIconCFG();

		public static MainIconCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public MainIconCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, MainIconVo>();
			while(bytes.bytesAvailable)
			{
				MainIconVo obj = new MainIconVo();
				obj.id = bytes.ReadUInt16();
				obj.data = bytes.ReadString();
				obj.descript = bytes.ReadString();
				obj.type = bytes.ReadUInt16();
				obj.index = bytes.ReadUInt16();
				obj.display = bytes.ReadUInt16();
				obj.iconid = bytes.ReadUInt16();
				obj.layoutid = bytes.ReadUInt16();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
