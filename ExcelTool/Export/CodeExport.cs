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

        static public void Export(string fileName, DataTable sheet)
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
                field.dataDesc = descRow[column].ToString() + (field.dataForm.ToLower().Contains("key") ? "  (key)" : "");
                if (!string.IsNullOrEmpty(field.dataName) && !field.dataName.ToLower().Contains("column"))
                {
                    dataFiled.Add(field);
                }
            }
            ExportXmlFile(fileName, dataFiled);
            ExportJsonFile(fileName, dataFiled);
        }

        static private void ExportJsonFile(string fileName, List<FieldDef> dataFiled)
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
            stringBuilder.AppendFormat("public class {0}\r\n{{", fileName + "Vo");
            stringBuilder.AppendLine();
            foreach (FieldDef field in dataFiled)
            {
                stringBuilder.AppendFormat("\tpublic {0} {1}; // {2}", field.dataType, field.dataName, field.dataDesc);
                stringBuilder.AppendLine();
            }
            stringBuilder.AppendLine("}");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("public class {0} : BaseCFG\r\n{{", fileName + "CFG");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("\tstatic public Dictionary<string , {0}> items;", fileName + "Vo");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("\tstatic private {0} _instance = new {0}();", fileName + "CFG");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("\tstatic public {0} Instance" , fileName + "CFG");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\t{");
            stringBuilder.AppendLine("\t\tget");
            stringBuilder.AppendLine("\t\t{");
            stringBuilder.AppendLine("\t\t\treturn _instance;");
            stringBuilder.AppendLine("\t\t}");
            stringBuilder.AppendLine("\t}");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\toverride public void Read(string str)");
            stringBuilder.AppendLine("\t{");
            stringBuilder.AppendFormat("\t\titems = Json.Deserialize(str) as Dictionary<string, {0}>;", fileName + "Vo");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\t}");
            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            string path = "Out/JsonCode/";

            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }

            FileStream stream = new FileStream(path + Path.GetFileNameWithoutExtension(fileName) + "Config.cs", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(stream);
            writer.Write(stringBuilder.ToString());
            writer.Close();
            stream.Close();
        }

        static private void ExportXmlFile(string fileName, List<FieldDef> dataFiled)
        {
            fileName = Path.GetFileNameWithoutExtension(fileName);

            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine("// Auto Generated Code By ExcelTool");
            stringBuilder.AppendLine("// Copyright(c) Cao ChunYang  All rights reserved.");
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("using System;");
            stringBuilder.AppendLine("using System.Xml;");
            stringBuilder.AppendLine("using System.Collections.Generic;");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("public class {0}\r\n{{", fileName + "Vo");
            stringBuilder.AppendLine();
            foreach (FieldDef field in dataFiled)
            {
                stringBuilder.AppendFormat("\tpublic {0} {1}; // {2}", field.dataType, field.dataName, field.dataDesc);
                stringBuilder.AppendLine();
            }
            stringBuilder.AppendLine("}");
            stringBuilder.AppendLine();

            stringBuilder.AppendFormat("public class {0} : BaseCFG\r\n{{", fileName + "CFG");
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("\tstatic public Dictionary<string , {0}> items;", fileName + "Vo");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("\tstatic private {0} _instance = new {0}();", fileName + "CFG");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine();
            stringBuilder.AppendFormat("\tstatic public {0} Instance", fileName + "CFG");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\t{");
            stringBuilder.AppendLine("\t\tget");
            stringBuilder.AppendLine("\t\t{");
            stringBuilder.AppendLine("\t\t\treturn _instance;");
            stringBuilder.AppendLine("\t\t}");
            stringBuilder.AppendLine("\t}");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\toverride public void Read(XmlDocument xml)");
            stringBuilder.AppendLine("\t{");
            stringBuilder.AppendLine("\t\tforeach(XmlNode point in xml.ChildNodes)");
            stringBuilder.AppendLine("\t\t{");
            stringBuilder.AppendFormat("\t\t\t{0} vo = new {0}();", fileName + "Vo");
            foreach (FieldDef field in dataFiled)
            {
                stringBuilder.AppendLine();
                if (field.dataType.ToLower() == "string")
                {
                    stringBuilder.AppendFormat("\t\t\tvo.{0} = point.Attributes[\"{0}\"].Value;", field.dataName);
                }
                else
                {
                    stringBuilder.AppendFormat("\t\t\tvo.{0} = {1}.Parse(point.Attributes[\"{0}\"].Value);", field.dataName, field.dataType);
                }
            }
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\t\t}");
            stringBuilder.AppendLine("\t}");
            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            string path = "Out/XmlCode/";

            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }

            FileStream stream = new FileStream(path + Path.GetFileNameWithoutExtension(fileName) + "Config.cs", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(stream);
            writer.Write(stringBuilder.ToString());
            writer.Close();
            stream.Close();
        }    

        static public void ExportInitFile(string[] files)
        {
            if (files.Length == 0) return;
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine("// Auto Generated Code By ExcelTool");
            stringBuilder.AppendLine("// Copyright(c) Cao ChunYang  All rights reserved.");
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine("using System;");
            stringBuilder.AppendLine("using System.Collections.Generic;");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("public class CfgFiles\r{");
            stringBuilder.AppendLine("\tstatic public Dictionary<String , BaseCFG> files = new Dictionary<String,BaseCFG>();");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("\tstatic public void Init()");
            stringBuilder.AppendLine("\t{");
            for (int i = 0; i < files.Length; i++)
            {
                string fileName = Path.GetFileNameWithoutExtension(files[i]);
                stringBuilder.AppendFormat("\t\tfiles[\"{0}\"] = {0}CFG.Instance;", fileName);
                stringBuilder.AppendLine();
            }
            stringBuilder.AppendLine("\t}");
            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            ExportXmlBaseFile(stringBuilder);
            ExportJsonBaseFile(stringBuilder);
        }

        static private void ExportXmlBaseFile(StringBuilder cfgStringBuilder)
        {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine("// Auto Generated Code By ExcelTool");
            stringBuilder.AppendLine("// Copyright(c) Cao ChunYang  All rights reserved.");
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("using System;");
            stringBuilder.AppendLine("using System.Xml;");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("public abstract class BaseCFG\r\n{");
            stringBuilder.AppendLine("\tpublic abstract void Read(XmlDocument xml);");
            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            string path = "Out/XmlCode/";

            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }

            FileStream stream = new FileStream(path + "BaseCFG.cs", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(stream);
            writer.Write(stringBuilder.ToString());
            writer.Close();
            stream.Close();

            FileStream cfgStream = new FileStream(path + "CfgFiles.cs", FileMode.Create, FileAccess.Write);
            TextWriter cfgWriter = new StreamWriter(cfgStream);
            cfgWriter.Write(cfgStringBuilder.ToString());
            cfgWriter.Close();
            cfgStream.Close();
        }

        static private void ExportJsonBaseFile(StringBuilder cfgStringBuilder)
        {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine("// Auto Generated Code By ExcelTool");
            stringBuilder.AppendLine("// Copyright(c) Cao ChunYang  All rights reserved.");
            stringBuilder.AppendLine("//************************************************************");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("using System;");
            stringBuilder.AppendLine();
            stringBuilder.AppendLine("public abstract class BaseCFG\r\n{");
            stringBuilder.AppendLine("\tpublic abstract void Read(string str);");
            stringBuilder.Append('}');
            stringBuilder.AppendLine();

            string path = "Out/JsonCode/";

            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }

            FileStream stream = new FileStream(path + "BaseCFG.cs", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(stream);
            writer.Write(stringBuilder.ToString());
            writer.Close();
            stream.Close();

            FileStream cfgStream = new FileStream(path + "CfgFiles.cs", FileMode.Create, FileAccess.Write);
            TextWriter cfgWriter = new StreamWriter(cfgStream);
            cfgWriter.Write(cfgStringBuilder.ToString());
            cfgWriter.Close();
            cfgStream.Close();
        }
    }
}
