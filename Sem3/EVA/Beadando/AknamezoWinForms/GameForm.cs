/**
 * TODOs:
 *      - Bounds checking in MovePlayer(...) method.
 */

using AknamezoModel;
using Timer = System.Windows.Forms.Timer;

namespace AknamezoWinForms 
{
    public partial class GameForm : Form
    {
        private GameState gameState; // Game state
        private PictureBox mineBody;

        public GameForm()
        {
            InitializeComponent();

            // Initializing model
            Submarine playerModel = new Submarine(player.Location.X, player.Location.Y, 50, player.Height, player.Width);
            // -- TESTING MINE
            Mine mine = new Mine(100, 100, 1, 50, 50);
            gameState = new GameState(playerModel, mine);

            // Subscribing buttons event handler methods
            startButton.Click += StartButton_Click;
            stopButton.Click += StopButton_Click;
            saveButton.Click += SaveButton_Click;
            loadButton.Click += LoadButton_Click;

            // Subscribing the game timer to the tick event
            gameTimer.Tick += GameTimer_Tick;
            gameTimer.Interval = 1000;

            // Subscribing the game loop timer to the tick event
            gameLoopTimer.Tick += GameLoopTimer_Tick;
            // I set the gameLoop to update every 16 miliseconds because that's roughly 60 fps (1000 / 60)
            gameLoopTimer.Interval = 16;

            // Subscribing to keypress event
            KeyPreview = true;
            KeyDown += MovePlayer;

            // -- TESTING MINE
            // Drawing a mine PictureBox to gamePanel
            mineBody = new PictureBox();
            mineBody.Location = new Point(100, 100);
            mineBody.Size = new Size(gameState.Mine.Height, gameState.Mine.Width);
            mineBody.BackColor = Color.Red;
            gamePanel.Controls.Add(mineBody);
        }

        // Main game loop. (60 fps)
        // Game loop timer tick event handler.
        private void GameLoopTimer_Tick(object? sender, EventArgs e)
        {
            // Drawing the player
            player.Location = new Point(gameState.Player.X, gameState.Player.Y);

            // -- TESTING MINE
            // Moving mine down
            gameState.Mine.Sink();
            mineBody.Location = new Point(gameState.Mine.X, gameState.Mine.Y);

            // Check player collision with mine
            if (gameState.MineHit())
            {
                gameTimer.Stop();
                gameLoopTimer.Stop();
                MessageBox.Show("A MINE HIT YOU!");
            }
        }

        // Game timer tick event handler.
        private void GameTimer_Tick(object? sender, EventArgs e)
        {
            gameState.ElpasedTime++;
            gameTimeLabel.Text = $"Game time: {gameState.ElpasedTime}";
        }

        // Start button event handler.
        // Starts the game loop (by starting the game timer).
        private void StartButton_Click(object? sender, EventArgs e)
        {
            gameTimer.Start();
            gameLoopTimer.Start();
        }

        // Stop button event handler.
        // Stops the game loop (by stopping the game timer).
        private void StopButton_Click(object? sender, EventArgs e)
        {
            gameTimer.Stop();
            gameLoopTimer.Stop();
        }

        // Save button event handler.
        // Saves the current game state to a json file.
        private void SaveButton_Click(object? sender, EventArgs e)
        {
            throw new NotImplementedException();
        }

        // Load button event handler.
        // Loads a game from a json file.
        private void LoadButton_Click(object? sender, EventArgs e)
        {
            throw new NotImplementedException();
        }
         
        // Method to move the player on specific key presses.
        // Handles the KeyPress event.
        private void MovePlayer(object? sender, KeyEventArgs e) 
        {
            if (gameLoopTimer.Enabled)
            {
                switch (e.KeyCode)
                {
                    case Keys.W:
                        gameState.Player.MoveUp();
                        break;
                    case Keys.S:
                        gameState.Player.MoveDown();
                        break;
                    case Keys.A:
                        gameState.Player.MoveLeft();
                        break;
                    case Keys.D:
                        gameState.Player.MoveRight();
                        break;
                }
            }
        }
    }
}
