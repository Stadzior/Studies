using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TextProcessing
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            try
            {
                PopulateFilesList(Directory.GetCurrentDirectory());
            }
            catch (Exception ex)
            {
                DisplayError(ex);
            }

        }

        private void PopulateFilesList(string workingDir)
        {
                              
            List<string> textFiles = Directory.GetFiles(workingDir, "*.txt", SearchOption.TopDirectoryOnly)
                .Select(path => Path.GetFileName(path))
                .ToList();
            foreach (string file in textFiles)
            {
                listBoxFiles.Items.Add(file);
            }
        }

        private void listBoxFiles_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                textBoxSource.Text = File.ReadAllText(Directory.GetCurrentDirectory() + "\\" + listBoxFiles.SelectedItem.ToString());
                textBoxResult.Text = TransformText(textBoxSource.Text); ;
            }
            catch (Exception ex)
            {
                DisplayError(ex);               
            }
        }

        private string TransformText(string text)
        {
            StringBuilder resultText = new StringBuilder();
            List<string> words = text.Split(' ').ToList();
            for (int i = 0; i < words.Count; i++)
            {
                words[i] = TransformWord(words[i]);
                resultText.Append(words[i] + " ");
            }

            resultText.Remove(resultText.Length - 1, 1);
            return resultText.ToString();
        }

        private string TransformWord(string word)
        {
            string transformedWord = word;

            if (word.ToLower().StartsWith("do"))
            {
                transformedWord = transformedWord.ToUpper();
            }

            if (word.ToLower().EndsWith("us")){
                transformedWord = transformedWord.First().ToString().ToUpper() + transformedWord.Substring(1).ToLower();
            }

            int counter = word.ToList().Count(x => x == 's');

            if (counter%2!=0)
            {
                List<char> reversedCharList = transformedWord.ToCharArray().ToList();
                reversedCharList.Reverse();
                transformedWord = string.Join("",reversedCharList.ToArray());
            }

            return transformedWord;

        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                string fileNameWithExtension = listBoxFiles.SelectedItem.ToString();
                string outputFilePath = Directory.GetCurrentDirectory() + "\\" + Path.GetFileNameWithoutExtension(fileNameWithExtension) + "_out" + Path.GetExtension(fileNameWithExtension);
                File.AppendAllText(outputFilePath, textBoxResult.Text);
                DialogResult shouldOpenTheFile = MessageBox.Show("Poprawnie zapisano plik. Czy otworzyć?", "Sukces!", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (shouldOpenTheFile == DialogResult.Yes){
                    Process.Start(outputFilePath);
                }
            }
            catch (Exception ex)
            {
                DisplayError(ex);
            }
        }

        private void DisplayError(Exception ex)
        {
            MessageBox.Show(ex.StackTrace.ToString(), ex.Message, MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
    }
}
