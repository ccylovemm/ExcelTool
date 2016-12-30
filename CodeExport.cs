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
                field.dataDesc = descRow[column].ToString();
                field.dataForm = formRow[column].ToString();
                dataFiled.Add(field);
            }

            ExportVo(fileName , dataFiled);
            ExportConfig(fileName, dataFiled);
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
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("public class {0}\r\n{{", fileName + "Config");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("\tpublic Dictionary<string , {0}> items;", fileName + "Vo");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\tpublic void Read()");
            stringBuilder.AppendLine("\t{");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("\t\tstring json = ResourceManager.ReadText(\"{0}\");", fileName + ".json");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("\t\titems = Json.Deserialize(jsont) as Dictionary<string, {0}>;", fileName + "Vo");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\t}");
            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            if (!Directory.Exists("Out/Code"))
            {
                Directory.CreateDirectory("Out/Code");
            }
            FileStream stream = new FileStream("Out/Code/" + fileName + "Config.cs", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(stream);
            writer.Write(stringBuilder.ToString());
            writer.Close();
            stream.Close();
            Console.Write(fileName + "Config.cs\n");
        }

        static private void ExportVo(string fileName , List<FieldDef> dataFiled)
        {
            fileName = Path.GetFileNameWithoutExtension(fileName);
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine("// Auto Generated Code By ExcelTool");
            stringBuilder.AppendLine("// Copyright(c) Cao ChunYang  All rights reserved.");
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("public class {0}\r\n{{", fileName);
            stringBuilder.AppendLine();
            stringBuilder.AppendLine();

            foreach (FieldDef field in dataFiled)
            {
                stringBuilder.AppendFormat("\tpublic {0} {1}; // {2}", field.dataType, field.dataName, field.dataDesc);
                stringBuilder.AppendLine();
            }

            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            if (!Directory.Exists("Out/Code"))
            {
                Directory.CreateDirectory("Out/Code");
            }
         
            FileStream stream = new FileStream("Out/Code/" + fileName + "Vo.cs", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(stream);
            writer.Write(stringBuilder.ToString());
            writer.Close();
            stream.Close();
            Console.Write(fileName + "Vo.cs\n");
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
            stringBuilder.AppendLine("public class CfgFiles\r\n{{");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\tpublic void Init()");
            stringBuilder.AppendLine("\t{");
            for (int i = 0; i < files.Length; i ++)
            {
                string fileName = Path.GetFileNameWithoutExtension(files[i]);
                stringBuilder.AppendFormat("\t\t{0}Config.Read();\r\n{{", fileName);
            }
            stringBuilder.AppendLine("\t}");
            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            if (!Directory.Exists("Out/Code"))
            {
                Directory.CreateDirectory("Out/Code");
            }

            FileStream stream = new FileStream("Out/Code/CfgFiles.cs", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(stream);
            writer.Write(stringBuilder.ToString());
            writer.Close();
            stream.Close();
            Console.Write("CfgFiles.cs\n");
        }
    }
}
