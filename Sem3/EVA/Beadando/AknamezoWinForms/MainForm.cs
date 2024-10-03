using AknamezoModel;
using Timer = System.Windows.Forms.Timer;

namespace AknamezoWinForms 
{
    public class MineBox : PictureBox
    {
        public Timer timer;
        public Mine model;

        public MineBox(int weight)
        {
            timer = new Timer();
            model = new Mine(weight);
        }
    }

    public partial class MainForm : Form 
    {
        private Game game = new Game(); // Game state
        private Submarine submarineModel = new Submarine(50); // Submarine model
        private List<MineBox> mines = new List<MineBox>();

        public MainForm() 
        {
            InitializeComponent();

            // Starting the game timer
            Timer gameTimer = new Timer();
            gameTimer.Interval = 1000;
            gameTimer.Tick += new EventHandler(UpdateGameState);
            gameTimer.Start();

            // Key down event
            KeyDown += new KeyEventHandler(MoveSubmarine);

            // Initializing mines
            for (int i = 0; i < 3; i++)
            {
                MineBox mine = new MineBox(i * 50 + 10);
                
                // Body setup
                mine.Location = new Point(i * 100 + 100 + mine.Size.Width, 25);
                mine.BackColor = Color.Red;
                mine.Size = new Size(50, 50);

                // Timer setup
                mine.timer.Interval = mine.model.Weight;
                mine.timer.Tick += new EventHandler((sender, e) => MoveMineDown(sender, e, mine));
                mine.timer.Start();

                Controls.Add(mine);
                mines.Add(mine);
             }
        }

        private void UpdateGameState(object? sender, EventArgs e)
        {
            game.Time += 1;

            if (game.Time >= 10)
            {
                foreach (MineBox mine in mines)
                {
                    mine.timer.Stop();
                    MessageBox.Show("Game timer stopped!");
                }
            }
        }

        private void MoveMineDown(object? sender, EventArgs e, MineBox mine)
        {
            int newYPos = mine.Location.Y + 25;
            mine.Location = new Point(mine.Location.X, newYPos);

            if (mine.Location.Y >= ClientSize.Height - 150)
            {
                mine.Dispose();
            }
        }

        private void MoveSubmarine(object? sender, KeyEventArgs e)
        {
            Point submarineLocation = submarine.Location;

            if (e.KeyCode == Keys.W || e.KeyCode == Keys.Up)
            {
                int newYPos = submarineLocation.Y - submarineModel.Speed;

                if (100 <= newYPos)
                {
                    submarine.Location = new Point(submarineLocation.X, newYPos);
                }
            }
            else if (e.KeyCode == Keys.A)
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
            else if (e.KeyCode == Keys.S || e.KeyCode == Keys.Down)
            {
                int newYPos = submarineLocation.Y + submarineModel.Speed;

                if (ClientSize.Height >= newYPos + submarine.Height)
                {
                    submarine.Location = new Point(submarineLocation.X, newYPos);
                }
            }
        }
    }
}
