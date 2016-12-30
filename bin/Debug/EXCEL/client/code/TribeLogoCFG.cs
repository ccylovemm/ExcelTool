// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TribeLogoCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TribeLogoCFG : BaseCFG
	{

		public Dictionary<Byte, TribeLogoVo> items;

		private static TribeLogoCFG _instance = new TribeLogoCFG();

		public static TribeLogoCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TribeLogoCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<Byte, TribeLogoVo>();
			while(bytes.bytesAvailable)
			{
				TribeLogoVo obj = new TribeLogoVo();
				obj.id = bytes.ReadUInt8();
				obj.tribelevel = bytes.ReadUInt8();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
