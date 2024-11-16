using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using AknamezoModel.Model;
using System.Windows.Threading;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows.Controls;
using System.Windows;

namespace AknamezoViewModel
{
    public class AknamezoViewModel : INotifyPropertyChanged
    {
        public int CanvasHeight { get; set; } = 500; // Height of the game canvas.
        public int CanvasWidth { get; set; } = 1000; // Widht of the game canvas.
        public int PlayerStartX { get; set; } = 400;
        public int PlayerStartY { get; set; } = 400;

        private GameState _gameState; // Holds the model.
        private string _gameTimeText; // Shows the game time.

        private DispatcherTimer? _gameTimer; // Timer that ticks every 1 second for keeping track of gametime.
        private DispatcherTimer? _gameLoopTimer; // Main game loop that ticks every 16 milliseconds (roughly 60 fps).
        private DispatcherTimer? _ship1MineTimer; // Timer for ship 1 to drop a new mine.
        private DispatcherTimer? _ship2MineTimer; // Timer for ship 2 to drop a new mine.
        private DispatcherTimer? _ship3MineTimer; // Timer for ship 3 to drop a new mine.

        public DelegateCommand StartBtnClicked { get; private set; }
        public DelegateCommand StopBtnClicked { get; private set; }
        public DelegateCommand RestartBtnClicked { get; private set; }
        public DelegateCommand SaveBtnClicked { get; private set; }
        public DelegateCommand LoadBtnClicked { get; private set; }
        public DelegateCommand MovePlayerCmd { get; private set; } // Used as the window keyboard binding.

        public event PropertyChangedEventHandler? PropertyChanged; // Propertychanged event.

        public GameState GameState
        {
            get => _gameState;
        }

        public string GameTimeText
        {
            get => _gameTimeText;
            private set
            {
                _gameTimeText = value;
                OnPropertyChanged();
            }
        }

        public AknamezoViewModel()
        {
            // -- INITIALIZING GAMESTATE
            _gameState = new GameState(
                new Submarine(PlayerStartX, PlayerStartY, 50, 50, 50),
                new Easy()
            );
            _gameState.ElpasedTime = 0;
            _gameTimeText = $"Game time: {_gameState.ElpasedTime}";
            SetupShips();
            _gameState.MineCollison += GameState_MineCollision;

            // -- INITIALIZING THE TIMERS
            SetupTimer(
                ref _gameLoopTimer,
                16,
                new DelegateCommand(
                    _ => GameLoopTimerTick(),
                    _ => true
                )
            );
            SetupTimer(
                ref _gameTimer,
                1000,
                new DelegateCommand(
                    _ => GameTimerTick(),
                    _ => true
                )
            );

            // -- INITIALIZING THE BUTTON COMMANDS
            StartBtnClicked = new DelegateCommand(
                _ => StartGame(),
                _ => true
            );
            StopBtnClicked = new DelegateCommand(
                _ => StopGame(),
                _ => false
            );
            RestartBtnClicked = new DelegateCommand(
                _ => _gameState.RestartGame(),
                _ => true
            );
            SaveBtnClicked = new DelegateCommand(
                _ => { },
                _ => true
            );
            LoadBtnClicked = new DelegateCommand(
                _ => { },
                _ => true
            );
            MovePlayerCmd = new DelegateCommand(
                key =>
                {
                    if (key is string k)
                        MovePlayer(k);
                },
                _ => false
            );
        }

        /// <summary>
        /// Starts the game by starting all of the neccessary timers and changes the predicate on buttons.
        /// </summary>
        private void StartGame()
        {
            StartBtnClicked.Predicate = _ => false;
            StopBtnClicked.Predicate = _ => true;
            RestartBtnClicked.Predicate = _ => false;
            MovePlayerCmd.Predicate = _ => true;
            _gameLoopTimer?.Start();
            _gameTimer?.Start();
            _ship1MineTimer?.Start();
            _ship2MineTimer?.Start();
            _ship3MineTimer?.Start();
        }

        /// <summary>
        /// Stops the game by stopping all of the neccessary timers and changes the predicate on buttons.
        /// </summary>
        private void StopGame()
        {
            StartBtnClicked.Predicate = _ => true;
            StopBtnClicked.Predicate = _ => false;
            RestartBtnClicked.Predicate = _ => true;
            MovePlayerCmd.Predicate = _ => false;
            _gameLoopTimer?.Stop();
            _gameTimer?.Stop();
            _ship1MineTimer?.Stop();
            _ship2MineTimer?.Stop();
            _ship3MineTimer?.Stop();
        }

        /// <summary>
        /// Handles the MineCollition event for GameState.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void GameState_MineCollision(object? sender, EventArgs e)
        {
            StopGame();
            MessageBox.Show($"YOU DIED\nTOTAL GAME TIME: {_gameState.ElpasedTime}");
        }

        /// <summary>
        /// Method that moves the player.
        /// </summary>
        /// <param name="key"></param>
        private void MovePlayer(string key)
        {
            switch (key)
            {
                case "W":
                    if (_gameState.Player.Y > OriginalGameState.SHIP3_START_Y + _gameState.Ships[2].Height + _gameState.Player.Height)
                        _gameState.Player.MoveUp();
                    break;
                case "S":
                    if (_gameState.Player.Y < CanvasHeight - _gameState.Player.Height)
                        _gameState.Player.MoveDown();
                    break;
                case "D":
                    if (_gameState.Player.X < CanvasWidth - _gameState.Player.Width) 
                        _gameState.Player.MoveRight();
                    break;
                case "A":
                    if (_gameState.Player.X > 0)
                        _gameState.Player.MoveLeft();
                    break;
                default:
                    break;
            }
        }

        /// <summary>
        /// This gets executed each time that _gameLoopTimer ticks.
        /// </summary>
        private void GameLoopTimerTick()
        {
            // -- MOVING THE SHIPS
            foreach (Ship ship in _gameState.Ships)
            {
                ship.Move();

                if (ship.X + ship.Width >= CanvasWidth || ship.X < 0)
                    ship.ReverseDirection();
            }

            // -- SINKING THE MINES
            for (int i = 0; i < _gameState.Mines.Count; i++)
            {
                Mine mine = _gameState.Mines[i];
                mine.Sink();

                // If the mine is out of bounds remove it.
                if (mine.Y >= CanvasHeight - mine.Height)
                    _gameState.Mines.RemoveAt(i);
            }

            // -- CHECKING FOR MINE COLLISION
            _gameState.MineHit();
        }

        /// <summary>
        /// This gets executed each time _gameTimer ticks.
        /// </summary>
        private void GameTimerTick()
        {
            _gameState.ElpasedTime++;
            GameTimeText = $"Game time: {_gameState.ElpasedTime}";
        }

        /// <summary>
        /// Sets up the given timer. Doesn't start it.
        /// </summary>
        /// <param name="timer">The timer that needs to be setup.</param>
        /// <param name="interval">The interval in milliseconds.</param>
        /// <param name="tickCommand">The command to be executed with each tick.</param>
        private void SetupTimer(ref DispatcherTimer? timer, int interval, DelegateCommand tickCommand)
        {
            timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromMilliseconds(interval);
            timer.Tick += (_, _) => tickCommand.Execute(null);
        }

        /// <summary>
        /// Sets up the ships and their mine drop timers.
        /// </summary>
        private void SetupShips()
        {
            // -- SHIP 1
            _gameState.AddShip(
               new Ship(
                   OriginalGameState.SHIP1_START_X,
                   OriginalGameState.SHIP1_START_Y,
                   50,
                   180,
                   3,
                   _gameState.Difficulty.MineIntervalMin(),
                   _gameState.Difficulty.MineIntervalMax()
               )
            );
            _ship1MineTimer = new DispatcherTimer();
            _ship1MineTimer.Interval = TimeSpan.FromMilliseconds(_gameState.Ships[0].MineIntervalSpeed);
            _ship1MineTimer.Tick += (_, _) =>
            {
                _gameState.AddMine(_gameState.Ships[0].DropMine());
                _ship1MineTimer.Interval = TimeSpan.FromMilliseconds(_gameState.Ships[0].ChangeMineDropInterval());
            };

            // -- SHIP 2
            _gameState.AddShip(
                new Ship(
                    OriginalGameState.SHIP2_START_X,
                    OriginalGameState.SHIP2_START_Y,
                    50,
                    180,
                    3,
                    _gameState.Difficulty.MineIntervalMin(),
                    _gameState.Difficulty.MineIntervalMax()
                )
            );
            _ship2MineTimer = new DispatcherTimer();
            _ship2MineTimer.Interval = TimeSpan.FromMilliseconds(_gameState.Ships[1].MineIntervalSpeed);
            _ship2MineTimer.Tick += (_, _) =>
            {
                _gameState.AddMine(_gameState.Ships[1].DropMine());
                _ship2MineTimer.Interval = TimeSpan.FromMilliseconds(_gameState.Ships[1].ChangeMineDropInterval());
            };

            // -- SHIP 3
            _gameState.AddShip(
                new Ship(
                    OriginalGameState.SHIP3_START_X,
                    OriginalGameState.SHIP3_START_Y,
                    50,
                    180,
                    3,
                    _gameState.Difficulty.MineIntervalMin(),
                    _gameState.Difficulty.MineIntervalMax()
                )
            );
            _ship3MineTimer = new DispatcherTimer();
            _ship3MineTimer.Interval = TimeSpan.FromMilliseconds(_gameState.Ships[2].MineIntervalSpeed);
            _ship3MineTimer.Tick += (_, _) =>
            {
                _gameState.AddMine(_gameState.Ships[2].DropMine());
                _ship3MineTimer.Interval = TimeSpan.FromMilliseconds(_gameState.Ships[2].ChangeMineDropInterval());
            };
        }

        /// <summary>
        /// Invokes the PropertyChanged event with the given property.
        /// </summary>
        /// <param name="property">If null then it uses the CallerMemberName.</param>
        private void OnPropertyChanged([CallerMemberName] string? property = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));
        }
    }
}