// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     OccuPropCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class OccuPropCFG : BaseCFG
	{

		public  List<OccuPropVo> items;

		private static OccuPropCFG _instance = new OccuPropCFG();

		public static OccuPropCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public OccuPropCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new List<OccuPropVo>();
			while(bytes.bytesAvailable)
			{
				OccuPropVo obj = new OccuPropVo();
				obj.occu = bytes.ReadUInt8();
				obj.type = bytes.ReadUInt8();
				obj.name = bytes.ReadString();
				obj.value = bytes.ReadUInt16();
				obj.hp = bytes.ReadUInt32();
				obj.mp = bytes.ReadUInt32();
				obj.phyatkfloor = bytes.ReadUInt32();
				obj.phyatktop = bytes.ReadUInt32();
				obj.magatkfloor = bytes.ReadUInt32();
				obj.magatktop = bytes.ReadUInt32();
				obj.def = bytes.ReadUInt32();
				obj.hit = bytes.ReadUInt32();
				obj.dod = bytes.ReadUInt32();
				obj.speed = bytes.ReadUInt32();
				obj.des = bytes.ReadString();
				items.Add(obj);
			}
			return true;
		}
	}
}
