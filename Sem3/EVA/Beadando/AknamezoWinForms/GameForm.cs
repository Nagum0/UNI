using AknamezoModel.Model;
using AknamezoModel.Persistance;

namespace AknamezoWinForms 
{
    public partial class GameForm : Form
    {
        private JsonFileManager jsonFileManager = new JsonFileManager(); // File manager
        private GameState gameState; // Game state
        private List<PictureBox> mineBodies; // Mine bodies

        public GameForm()
        {
            InitializeComponent();

            // -- INITIALIZING MODEL --
            gameState = new GameState(
                    new Submarine(player.Location.X, player.Location.Y, 50, player.Height, player.Width),
                    new Easy()
            );
            // Setting up the ships
            SetupShips();
            // Initializing mineBodies
            mineBodies = new List<PictureBox>();
            // Subscribing to the MineCollision event
            gameState.MineCollison += GameState_MineCollison;

            // -- SUBSRCIBING HANDLERS TO WINFORMS EVENTS --
            // Subscribing buttons event handler methods
            startButton.Click += StartButton_Click;
            stopButton.Click += StopButton_Click;
            saveButton.Click += SaveButton_Click;
            loadButton.Click += LoadButton_Click;
            restartButton.Click += RestartButton_Click;

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
        }

        private void GameState_MineCollison(object? sender, EventArgs e)
        {
            StopGame();
            MessageBox.Show($"YOU DIED\nTOTAL GAME TIME: {gameState.ElpasedTime}");
        }

        // Main game loop. (60 fps)
        // Updates the movement, checks for collision, drwas the positions of the ships and the mines.
        // Game loop timer tick event handler.
        private void GameLoopTimer_Tick(object? sender, EventArgs e)
        {
            // Drawing the player
            player.Location = new Point(gameState.Player.X, gameState.Player.Y);

            // Moving the enemy ships
            MoveShip(shipBody1, 0);
            MoveShip(shipBody2, 1);
            MoveShip(shipBody3, 2);

            // Sinking the mines
            SinkMines();

            // Check if mine collision happened
            gameState.MineHit();
        }

        // Game timer tick event handler.
        private void GameTimer_Tick(object? sender, EventArgs e)
        {
            // Update gameTime label
            gameState.ElpasedTime++;
            gameTimeLabel.Text = $"Game time: {gameState.ElpasedTime}";

            // Up the difficulty
            switch (gameState.ElpasedTime)
            {
                case 15:
                    gameState.ChangeDifficulty(new Normal());
                    break;
                case 25:
                    gameState.ChangeDifficulty(new Hard());
                    break;
                case 35:
                    gameState.ChangeDifficulty(new Death());
                    break;
                default:
                    break;
            }

            // -- DEBUGGING
            Console.WriteLine($"{gameState}");
        }

        // Start button event handler.
        // Starts the game loop (by starting the game timer).
        private void StartButton_Click(object? sender, EventArgs e)
        {
            StartGame();
        }

        // Stop button event handler.
        // Stops the game loop (by stopping the game timer).
        private void StopButton_Click(object? sender, EventArgs e)
        {
            StopGame();
        }

        // Save button event handler.
        // Saves the current game state to a json file.
        private void SaveButton_Click(object? sender, EventArgs e)
        {
            try
            {
                using SaveFileDialog saveFileDialog = new SaveFileDialog();
                saveFileDialog.Filter = "JSON files (*.json)|*.json|All files (*.*)|*.*";
                saveFileDialog.Title = "SAVE GAME";

                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    string fileName = saveFileDialog.FileName;
                    jsonFileManager.Save(gameState, fileName);
                }
            }
            catch (Exception)
            {
                MessageBox.Show("UNABLE TO SAVE GAME");
            }
        }

        // Load button event handler.
        // Loads a game from a json file.
        private void LoadButton_Click(object? sender, EventArgs e)
        {
            Console.WriteLine("GAME LOADED FROM FILE");

            // Restart the game
            RestartGame();

            try
            {
                using OpenFileDialog openFileDialog = new OpenFileDialog();
                openFileDialog.Filter = "JSON files (*.json)|*.json|All files (*.*)|*.*";
                openFileDialog.Title = "LOAD GAME SAVE";

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    string fileName = openFileDialog.FileName;
                    GameState readGameState = jsonFileManager.Load(fileName);
                    gameState = readGameState;
                    gameState.MineCollison += GameState_MineCollison;

                    // Create the mine bodies for all the loaded mines
                    foreach (Mine mine in gameState.Mines) 
                    {
                        PictureBox mineBody = CreateMineBody(mine);
                        mineBodies.Add(mineBody);
                        gamePanel.Controls.Add(mineBody);
                    }
                }
            }
            catch (Exception)
            {
                MessageBox.Show("Unable to read save file.");
            }
        }

        // Set everything to its original state and restart all of the timers.
        private void RestartButton_Click(object? sender, EventArgs e)
        {
            RestartGame();
        }

        private void RestartGame()
        {
            Console.WriteLine("RESTARTING GAME: ");

            // Stopping the game
            StopGame();

            // Reset ship and player body positions
            player.Location = new Point(OriginalGameState.PLAYER_START_X, OriginalGameState.PLAYER_START_Y);
            shipBody1.Location = new Point(OriginalGameState.SHIP1_START_X, OriginalGameState.SHIP1_START_Y);
            shipBody2.Location = new Point(OriginalGameState.SHIP2_START_X, OriginalGameState.SHIP2_START_Y);
            shipBody3.Location = new Point(OriginalGameState.SHIP3_START_X, OriginalGameState.SHIP3_START_Y);

            // Reset the ship direction
            for (int i = 0; i < gameState.Ships.Count; i++)
            {
                gameState.Ships[i].Speed = Math.Abs(gameState.Ships[i].Speed);
            }

            // Empty mine bodies
            foreach (PictureBox mineBody in mineBodies)
            {
                mineBody.Dispose();
            }
            mineBodies = new List<PictureBox>();

            // Reset the model
            gameState.RestartGame();

        }

        // Start all of the timers needed for the game.
        private void StartGame()
        {
            gameLoopTimer.Start();
            gameTimer.Start();
            ship1MineTimer.Start();
            ship2MineTimer.Start();
            ship3MineTimer.Start();
        }

        // Stops all the active timers for the game.
        private void StopGame()
        {
            gameLoopTimer.Stop();
            gameTimer.Stop();
            ship1MineTimer.Stop();
            ship2MineTimer.Stop();
            ship3MineTimer.Stop();
        }

        // Updates the ship position and moves the shipBody.
        private void MoveShip(PictureBox shipBody, int shipIndex)
        {
            Ship ship = gameState.Ships[shipIndex];
            ship.Move();

            if (ship.X + ship.Width >= gamePanel.Width || ship.X < 0)
            {
                ship.ReverseDirection();
            }

            shipBody.Location = new Point(ship.X, shipBody.Location.Y);
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
                        if (gameState.Player.Y >= (shipBody3.Location.Y + shipBody3.Height) + 75)
                        {
                            gameState.Player.MoveUp();
                        }
                        break;
                    case Keys.S:
                        if (gameState.Player.Y + gameState.Player.Height <= gamePanel.Height - gameState.Player.Height)
                        {
                            gameState.Player.MoveDown();
                        }
                        break;
                    case Keys.A:
                        if (gameState.Player.X > gameState.Player.Width)
                        {
                            gameState.Player.MoveLeft();
                        }
                        break;
                    case Keys.D:
                        if (gameState.Player.X + gameState.Player.Width < gamePanel.Width - gameState.Player.Width)
                        {
                            gameState.Player.MoveRight();
                        }
                        break;
                }
            }
        }

        // ----------------- SHIP METHODS -----------------
        private void SetupShips()
        {
            // Setting up the ship models
            gameState.AddShip(new Ship(
                        shipBody1.Location.X,
                        shipBody1.Location.Y,
                        shipBody1.Height,
                        shipBody1.Width,
                        3,
                        gameState.Difficulty.MineIntervalMin(),
                        gameState.Difficulty.MineIntervalMax())
            );
            gameState.AddShip(new Ship(
                        shipBody2.Location.X,
                        shipBody2.Location.Y,
                        shipBody2.Height,
                        shipBody2.Width,
                        3,
                        gameState.Difficulty.MineIntervalMin(),
                        gameState.Difficulty.MineIntervalMax())
            );
            gameState.AddShip(new Ship(
                        shipBody3.Location.X,
                        shipBody3.Location.Y,
                        shipBody3.Height,
                        shipBody3.Width,
                        3,
                        gameState.Difficulty.MineIntervalMin(),
                        gameState.Difficulty.MineIntervalMax())
            );

            // Setting up the ship timers
            ship1MineTimer.Interval = gameState.Ships[0].MineIntervalSpeed;
            ship2MineTimer.Interval = gameState.Ships[1].MineIntervalSpeed;
            ship3MineTimer.Interval = gameState.Ships[2].MineIntervalSpeed;

            // Setting up the ship timer tick events
            ship1MineTimer.Tick += Ship1MineTimer_Tick;
            ship2MineTimer.Tick += Ship2MineTimer_Tick;
            ship3MineTimer.Tick += Ship3MineTimer_Tick;
        }

        private void Ship1MineTimer_Tick(object? sender, EventArgs e)
        {
            // Dropping the mine
            DropMine(0);

            // Randomly setting a new mine drop interval
            ship1MineTimer.Interval = gameState.Ships[0].ChangeMineDropInterval();
        }

        private void Ship2MineTimer_Tick(object? sender, EventArgs e)
        {
            // Dropping the mine
            DropMine(1);

            // Randomly setting a new mine drop interval
            ship2MineTimer.Interval = gameState.Ships[1].ChangeMineDropInterval();
        }

        private void Ship3MineTimer_Tick(object? sender, EventArgs e)
        {
            // Dropping the mine
            DropMine(2);

            // Randomly setting a new mine drop interval
            ship3MineTimer.Interval = gameState.Ships[2].ChangeMineDropInterval();
        }

        private void DropMine(int shipIndex)
        {
            Mine mine = gameState.Ships[shipIndex].DropMine();
            PictureBox mineBody = CreateMineBody(mine);
            AddMineToGame(mine, mineBody);

            Console.WriteLine($"Ship[{shipIndex}] dropped a mine [{mine}]");
        }

        // ----------------- MINE METHODS -----------------
        private PictureBox CreateMineBody(Mine mine)
        {
            PictureBox mineBody = new PictureBox();
            mineBody.Location = new Point(mine.X, mine.Y);
            mineBody.Size = new Size(mine.Width, mine.Height);
            mineBody.Image = Properties.Resources.mine;
            return mineBody;
        }

        private void AddMineToGame(Mine mine, PictureBox body)
        {
            gameState.AddMine(mine);
            mineBodies.Add(body);
            gamePanel.Controls.Add(body);
        }

        // Goes through each mine model and mineBody and sinks it.
        private void SinkMines()
        {
            for (int i = 0; i < gameState.Mines.Count; i++)
            {
                gameState.Mines[i].Sink();
                mineBodies[i].Location = new Point(gameState.Mines[i].X, gameState.Mines[i].Y);
            }
        }
    }
}
