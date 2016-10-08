using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Shapes
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private ShapeFactory _shapeFactory;
        private Dictionary<string, IShape> _shapes;

        private void frmMain_Load(object sender, EventArgs e)
        {
            _shapeFactory = new ShapeFactory();
            _shapes = new Dictionary<string, IShape>();
        }

        private void btnTriangle_Click(object sender, EventArgs e)
        {
            try
            {
                IShape triangle = (MyTriangle)_shapeFactory.CreateShape(typeof(MyTriangle));
                AddShapeToGridView(triangle);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.StackTrace.ToString(),ex.Message, MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnRectangle_Click(object sender, EventArgs e)
        {
            try
            {
                IShape rectange = (MyRectangle)_shapeFactory.CreateShape(typeof(MyRectangle));
                AddShapeToGridView(rectange);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.StackTrace.ToString(), ex.Message, MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnElipse_Click(object sender, EventArgs e)
        {
            try
            {
                IShape elipse = (MyElipse)_shapeFactory.CreateShape(typeof(MyElipse));
                AddShapeToGridView(elipse);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.StackTrace.ToString(), ex.Message, MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void AddShapeToGridView(IShape shape)
        {
            string shapeName = shape is MyTriangle ? "Trójkąt" : shape is MyRectangle ? "Prostokąt" : "Elipsa";
            shapeName += AddNumberShapeName(shapeName);
            DataGridViewRow gridRow = ConstructShapeGridRow(shapeName, shape);
            _shapes.Add(shapeName, shape);
            gridViewInfo.Rows.Add(gridRow);
            textBoxDescription.Text = shape.ToString();
        }

        private DataGridViewRow ConstructShapeGridRow(string shapeName, IShape shape)
        {
            DataGridViewRow gridRow = new DataGridViewRow();
            gridRow.CreateCells(gridViewInfo);
            gridRow.Cells[0].Value = shapeName;
            gridRow.Cells[1].Value = shape.FactorA;
            gridRow.Cells[2].Value = shape.FactorB;
            gridRow.Cells[3].Value = shape.Area;
            gridRow.Cells[4].Value = shape.Circuit;
            return gridRow;
        }

        private string AddNumberShapeName(string shapeName)
        {
            var filteredShapes = _shapes.Where(x => x.Key.Contains(shapeName)).OrderByDescending(x=>x.Key).ToList();
            int latestShapeNumber = 1;
            if (filteredShapes.Count() > 0)
            {
                string latestShapeName = filteredShapes[0].Key;
                latestShapeNumber = int.Parse(latestShapeName.Replace(shapeName, ""));
            }
            return (latestShapeNumber+1).ToString();
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (gridViewInfo.Rows.Count > 0)
                {
                    string shapeName = gridViewInfo.SelectedRows[0].Cells["colName"].Value.ToString();
                    _shapes.Remove(shapeName);
                    gridViewInfo.Rows.RemoveAt(gridViewInfo.SelectedRows[0].Index);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.StackTrace.ToString(), ex.Message, MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void gridViewInfo_SelectionChanged(object sender, EventArgs e)
        {
            try
            {
                string shapeName = gridViewInfo.SelectedRows[0].Cells["colName"].Value.ToString();
                textBoxDescription.Text = _shapes[shapeName].ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.StackTrace.ToString(), ex.Message, MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }

}
