namespace TextProcessing
{
    partial class frmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.splitContainerMain = new System.Windows.Forms.SplitContainer();
            this.splitContainterFiles = new System.Windows.Forms.SplitContainer();
            this.splitContainterTexts = new System.Windows.Forms.SplitContainer();
            this.listBoxFiles = new System.Windows.Forms.ListBox();
            this.textBoxSource = new System.Windows.Forms.RichTextBox();
            this.textBoxResult = new System.Windows.Forms.RichTextBox();
            this.btnSave = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerMain)).BeginInit();
            this.splitContainerMain.Panel1.SuspendLayout();
            this.splitContainerMain.Panel2.SuspendLayout();
            this.splitContainerMain.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainterFiles)).BeginInit();
            this.splitContainterFiles.Panel1.SuspendLayout();
            this.splitContainterFiles.Panel2.SuspendLayout();
            this.splitContainterFiles.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainterTexts)).BeginInit();
            this.splitContainterTexts.Panel1.SuspendLayout();
            this.splitContainterTexts.Panel2.SuspendLayout();
            this.splitContainterTexts.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainerMain
            // 
            this.splitContainerMain.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainerMain.Location = new System.Drawing.Point(0, 0);
            this.splitContainerMain.Name = "splitContainerMain";
            this.splitContainerMain.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainerMain.Panel1
            // 
            this.splitContainerMain.Panel1.Controls.Add(this.splitContainterFiles);
            // 
            // splitContainerMain.Panel2
            // 
            this.splitContainerMain.Panel2.Controls.Add(this.btnSave);
            this.splitContainerMain.Size = new System.Drawing.Size(743, 372);
            this.splitContainerMain.SplitterDistance = 314;
            this.splitContainerMain.TabIndex = 0;
            // 
            // splitContainterFiles
            // 
            this.splitContainterFiles.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainterFiles.Location = new System.Drawing.Point(0, 0);
            this.splitContainterFiles.Name = "splitContainterFiles";
            // 
            // splitContainterFiles.Panel1
            // 
            this.splitContainterFiles.Panel1.Controls.Add(this.listBoxFiles);
            // 
            // splitContainterFiles.Panel2
            // 
            this.splitContainterFiles.Panel2.Controls.Add(this.splitContainterTexts);
            this.splitContainterFiles.Size = new System.Drawing.Size(743, 314);
            this.splitContainterFiles.SplitterDistance = 247;
            this.splitContainterFiles.TabIndex = 0;
            // 
            // splitContainterTexts
            // 
            this.splitContainterTexts.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainterTexts.Location = new System.Drawing.Point(0, 0);
            this.splitContainterTexts.Name = "splitContainterTexts";
            // 
            // splitContainterTexts.Panel1
            // 
            this.splitContainterTexts.Panel1.Controls.Add(this.textBoxSource);
            // 
            // splitContainterTexts.Panel2
            // 
            this.splitContainterTexts.Panel2.Controls.Add(this.textBoxResult);
            this.splitContainterTexts.Size = new System.Drawing.Size(492, 314);
            this.splitContainterTexts.SplitterDistance = 250;
            this.splitContainterTexts.TabIndex = 0;
            // 
            // listBoxFiles
            // 
            this.listBoxFiles.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listBoxFiles.FormattingEnabled = true;
            this.listBoxFiles.Location = new System.Drawing.Point(0, 0);
            this.listBoxFiles.Name = "listBoxFiles";
            this.listBoxFiles.Size = new System.Drawing.Size(247, 314);
            this.listBoxFiles.TabIndex = 0;
            this.listBoxFiles.SelectedIndexChanged += new System.EventHandler(this.listBoxFiles_SelectedIndexChanged);
            // 
            // textBoxSource
            // 
            this.textBoxSource.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBoxSource.Location = new System.Drawing.Point(0, 0);
            this.textBoxSource.Name = "textBoxSource";
            this.textBoxSource.Size = new System.Drawing.Size(250, 314);
            this.textBoxSource.TabIndex = 0;
            this.textBoxSource.Text = "";
            // 
            // textBoxResult
            // 
            this.textBoxResult.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBoxResult.Location = new System.Drawing.Point(0, 0);
            this.textBoxResult.Name = "textBoxResult";
            this.textBoxResult.Size = new System.Drawing.Size(238, 314);
            this.textBoxResult.TabIndex = 0;
            this.textBoxResult.Text = "";
            // 
            // btnSave
            // 
            this.btnSave.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btnSave.Location = new System.Drawing.Point(0, 0);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(743, 54);
            this.btnSave.TabIndex = 0;
            this.btnSave.Text = "Zapisz";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(743, 372);
            this.Controls.Add(this.splitContainerMain);
            this.Name = "frmMain";
            this.Text = "Zamiana tekstu";
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.splitContainerMain.Panel1.ResumeLayout(false);
            this.splitContainerMain.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerMain)).EndInit();
            this.splitContainerMain.ResumeLayout(false);
            this.splitContainterFiles.Panel1.ResumeLayout(false);
            this.splitContainterFiles.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainterFiles)).EndInit();
            this.splitContainterFiles.ResumeLayout(false);
            this.splitContainterTexts.Panel1.ResumeLayout(false);
            this.splitContainterTexts.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainterTexts)).EndInit();
            this.splitContainterTexts.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainerMain;
        private System.Windows.Forms.SplitContainer splitContainterFiles;
        private System.Windows.Forms.ListBox listBoxFiles;
        private System.Windows.Forms.SplitContainer splitContainterTexts;
        private System.Windows.Forms.RichTextBox textBoxSource;
        private System.Windows.Forms.RichTextBox textBoxResult;
        private System.Windows.Forms.Button btnSave;
    }
}

