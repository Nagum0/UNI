using AknamezoModel.Model;

namespace AknamezoWinForms 
{
    public partial class GameForm : Form
    {
        private GameState gameState; // Game state
        private List<PictureBox> mineBodies;

        public GameForm()
        {
            InitializeComponent();

            // -- INITIALIZING MODEL --
            // Setting up submarine
            Submarine playerModel = new Submarine(player.Location.X, player.Location.Y, 50, player.Height, player.Width);
            gameState = new GameState(playerModel);
            // Setting up the ships
            SetupShips();
            // Initializing mineBodies
            mineBodies = new List<PictureBox>();

            // -- SUBSRCIBING HANDLERS TO WINFORMS EVENTS --
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
            if (gameState.MineHit())
            {
                StopGame();
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
            ship1MineTimer.Start();
            ship2MineTimer.Start();
            ship3MineTimer.Start();
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
            throw new NotImplementedException();
        }

        // Load button event handler.
        // Loads a game from a json file.
        private void LoadButton_Click(object? sender, EventArgs e)
        {
            throw new NotImplementedException();
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

        // Goes through each mine model and mineBody and sinks it.
        private void SinkMines()
        {
            for (int i = 0; i < gameState.Mines.Count; i++)
            {
                gameState.Mines[i].Sink();
                mineBodies[i].Location = new Point(gameState.Mines[i].X, gameState.Mines[i].Y);
            }
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
                        if (gameState.Player.Y >= 300)
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
                        if (gameState.Player.X >= 0)
                        {
                            gameState.Player.MoveLeft();
                        }
                        break;
                    case Keys.D:
                        if (gameState.Player.X <= gamePanel.Width - gameState.Player.Width)
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
            gameState.AddShip(new Ship(shipBody1.Location.X, shipBody1.Location.Y, shipBody1.Height, shipBody1.Width, 5, 2000, 6000));
            gameState.AddShip(new Ship(shipBody2.Location.X, shipBody2.Location.Y, shipBody2.Height, shipBody2.Width, 5, 2000, 6000));
            gameState.AddShip(new Ship(shipBody3.Location.X, shipBody3.Location.Y, shipBody3.Height, shipBody3.Width, 5, 2000, 6000));

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
            Mine mine = gameState.Ships[0].DropMine();
            PictureBox mineBody = CreateMineBody(mine);
            AddMineToGame(mine, mineBody);

            // Randomly setting a new mine drop interval
            ship1MineTimer.Interval = gameState.Ships[0].ChangeMineDropInterval();
        }

        private void Ship2MineTimer_Tick(object? sender, EventArgs e)
        {
            // Dropping the mine
            Mine mine = gameState.Ships[1].DropMine();
            PictureBox mineBody = CreateMineBody(mine);
            AddMineToGame(mine, mineBody);

            // Randomly setting a new mine drop interval
            ship1MineTimer.Interval = gameState.Ships[1].ChangeMineDropInterval();
        }

        private void Ship3MineTimer_Tick(object? sender, EventArgs e)
        {
            // Dropping the mine
            Mine mine = gameState.Ships[2].DropMine();
            PictureBox mineBody = CreateMineBody(mine);
            AddMineToGame(mine, mineBody);

            // Randomly setting a new mine drop interval
            ship1MineTimer.Interval = gameState.Ships[2].ChangeMineDropInterval();
        }

        // ----------------- MINE METHODS -----------------
        private PictureBox CreateMineBody(Mine mine)
        {
            PictureBox mineBody = new PictureBox();
            mineBody.Location = new Point(mine.X, mine.Y);
            mineBody.Size = new Size(mine.Width, mine.Height);
            mineBody.BackColor = Color.Black;
            return mineBody;
        }

        private void AddMineToGame(Mine mine, PictureBox body)
        {
            gameState.AddMine(mine);
            mineBodies.Add(body);
            gamePanel.Controls.Add(body);
        }
    }
}
