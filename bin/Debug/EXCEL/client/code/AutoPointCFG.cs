// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     AutoPointCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class AutoPointCFG : BaseCFG
	{

		public Dictionary<UInt16, AutoPointVo> items;

		private static AutoPointCFG _instance = new AutoPointCFG();

		public static AutoPointCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public AutoPointCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, AutoPointVo>();
			while(bytes.bytesAvailable)
			{
				AutoPointVo obj = new AutoPointVo();
				obj.occu = bytes.ReadUInt16();
				obj.basePoint = bytes.ReadUInt16();
				obj.Stren = bytes.ReadUInt16();
				obj.Agil = bytes.ReadUInt16();
				obj.Intel = bytes.ReadUInt16();
				obj.Vital = bytes.ReadUInt16();
				items[obj.occu] = obj;
			}
			return true;
		}
	}
}
