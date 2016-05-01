namespace Shapes
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
            this.splitContainerMain = new System.Windows.Forms.SplitContainer();
            this.tabPaneButtons = new System.Windows.Forms.TableLayoutPanel();
            this.btnTriangle = new System.Windows.Forms.Button();
            this.btnRectangle = new System.Windows.Forms.Button();
            this.btnElipse = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.splitContainerInfo = new System.Windows.Forms.SplitContainer();
            this.gridViewInfo = new System.Windows.Forms.DataGridView();
            this.colName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colFactorA = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colFactorB = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colArea = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.colCircuit = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.textBoxDescription = new System.Windows.Forms.RichTextBox();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerMain)).BeginInit();
            this.splitContainerMain.Panel1.SuspendLayout();
            this.splitContainerMain.Panel2.SuspendLayout();
            this.splitContainerMain.SuspendLayout();
            this.tabPaneButtons.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerInfo)).BeginInit();
            this.splitContainerInfo.Panel1.SuspendLayout();
            this.splitContainerInfo.Panel2.SuspendLayout();
            this.splitContainerInfo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewInfo)).BeginInit();
            this.SuspendLayout();
            // 
            // splitContainerMain
            // 
            this.splitContainerMain.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainerMain.Location = new System.Drawing.Point(0, 0);
            this.splitContainerMain.Name = "splitContainerMain";
            // 
            // splitContainerMain.Panel1
            // 
            this.splitContainerMain.Panel1.Controls.Add(this.tabPaneButtons);
            // 
            // splitContainerMain.Panel2
            // 
            this.splitContainerMain.Panel2.Controls.Add(this.splitContainerInfo);
            this.splitContainerMain.Size = new System.Drawing.Size(769, 418);
            this.splitContainerMain.SplitterDistance = 165;
            this.splitContainerMain.TabIndex = 0;
            // 
            // tabPaneButtons
            // 
            this.tabPaneButtons.ColumnCount = 1;
            this.tabPaneButtons.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tabPaneButtons.Controls.Add(this.btnTriangle, 0, 0);
            this.tabPaneButtons.Controls.Add(this.btnRectangle, 0, 1);
            this.tabPaneButtons.Controls.Add(this.btnElipse, 0, 2);
            this.tabPaneButtons.Controls.Add(this.btnDelete, 0, 3);
            this.tabPaneButtons.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabPaneButtons.Location = new System.Drawing.Point(0, 0);
            this.tabPaneButtons.Name = "tabPaneButtons";
            this.tabPaneButtons.RowCount = 4;
            this.tabPaneButtons.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tabPaneButtons.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tabPaneButtons.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tabPaneButtons.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tabPaneButtons.Size = new System.Drawing.Size(165, 418);
            this.tabPaneButtons.TabIndex = 0;
            // 
            // btnTriangle
            // 
            this.btnTriangle.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btnTriangle.Image = ((System.Drawing.Image)(resources.GetObject("btnTriangle.Image")));
            this.btnTriangle.Location = new System.Drawing.Point(3, 3);
            this.btnTriangle.Name = "btnTriangle";
            this.btnTriangle.Size = new System.Drawing.Size(159, 98);
            this.btnTriangle.TabIndex = 0;
            this.btnTriangle.UseVisualStyleBackColor = true;
            this.btnTriangle.Click += new System.EventHandler(this.btnTriangle_Click);
            // 
            // btnRectangle
            // 
            this.btnRectangle.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btnRectangle.Image = ((System.Drawing.Image)(resources.GetObject("btnRectangle.Image")));
            this.btnRectangle.Location = new System.Drawing.Point(3, 107);
            this.btnRectangle.Name = "btnRectangle";
            this.btnRectangle.Size = new System.Drawing.Size(159, 98);
            this.btnRectangle.TabIndex = 1;
            this.btnRectangle.UseVisualStyleBackColor = true;
            this.btnRectangle.Click += new System.EventHandler(this.btnRectangle_Click);
            // 
            // btnElipse
            // 
            this.btnElipse.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btnElipse.Image = ((System.Drawing.Image)(resources.GetObject("btnElipse.Image")));
            this.btnElipse.Location = new System.Drawing.Point(3, 211);
            this.btnElipse.Name = "btnElipse";
            this.btnElipse.Size = new System.Drawing.Size(159, 98);
            this.btnElipse.TabIndex = 2;
            this.btnElipse.UseVisualStyleBackColor = true;
            this.btnElipse.Click += new System.EventHandler(this.btnElipse_Click);
            // 
            // btnDelete
            // 
            this.btnDelete.Dock = System.Windows.Forms.DockStyle.Fill;
            this.btnDelete.Image = ((System.Drawing.Image)(resources.GetObject("btnDelete.Image")));
            this.btnDelete.Location = new System.Drawing.Point(3, 315);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(159, 100);
            this.btnDelete.TabIndex = 3;
            this.btnDelete.UseVisualStyleBackColor = true;
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // splitContainerInfo
            // 
            this.splitContainerInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainerInfo.Location = new System.Drawing.Point(0, 0);
            this.splitContainerInfo.Name = "splitContainerInfo";
            this.splitContainerInfo.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainerInfo.Panel1
            // 
            this.splitContainerInfo.Panel1.Controls.Add(this.gridViewInfo);
            // 
            // splitContainerInfo.Panel2
            // 
            this.splitContainerInfo.Panel2.Controls.Add(this.textBoxDescription);
            this.splitContainerInfo.Size = new System.Drawing.Size(600, 418);
            this.splitContainerInfo.SplitterDistance = 370;
            this.splitContainerInfo.TabIndex = 1;
            // 
            // gridViewInfo
            // 
            this.gridViewInfo.AllowUserToAddRows = false;
            this.gridViewInfo.AllowUserToDeleteRows = false;
            this.gridViewInfo.AllowUserToResizeRows = false;
            this.gridViewInfo.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridViewInfo.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.colName,
            this.colFactorA,
            this.colFactorB,
            this.colArea,
            this.colCircuit});
            this.gridViewInfo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gridViewInfo.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.gridViewInfo.Location = new System.Drawing.Point(0, 0);
            this.gridViewInfo.MultiSelect = false;
            this.gridViewInfo.Name = "gridViewInfo";
            this.gridViewInfo.ReadOnly = true;
            this.gridViewInfo.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gridViewInfo.Size = new System.Drawing.Size(600, 370);
            this.gridViewInfo.TabIndex = 0;
            this.gridViewInfo.SelectionChanged += new System.EventHandler(this.gridViewInfo_SelectionChanged);
            // 
            // colName
            // 
            this.colName.HeaderText = "Nazwa";
            this.colName.Name = "colName";
            this.colName.ReadOnly = true;
            // 
            // colFactorA
            // 
            this.colFactorA.HeaderText = "a";
            this.colFactorA.Name = "colFactorA";
            this.colFactorA.ReadOnly = true;
            // 
            // colFactorB
            // 
            this.colFactorB.HeaderText = "b";
            this.colFactorB.Name = "colFactorB";
            this.colFactorB.ReadOnly = true;
            // 
            // colArea
            // 
            this.colArea.HeaderText = "Pole";
            this.colArea.Name = "colArea";
            this.colArea.ReadOnly = true;
            // 
            // colCircuit
            // 
            this.colCircuit.HeaderText = "Obwód";
            this.colCircuit.Name = "colCircuit";
            this.colCircuit.ReadOnly = true;
            // 
            // textBoxDescription
            // 
            this.textBoxDescription.Dock = System.Windows.Forms.DockStyle.Fill;
            this.textBoxDescription.Location = new System.Drawing.Point(0, 0);
            this.textBoxDescription.Name = "textBoxDescription";
            this.textBoxDescription.Size = new System.Drawing.Size(600, 44);
            this.textBoxDescription.TabIndex = 0;
            this.textBoxDescription.Text = "";
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(769, 418);
            this.Controls.Add(this.splitContainerMain);
            this.Name = "frmMain";
            this.Text = "Krztałty";
            this.Load += new System.EventHandler(this.frmMain_Load);
            this.splitContainerMain.Panel1.ResumeLayout(false);
            this.splitContainerMain.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerMain)).EndInit();
            this.splitContainerMain.ResumeLayout(false);
            this.tabPaneButtons.ResumeLayout(false);
            this.splitContainerInfo.Panel1.ResumeLayout(false);
            this.splitContainerInfo.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerInfo)).EndInit();
            this.splitContainerInfo.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.gridViewInfo)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainerMain;
        private System.Windows.Forms.TableLayoutPanel tabPaneButtons;
        private System.Windows.Forms.Button btnTriangle;
        private System.Windows.Forms.Button btnRectangle;
        private System.Windows.Forms.Button btnElipse;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.DataGridView gridViewInfo;
        private System.Windows.Forms.SplitContainer splitContainerInfo;
        private System.Windows.Forms.RichTextBox textBoxDescription;
        private System.Windows.Forms.DataGridViewTextBoxColumn colName;
        private System.Windows.Forms.DataGridViewTextBoxColumn colFactorA;
        private System.Windows.Forms.DataGridViewTextBoxColumn colFactorB;
        private System.Windows.Forms.DataGridViewTextBoxColumn colArea;
        private System.Windows.Forms.DataGridViewTextBoxColumn colCircuit;
    }
}

