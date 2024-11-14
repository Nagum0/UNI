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

namespace AknamezoViewModel
{
    public class AknamezoViewModel : INotifyPropertyChanged
    {
        public int CanvasHeight { get; set; } = 500; // Height of the game canvas.
        public int CanvasWidth { get; set; } = 980; // Widht of the game canvas.

        private GameState _gameState; // Holds the model.
        private string _gameTimeText;

        private DispatcherTimer? _gameTimer; // Timer that ticks every 1 second for keeping track of gametime.
        private DispatcherTimer? _gameLoopTimer; // Main game loop that ticks every 16 milliseconds (roughly 60 fps).

        public DelegateCommand StartBtnClicked { get; private set; }
        public DelegateCommand StopBtnClicked { get; private set; }
        public DelegateCommand RestartBtnClicked { get; private set; }
        public DelegateCommand SaveBtnClicked { get; private set; }
        public DelegateCommand LoadBtnClicked { get; private set; }

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
                new Submarine(400, 400, 50, 50, 50),
                new Easy()
            );
            _gameState.ElpasedTime = 0;
            _gameTimeText = $"Game time: {_gameState.ElpasedTime}";

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
                _ => { },
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

            // -- INITIALIZING SOME MINES FOR TESTING
            _gameState.AddMine(new LightMine(50, 50, 50, 50));
            _gameState.AddMine(new MediumMine(150, 50, 50, 50));
            _gameState.AddMine(new HeavyMine(250, 50, 50, 50));
        }

        /// <summary>
        /// Starts the game by starting all of the neccessary timers.
        /// </summary>
        private void StartGame()
        {
            StartBtnClicked.Predicate = _ => false;
            StopBtnClicked.Predicate = _ => true;
            _gameLoopTimer?.Start();
            _gameTimer?.Start();
        }

        /// <summary>
        /// Stops the game by stopping all of the neccessary timers.
        /// </summary>
        private void StopGame()
        {
            StartBtnClicked.Predicate = _ => true;
            StopBtnClicked.Predicate = _ => false;
            _gameLoopTimer?.Stop();
            _gameTimer?.Stop();
        }

        /// <summary>
        /// This gets executed each time that _gameLoopTimer ticks.
        /// </summary>
        private void GameLoopTimerTick()
        {
            // -- SINKING THE MINES
            for (int i = 0; i < _gameState.Mines.Count; i++)
            {
                Mine mine = _gameState.Mines[i];
                mine.Sink();

                // If the mine is out of bounds remove it.
                if (mine.Y >= CanvasHeight - mine.Height)
                    _gameState.Mines.RemoveAt(i);
            }
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
        /// Invokes the PropertyChanged event with the given property.
        /// </summary>
        /// <param name="property">If null then it uses the CallerMemberName.</param>
        private void OnPropertyChanged([CallerMemberName] string? property = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));
        }
    }
}