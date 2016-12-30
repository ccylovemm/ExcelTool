// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     OccuCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class OccuCFG : BaseCFG
	{

		public  List<OccuVo> items;

		private static OccuCFG _instance = new OccuCFG();

		public static OccuCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public OccuCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new List<OccuVo>();
			while(bytes.bytesAvailable)
			{
				OccuVo obj = new OccuVo();
				obj.Job = bytes.ReadUInt8();
				obj.JobStage = bytes.ReadUInt8();
				obj.Name = bytes.ReadString();
				items.Add(obj);
			}
			return true;
		}
	}
}
