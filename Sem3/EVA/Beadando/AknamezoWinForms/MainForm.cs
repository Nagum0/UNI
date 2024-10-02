using AknamezoModel;

namespace AknamezoWinForms 
{
    public partial class MainForm : Form 
    {
        // Initialize submarine model
        private Submarine submarineModel = new Submarine(10);

        public MainForm() 
        {
            InitializeComponent();

            // Key down event
            KeyDown += new KeyEventHandler(MoveSubmarine);
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
