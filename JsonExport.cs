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
            Dictionary<string , Dictionary<string, string>> client_jsonData = new Dictionary<string, Dictionary<string, string>>();
            Dictionary<string , Dictionary<string, string>> server_jsonData = new Dictionary<string, Dictionary<string, string>>();

            int firstDataRow = 5;
            for (int i = firstDataRow; i < sheet.Rows.Count; i++)
            {
                DataRow row = sheet.Rows[i];
                var clientRowData = new Dictionary<string, string>();
                var serverRowData = new Dictionary<string, string>();
                var key = "";
                foreach (DataColumn column in sheet.Columns)
                {
                    string value = row[column].ToString();
                    string fieldName = column.ToString();

                    if (!string.IsNullOrEmpty(fieldName) && !fieldName.ToLower().Contains("column"))
                    {
                       string dataForm = sheet.Rows[2][column].ToString();
                        if (dataForm.ToLower().Contains("key"))
                        {
                            clientRowData.Add(fieldName , value);
                            serverRowData.Add(fieldName, value);
                            key += value;
                        }
                        else
                        {
                            if (dataForm.ToLower().Contains("client"))
                            {
                                clientRowData.Add(fieldName, value);
                            }
                            if (dataForm.ToLower().Contains("server"))
                            {
                                serverRowData.Add(fieldName, value);
                            }
                        }
                    }
                }
                client_jsonData.Add(key , clientRowData);
                server_jsonData.Add(key, serverRowData);
            }

            if (!Directory.Exists("Out/Client/Config"))
            {
                Directory.CreateDirectory("Out/Client/Config");
            }
            fileName = Path.GetFileNameWithoutExtension(fileName);
            string jsonClient = JsonConvert.SerializeObject(client_jsonData, Formatting.Indented);
            FileStream streamClient = new FileStream("Out/Client/Config/" + fileName + ".json", FileMode.Create, FileAccess.Write);
            TextWriter writerClient = new StreamWriter(streamClient);
            writerClient.Write(jsonClient);
            writerClient.Close();
            streamClient.Close();

            if (!Directory.Exists("Out/Server/Config"))
            {
                Directory.CreateDirectory("Out/Server/Config");
            }
            string jsonServer = JsonConvert.SerializeObject(server_jsonData, Formatting.Indented);
            FileStream streamServer = new FileStream("Out/Server/Config/" + fileName + ".json", FileMode.Create, FileAccess.Write);
            TextWriter writerServer = new StreamWriter(streamServer);
            writerServer.Write(jsonServer);
            writerServer.Close();
            streamServer.Close();

            Console.Write(fileName + ".json\n");
        }
    }
}
