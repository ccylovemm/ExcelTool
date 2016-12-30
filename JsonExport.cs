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

            string json = JsonConvert.SerializeObject(jsonData, Formatting.Indented);
            FileStream file = new FileStream("Out/Config/" + fileName.Split('.')[0] + ".json", FileMode.Create, FileAccess.Write);
            TextWriter writer = new StreamWriter(file);
            writer.Write(json);
            writer.Close();
            file.Close();
        }
    }
}
