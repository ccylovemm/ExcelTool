using System;
using System.IO;
using System.Data;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using Newtonsoft.Json;

namespace ExcelTool
{
    class DataExport
    {
        static public void Export(string fileName, DataTable sheet)
        {
            XmlDocument xmlDoc = new XmlDocument();
            XmlElement root = xmlDoc.CreateElement("Root");

            List<Dictionary<string, string>> jsonData = new List<Dictionary<string, string>>();

            for (int i = ExcelDefine.DataContent; i < sheet.Rows.Count; i++)
            {
                XmlElement point = xmlDoc.CreateElement("Item");
                Dictionary<string, string> data = new Dictionary<string, string>();

                for (int c = 0; c < sheet.Columns.Count; c ++ )
                {
                    if (sheet.Rows[2][sheet.Columns[c]].ToString().ToLower() == "skip") continue;
                    string filed = sheet.Columns[c].ToString().Replace(" ", "");
                    if (!string.IsNullOrEmpty(filed))
                    {
                        string value = sheet.Rows[i][sheet.Columns[c]].ToString();
                        data.Add(filed, value);
                        point.SetAttribute(filed , value);
                    }
                }
                jsonData.Add(data);
                root.AppendChild(point);
            }
            xmlDoc.AppendChild(root);

            string path = "Out/JsonData/";

            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }
            string json = JsonConvert.SerializeObject(jsonData, Newtonsoft.Json.Formatting.None);
            FileStream stream = new FileStream(path + Path.GetFileNameWithoutExtension(fileName) + ".json", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(stream);
            writer.Write(json);
            writer.Close();
            stream.Close();         

            string xmlPath = "Out/XmlData/";

            if (!Directory.Exists(xmlPath))
            {
                Directory.CreateDirectory(xmlPath);
            }

            xmlDoc.Save(xmlPath + Path.GetFileNameWithoutExtension(fileName) + ".xml");
        }
    }
}
