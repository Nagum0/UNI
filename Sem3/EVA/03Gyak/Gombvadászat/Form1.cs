namespace Gombvadászat
{
    public partial class Form1 : Form
    {
        private int points = 0;
        private Random generator = new Random();
        private DateTime startTime = new DateTime();

        public Form1()
        {
            InitializeComponent();
            timer1.Interval = 1000;
        }

        private void pushMe_ButtonClicked(object sender, EventArgs e)
        {
            int x = ClientSize.Width - pushButton.Width;
            int y = ClientSize.Height - pushButton.Height - statusStrip.Height;
            pushButton.Location = new Point(generator.Next(x), generator.Next(y));

            if (!timer1.Enabled)
            {
                startTime = DateTime.Now;
                timer1.Start();
            }
            else
            {
                ++points;
            }

            UpdateStatusBar(sender, e);
        }

        private void UpdateStatusBar(object sender, EventArgs e)
        {
            double elapsedSeconds = (DateTime.Now - startTime).TotalSeconds;
            statusLabel.Text = $"Points {points} | Elapsed time: {elapsedSeconds:F0} sec";
        }

        private void GameClosing(object sender, FormClosingEventArgs e)
        {
            if (e.CloseReason == CloseReason.UserClosing && timer1.Enabled)
            {
                double elapsedSeconds = (DateTime.Now - startTime).TotalSeconds;
                double pushPerSeconds = points / elapsedSeconds;
                MessageBox.Show($"Pushes per seconds: {pushPerSeconds:F2}", 
                    "Results", 
                    MessageBoxButtons.OK, 
                    MessageBoxIcon.Information
                );
            }
        }
    }
}
