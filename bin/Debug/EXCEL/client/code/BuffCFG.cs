// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     BuffCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class BuffCFG : BaseCFG
	{

		public Dictionary<UInt32, BuffVo> items;

		private static BuffCFG _instance = new BuffCFG();

		public static BuffCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public BuffCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, BuffVo>();
			while(bytes.bytesAvailable)
			{
				BuffVo obj = new BuffVo();
				obj.id = bytes.ReadUInt32();
				obj.buffname = bytes.ReadString();
				obj.group = bytes.ReadUInt8();
				obj.goodtype = bytes.ReadUInt8();
				obj.canceltype = bytes.ReadUInt8();
				obj.effectid = bytes.ReadUInt8();
				obj.effectparams1 = bytes.ReadUInt32();
				obj.effectparams2 = bytes.ReadUInt32();
				obj.effectparams3 = bytes.ReadUInt32();
				obj.triggerbuff = bytes.ReadUInt32();
				obj.maxlasttime = bytes.ReadUInt32();
				obj.maxvalue = bytes.ReadUInt32();
				obj.icon = bytes.ReadUInt32();
				obj.bufftips = bytes.ReadString();
				obj.haseffect = bytes.ReadUInt16();
				obj.effectpos = bytes.ReadUInt8();
				items[obj.id] = obj;
			}
			return true;
		}
	}
}
