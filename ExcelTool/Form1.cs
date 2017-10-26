using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using Excel;

namespace ExcelTool
{
    public partial class Form1 : Form
    {
        private string filePath = "";

        public Form1()
        {
            InitializeComponent();

            listBox.Items.Add("///////////////////////////////////");
            listBox.Items.Add("Excel表格式");
            listBox.Items.Add("///////////////////////////////////");
            listBox.Items.Add("属性名称  id   type  num   desc");
            listBox.Items.Add("属性描述 序号  类型  数量  描述");
            listBox.Items.Add("属性类型 uint  int   uint string");
            listBox.Items.Add("关键键值  key        key        ");
            listBox.Items.Add("  数据    1     1     5    物品1");
            listBox.Items.Add("  数据    2     1     5    物品2");
            listBox.Items.Add("  数据    3     1    10    物品3");
            listBox.Items.Add("  数据    4     2    10    物品4");
            listBox.Items.Add("  数据    5     2    10    物品5");
            listBox.Items.Add("结果会自动生成(id+num)组成的唯一key方便查找");
            listBox.Items.Add("///////////////////////////////////");
            listBox.Items.Add("");
            listBox.Items.Add("");
        }

        private void ImportBtn_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog dilog = new FolderBrowserDialog();
            dilog.Description = "请选择文件夹";
            if (dilog.ShowDialog() == DialogResult.OK)
            {
                filePath = dilog.SelectedPath;
                FilesPath.Text = dilog.SelectedPath;
                listBox.Items.Add("导入文件夹 " + dilog.SelectedPath);
                listBox.SelectedIndex = listBox.Items.Count - 1;
            }
        }

        private void ExportBtn_Click(object sender, EventArgs e)
        {
            filePath = "./Excel/";
            if (filePath == "") return;
            string[] files = Directory.GetFiles(filePath, "*.xlsx");
            for (int i = 0; i < files.Length; i++)
            {
                FileStream excelFile = File.Open(files[i], FileMode.Open, FileAccess.Read);
                IExcelDataReader excelReader = ExcelReaderFactory.CreateOpenXmlReader(excelFile);
                excelReader.IsFirstRowAsColumnNames = true;

                DataSet book = excelReader.AsDataSet();
                DataTable sheet = book.Tables[0];

                DataExport.Export(files[i], sheet);
                CodeExport.Export(files[i], sheet);
                excelFile.Close();
                listBox.Items.Add(files[i]);
                listBox.SelectedIndex = listBox.Items.Count - 1;
            }
            CodeExport.ExportInitFile(files);
            listBox.Items.Add("导出完成" + files.Length);
            listBox.SelectedIndex = listBox.Items.Count - 1;
        }
    }
}
