using System;
using System.IO;
using System.Data;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Newtonsoft.Json;

namespace ExcelTool
{
    class JsonExport
    {
        static public void Export(string fileName , DataTable sheet)
        {
            List<Dictionary<string, object>> jsonData = new List<Dictionary<string, object>>();

            int firstDataRow = 5;
            for (int i = firstDataRow; i < sheet.Rows.Count; i++)
            {
                DataRow row = sheet.Rows[i];
                var rowData = new Dictionary<string, object>();
                foreach (DataColumn column in sheet.Columns)
                {
                    object value = row[column];
                    string fieldName = column.ToString();

                    if (!string.IsNullOrEmpty(fieldName))
                        rowData[fieldName] = value;
                }

                jsonData.Add(rowData);
            }
            if (!Directory.Exists("Out/Config"))
            {
                Directory.CreateDirectory("Out/Config");
            }
            fileName = Path.GetFileNameWithoutExtension(fileName);
            string json = JsonConvert.SerializeObject(jsonData, Formatting.Indented);
            FileStream stream = new FileStream("Out/Config/" + fileName + ".json", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(stream);
            writer.Write(json);
            writer.Close();
            stream.Close();
            Console.Write(fileName + ".json\n");
        }
    }
}
