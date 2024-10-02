using AknamezoModel;

namespace AknamezoWinForms 
{
    public partial class MainForm : Form 
    {
        // Initialize submarine model
        private Submarine submarineModel = new Submarine(10);
        // Initializing a mine model
        private Mine mineModel = new Mine(25);

        public MainForm() 
        {
            InitializeComponent();

            // Key down event
            KeyDown += new KeyEventHandler(MoveSubmarine);

            // Setting up ship1
            mine1Timer.Tick += new EventHandler(MoveMineDown);
            mine1Timer.Interval = 200;
            mine1Timer.Start();
        }

        private void MoveMineDown(object? sender, EventArgs e)
        {
            int newYPos = mine1.Location.Y + mineModel.Speed;

            if (ClientSize.Height < newYPos + mine1.Height)
            {
                mine1.Dispose();
            }
            else
            {
                mine1.Location = new Point(mine1.Location.X, newYPos);
            }

            if (submarine.Bounds.IntersectsWith(mine1.Bounds))
            {
                mine1Timer.Stop();
                MessageBox.Show("YOU DIED");
            } 
        }

        private void MoveSubmarine(object? sender, KeyEventArgs e)
        {
            // Get current submarine position
            Point submarineLocation = submarine.Location;

            if (e.KeyCode == Keys.A)
            {
                int newXPos = submarineLocation.X - submarineModel.Speed;

                if (newXPos >= 0)
                {
                    submarine.Location = new Point(newXPos, submarineLocation.Y);
                }
            }
            else if (e.KeyCode == Keys.D)
            {
                int newXPos = submarineLocation.X + submarineModel.Speed;

                if (newXPos + submarine.Width <= ClientSize.Width)
                {
                    submarine.Location = new Point(newXPos, submarineLocation.Y);
                }
            }
        }
    }
}
