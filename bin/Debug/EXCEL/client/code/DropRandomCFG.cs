// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     DropRandomCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class DropRandomCFG : BaseCFG
	{

		public Dictionary<UInt16, DropRandomVo> items;

		private static DropRandomCFG _instance = new DropRandomCFG();

		public static DropRandomCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public DropRandomCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt16, DropRandomVo>();
			while(bytes.bytesAvailable)
			{
				DropRandomVo obj = new DropRandomVo();
				obj.calss = bytes.ReadUInt16();
				obj.mir1 = bytes.ReadUInt16();
				obj.mir2 = bytes.ReadUInt16();
				obj.mir3 = bytes.ReadUInt16();
				obj.poweruprat = bytes.ReadUInt8();
				obj.propaddrat = bytes.ReadUInt8();
				obj.lucky = bytes.ReadUInt8();
				items[obj.calss] = obj;
			}
			return true;
		}
	}
}
