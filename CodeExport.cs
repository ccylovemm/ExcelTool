using System;
using System.IO;
using System.Data;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ExcelTool
{
    class CodeExport
    {
        struct FieldDef
        {
            public string dataName;
            public string dataType;
            public string dataDesc;
            public string dataForm;
        }

        static public void Export(string fileName , DataTable sheet)
        {
            List<FieldDef> dataFiled = new List<FieldDef>();
            DataRow typeRow = sheet.Rows[0];
            DataRow descRow = sheet.Rows[1];
            DataRow formRow = sheet.Rows[2];

            foreach (DataColumn column in sheet.Columns)
            {
                FieldDef field;
                field.dataName = column.ToString();
                field.dataType = typeRow[column].ToString();
                field.dataForm = formRow[column].ToString();
                field.dataDesc = descRow[column].ToString() + (field.dataForm.ToLower().Contains("key") ? " key" : "");
                if (!string.IsNullOrEmpty(field.dataName) && !field.dataName.ToLower().Contains("column"))
                {
                    dataFiled.Add(field);
                }     
            }
            ExportClientVo(fileName, dataFiled);
            ExportServerVo(fileName , dataFiled);
            Console.Write(fileName + "Vo.cs\n");
            ExportConfig(fileName, dataFiled);
            Console.Write(fileName + "Config.cs\n");
        }

        static private void ExportConfig(string fileName, List<FieldDef> dataFiled)
        {
            fileName = Path.GetFileNameWithoutExtension(fileName);

            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine("// Auto Generated Code By ExcelTool");
            stringBuilder.AppendLine("// Copyright(c) Cao ChunYang  All rights reserved.");
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("using System;");
            stringBuilder.AppendLine("using System.Collections.Generic;");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("public class {0}\r\n{{", fileName + "Config");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("\tstatic public Dictionary<string , {0}> items;", fileName + "Vo");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\tstatic public void Read()");
            stringBuilder.AppendLine("\t{");
            stringBuilder.AppendFormat("\t\tstring json = ResourceManager.ReadText(\"{0}\");", fileName + ".json");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("\t\titems = Json.Deserialize(jsont) as Dictionary<string, {0}>;", fileName + "Vo");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\t}");
            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            if (!Directory.Exists("Out/Client/Code"))
            {
                Directory.CreateDirectory("Out/Client/Code");
            }
            FileStream streamClient = new FileStream("Out/Client/Code/" + fileName + "Config.cs", FileMode.Create, FileAccess.Write);
            TextWriter writerClient = new StreamWriter(streamClient);
            writerClient.Write(stringBuilder.ToString());
            writerClient.Close();
            streamClient.Close();

            if (!Directory.Exists("Out/Server/Code"))
            {
                Directory.CreateDirectory("Out/Server/Code");
            }
            FileStream streamServer = new FileStream("Out/Server/Code/" + fileName + "Config.cs", FileMode.Create, FileAccess.Write);
            TextWriter writerServer = new StreamWriter(streamServer);
            writerServer.Write(stringBuilder.ToString());
            writerServer.Close();
            streamServer.Close();
        }

        static private void ExportClientVo(string fileName , List<FieldDef> dataFiled)
        {
            fileName = Path.GetFileNameWithoutExtension(fileName);
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine("// Auto Generated Code By ExcelTool");
            stringBuilder.AppendLine("// Copyright(c) Cao ChunYang  All rights reserved.");
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("using System;");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("public class {0}\r\n{{", fileName + "Vo");
            stringBuilder.AppendLine();

            foreach (FieldDef field in dataFiled)
            {
                if (field.dataForm.ToLower().Contains("key") || field.dataForm.ToLower().Contains("client"))
                {
                    stringBuilder.AppendFormat("\tpublic {0} {1}; // {2}", field.dataType, field.dataName, field.dataDesc);
                    stringBuilder.AppendLine();
                }
            }

            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            if (!Directory.Exists("Out/Client/Code"))
            {
                Directory.CreateDirectory("Out/Client/Code");
            }

            FileStream stream = new FileStream("Out/Client/Code/" + fileName + "Vo.cs", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(stream);
            writer.Write(stringBuilder.ToString());
            writer.Close();
            stream.Close();
        }

        static private void ExportServerVo(string fileName, List<FieldDef> dataFiled)
        {
            fileName = Path.GetFileNameWithoutExtension(fileName);
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine("// Auto Generated Code By ExcelTool");
            stringBuilder.AppendLine("// Copyright(c) Cao ChunYang  All rights reserved.");
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("using System;");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("public class {0}\r\n{{", fileName + "Vo");
            stringBuilder.AppendLine();

            foreach (FieldDef field in dataFiled)
            {
                if (field.dataForm.ToLower().Contains("key") || field.dataForm.ToLower().Contains("server"))
                {
                    stringBuilder.AppendFormat("\tpublic {0} {1}; // {2}", field.dataType, field.dataName, field.dataDesc);
                    stringBuilder.AppendLine();
                }
            }

            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            if (!Directory.Exists("Out/Server/Code"))
            {
                Directory.CreateDirectory("Out/Server/Code");
            }

            FileStream stream = new FileStream("Out/Server/Code/" + fileName + "Vo.cs", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(stream);
            writer.Write(stringBuilder.ToString());
            writer.Close();
            stream.Close();
        }

        static public void ExportReadFile(string[] files)
        {
            if(files.Length == 0)return;
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine("// Auto Generated Code By ExcelTool");
            stringBuilder.AppendLine("// Copyright(c) Cao ChunYang  All rights reserved.");
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("public class CfgFiles\r{");
            stringBuilder.AppendLine("\tpublic void Init()");
            stringBuilder.AppendLine("\t{");
            for (int i = 0; i < files.Length; i ++)
            {
                string fileName = Path.GetFileNameWithoutExtension(files[i]);
                stringBuilder.AppendFormat("\t\t{0}Config.Read();", fileName);
                stringBuilder.AppendLine();
            }
            stringBuilder.AppendLine("\t}");
            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            if (!Directory.Exists("Out/Client/Code"))
            {
                Directory.CreateDirectory("Out/Client/Code");
            }

            FileStream streamClient = new FileStream("Out/Client/Code/CfgFiles.cs", FileMode.Create, FileAccess.Write);
            TextWriter writerClient = new StreamWriter(streamClient);
            writerClient.Write(stringBuilder.ToString());
            writerClient.Close();
            streamClient.Close();

            if (!Directory.Exists("Out/Server/Code"))
            {
                Directory.CreateDirectory("Out/Server/Code");
            }

            FileStream streamServer = new FileStream("Out/Server/Code/CfgFiles.cs", FileMode.Create, FileAccess.Write);
            TextWriter writerServer = new StreamWriter(streamServer);
            writerServer.Write(stringBuilder.ToString());
            writerServer.Close();
            streamServer.Close();
            Console.Write("CfgFiles.cs\n");
        }
    }
}
