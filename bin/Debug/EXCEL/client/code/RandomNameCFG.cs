// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     RandomNameCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class RandomNameCFG : BaseCFG
	{

		public  List<RandomNameVo> items;

		private static RandomNameCFG _instance = new RandomNameCFG();

		public static RandomNameCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public RandomNameCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new List<RandomNameVo>();
			while(bytes.bytesAvailable)
			{
				RandomNameVo obj = new RandomNameVo();
				obj.Type = bytes.ReadUInt32();
				obj.NameStr = bytes.ReadString();
				items.Add(obj);
			}
			return true;
		}
	}
}
