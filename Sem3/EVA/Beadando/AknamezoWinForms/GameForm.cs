using AknamezoModel;
using Timer = System.Windows.Forms.Timer;

namespace AknamezoWinForms 
{
    public partial class GameForm : Form
    {
        private GameState gameState; // Game state

        public GameForm()
        {
            InitializeComponent();

            // Initializing model
            Submarine playerModel = new Submarine(player.Location.X, player.Location.Y, 25);
            gameState = new GameState(playerModel);

            // Subscribing buttons event handler methods
            startButton.Click += startButton_Click;
            stopButton.Click += stopButton_Click;
            saveButton.Click += saveButton_Click;
            loadButton.Click += loadButton_Click;

            // Subsribing the game timer to the tick event
            gameTimer.Tick += gameTimer_Tick;
            gameTimer.Interval = 1000;

            // Subscribing the game loop timer to the tick event
            gameLoopTimer.Tick += gameLoopTimer_Tick;
            // I set the gameLoop to update every 16 seconds because that's roughly 60 fps (1000 / 60)
            gameLoopTimer.Interval = 16;

            // Subscribing to keypress event
            KeyPreview = true;
            KeyDown += MovePlayer;
        }

        // Main game loop. (60 fps)
        // Game loop timer tick event handler.
        private void gameLoopTimer_Tick(object? sender, EventArgs e)
        {
            // Drawing the player
            player.Location = new Point(gameState.Player.X, gameState.Player.Y);
        }

        // Game timer tick event handler.
        private void gameTimer_Tick(object? sender, EventArgs e)
        {
            gameState.ElpasedTime++;
            gameTimeLabel.Text = $"Game time: {gameState.ElpasedTime}";
        }

        // Start button event handler.
        // Starts the game loop (by starting the game timer).
        private void startButton_Click(object? sender, EventArgs e)
        {
            gameTimer.Start();
            gameLoopTimer.Start();
        }

        // Stop button event handler.
        // Stops the game loop (by stopping the game timer).
        private void stopButton_Click(object? sender, EventArgs e)
        {
            gameTimer.Stop();
            gameLoopTimer.Stop();
        }

        // Save button event handler.
        // Saves the current game state to a json file.
        private void saveButton_Click(object? sender, EventArgs e)
        {
            throw new NotImplementedException();
        }

        // Load button event handler.
        // Loads a game from a json file.
        private void loadButton_Click(object? sender, EventArgs e)
        {
            throw new NotImplementedException();
        }

        private void MovePlayer(object? sender, KeyEventArgs e) 
        {
            if (e.KeyCode == Keys.D || e.KeyCode == Keys.Right) gameState.Player.MoveRight();
        }
    }
}
