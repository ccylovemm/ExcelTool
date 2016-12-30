// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ExpCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ExpCFG : BaseCFG
	{

		public Dictionary<UInt16, ExpVo> items;

		private static ExpCFG _instance = new ExpCFG();

		public static ExpCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ExpCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, ExpVo>();
			while(bytes.bytesAvailable)
			{
				ExpVo obj = new ExpVo();
				obj.level = bytes.ReadUInt16();
				obj.exp = (UInt64)bytes.ReadUInt32();
				obj.totalexp = (UInt64)bytes.ReadUInt32();
				obj.sitbasicexp = bytes.ReadUInt16();
				items[obj.level] = obj;
			}
			return true;
		}
	}
}
