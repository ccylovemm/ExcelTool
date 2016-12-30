// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     ParameterCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class ParameterCFG : BaseCFG
	{

		public Dictionary<UInt32, ParameterVo> items;

		private static ParameterCFG _instance = new ParameterCFG();

		public static ParameterCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public ParameterCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, ParameterVo>();
			while(bytes.bytesAvailable)
			{
				ParameterVo obj = new ParameterVo();
				obj.ID = bytes.ReadUInt32();
				obj.value = bytes.ReadString();
				items[obj.ID] = obj;
			}
			return true;
		}
	}
}
