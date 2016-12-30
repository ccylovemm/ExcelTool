// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     CopyConfigCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class CopyConfigCFG : BaseCFG
	{

		public Dictionary<UInt32, CopyConfigVo> items;

		private static CopyConfigCFG _instance = new CopyConfigCFG();

		public static CopyConfigCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public CopyConfigCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, CopyConfigVo>();
			while(bytes.bytesAvailable)
			{
				CopyConfigVo obj = new CopyConfigVo();
				obj.id = bytes.ReadUInt32();
				obj.denyCopyId = bytes.ReadUInt32();
				obj.task = bytes.ReadUInt32();
				obj.showPassWin = bytes.ReadUInt8();
				obj.copyType = bytes.ReadUInt8();
				obj.drop1 = bytes.ReadString();
				obj.battlePoint = bytes.ReadString();
				obj.clean = bytes.ReadUInt8();
				obj.group = bytes.ReadUInt32();
				obj.infoType = bytes.ReadUInt8();
				obj.infoTitle = bytes.ReadString();
				obj.infoStr = bytes.ReadString();
				obj.Stars = bytes.ReadString();
				obj.needItem = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
