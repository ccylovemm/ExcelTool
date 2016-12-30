// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     MallItemCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class MallItemCFG : BaseCFG
	{

		public Dictionary<UInt32, MallItemVo> items;

		private static MallItemCFG _instance = new MallItemCFG();

		public static MallItemCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public MallItemCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, MallItemVo>();
			while(bytes.bytesAvailable)
			{
				MallItemVo obj = new MallItemVo();
				obj.id = bytes.ReadUInt32();
				obj.itemid = bytes.ReadUInt32();
				obj.num = bytes.ReadUInt16();
				obj.price = bytes.ReadUInt32();
				obj.discountprice = bytes.ReadUInt32();
				obj.moneytype = bytes.ReadUInt8();
				obj.type = bytes.ReadUInt16();
				obj.subType = bytes.ReadUInt8();
				obj.hot = bytes.ReadUInt8();
				obj.isNew = bytes.ReadUInt8();
				obj.preview = bytes.ReadUInt8();
				obj.itemLevel = bytes.ReadUInt8();
				obj.sort = bytes.ReadUInt32();
				obj.totalnum = bytes.ReadUInt32();
				obj.limitnum = bytes.ReadUInt32();
				obj.bBind = bytes.ReadUInt32();
				obj.bLimit = bytes.ReadUInt32();
				obj.hide = bytes.ReadUInt32();
				obj.festival = bytes.ReadString();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
