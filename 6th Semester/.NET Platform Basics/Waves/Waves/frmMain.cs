using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Waves
{
    public partial class frmMain : Form
    {
        delegate void SetTextCallback(string text);
        public frmMain()
        {
            InitializeComponent();
        }

        Task _projection;
        CancellationTokenSource _cancellationTokenSource;

        private void frmMain_Load(object sender, EventArgs e)
        {
            _cancellationTokenSource = new CancellationTokenSource();
            _projection = Task.Run(()=>StartWaves(),_cancellationTokenSource.Token);
        }

        private void StartWaves()
        {
            double t = 0.0;
            double i = 0;
            while (true)
            {
                long tick = DateTime.Now.Ticks;
                RefreshWaves(t);
                long tock = DateTime.Now.Ticks;
                TimeSpan timeElapsedOnRefresh = new TimeSpan(tock - tick);
                i++;
                SetText(i.ToString());
                t += timeElapsedOnRefresh.TotalSeconds;
            }
        }

        private void RefreshWaves(double t)
        {
            Bitmap image = new Bitmap(pictureBoxMain.Width, pictureBoxMain.Height);
            for (int x = 0; x < image.Width; x++)
            {
                for (int y = 0; y < image.Height; y++)
                {
                    int r = (int)((0.5+0.5*Math.Sin(((Math.Pow(x-pictureBoxMain.Width/2,2)+Math.Pow(y-pictureBoxMain.Height/2,2))/1000)+t))*255);
                    Color fadedRed = Color.FromArgb(r, 0, 0);
                    image.SetPixel(x, y,fadedRed);
                }
            }
            pictureBoxMain.Image = image;
        }

        private void frmMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            _cancellationTokenSource.Cancel();
        }

        private void SetText(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (InvokeRequired)
            {
                SetTextCallback callback = new SetTextCallback(SetText);
                Invoke(callback, new object[] { text });
            }
            else
            {
                Text = text;
            }
        }
    }
}
