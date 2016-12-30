// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     TrapCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class TrapCFG : BaseCFG
	{

		public Dictionary<UInt32, TrapVo> items;

		private static TrapCFG _instance = new TrapCFG();

		public static TrapCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public TrapCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, TrapVo>();
			while(bytes.bytesAvailable)
			{
				TrapVo obj = new TrapVo();
				obj.id = bytes.ReadUInt32();
				obj.type = bytes.ReadUInt8();
				obj.shape = bytes.ReadUInt8();
				obj.radius1 = bytes.ReadFloat();
				obj.radius2 = bytes.ReadFloat();
				obj.intervalTime = bytes.ReadUInt32();
				obj.directDmg = bytes.ReadUInt32();
				obj.buffid1 = bytes.ReadUInt16();
				obj.targetFlag1 = bytes.ReadUInt16();
				obj.buffid2 = bytes.ReadUInt16();
				obj.targetFlag2 = bytes.ReadUInt16();
				obj.buffid3 = bytes.ReadUInt16();
				obj.targetFlag3 = bytes.ReadUInt16();
				obj.maxTargetNum = bytes.ReadUInt32();
				obj.prevLastTime = bytes.ReadUInt32();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
