// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     FuncNotifyCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class FuncNotifyCFG : BaseCFG
	{

		public Dictionary<UInt16, FuncNotifyVo> items;

		private static FuncNotifyCFG _instance = new FuncNotifyCFG();

		public static FuncNotifyCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public FuncNotifyCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, FuncNotifyVo>();
			while(bytes.bytesAvailable)
			{
				FuncNotifyVo obj = new FuncNotifyVo();
				obj.id = bytes.ReadUInt16();
				obj.beginTask = bytes.ReadUInt16();
				obj.beginLevel = bytes.ReadUInt16();
				obj.endTask = bytes.ReadUInt16();
				obj.endLevel = bytes.ReadUInt16();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
