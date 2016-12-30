// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！
// 文件名：     MessageCFG.cs
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


namespace GameCFG
{
	using System;
	using System.Collections.Generic;
	using System.IO;

	public sealed class MessageCFG : BaseCFG
	{

		public Dictionary<UInt32, MessageVo> items;

		private static MessageCFG _instance = new MessageCFG();

		public static MessageCFG Instance
		{
			get
			{
				return _instance;
			}
		}

		public MessageCFG()
		{
			if(_instance != null)
			{
				return;
			}
		}

		public override bool LoadData(FileReadStream bytes)
		{
			items = new Dictionary<UInt32, MessageVo>();
			while(bytes.bytesAvailable)
			{
				MessageVo obj = new MessageVo();
				obj.ID = bytes.ReadUInt32();
				obj.Name = bytes.ReadString();
				items[obj.ID] = obj;
			}
			return true;
		}
	}
}
