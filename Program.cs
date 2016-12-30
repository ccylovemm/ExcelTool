using System;
using System.IO;
using System.Data;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Excel;

namespace ExcelTool
{
    class Program
    {
        /// <summary>
        /// 应用程序入口
        /// </summary>
        /// <param name="args">命令行参数</param>
        static void Main(string[] args)
        {
            if (Directory.Exists("Excel"))
            {
                if (Directory.Exists("Out"))
                {
                    DirectoryInfo outFile = new DirectoryInfo("Out");
                    outFile.Delete(true);
                }
                string[] files = Directory.GetFiles("Excel", "*.xlsx");         
                for (int i = 0; i < files.Length; i++)
                {
                    FileStream excelFile = File.Open(files[i], FileMode.Open, FileAccess.Read);
                    IExcelDataReader excelReader = ExcelReaderFactory.CreateOpenXmlReader(excelFile);
                    excelReader.IsFirstRowAsColumnNames = true;

                    DataSet book = excelReader.AsDataSet();
                    DataTable sheet = book.Tables[0];

                    JsonExport.Export(files[i], sheet);
                    CodeExport.Export(files[i], sheet);
                }
                CodeExport.ExportReadFile(files);
                Console.Write("导出结束");
            }
        }
    }
}
