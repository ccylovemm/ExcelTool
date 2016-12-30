// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TribeShopCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TribeShopCFG : BaseCFG
	{

		public Dictionary<UInt32, TribeShopVo> items;

		private static TribeShopCFG _instance = new TribeShopCFG();

		public static TribeShopCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TribeShopCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, TribeShopVo>();
			while(bytes.bytesAvailable)
			{
				TribeShopVo obj = new TribeShopVo();
				obj.id = bytes.ReadUInt32();
				obj.tslevel = bytes.ReadUInt8();
				obj.bLimit = bytes.ReadUInt8();
				obj.sum = bytes.ReadUInt16();
				obj.buynum = bytes.ReadUInt16();
				obj.price = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
