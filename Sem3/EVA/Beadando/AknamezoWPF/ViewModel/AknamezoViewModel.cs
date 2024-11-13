using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using AknamezoModel.Model;
using System.Windows.Threading;
using System.ComponentModel;

namespace AknamezoViewModel
{
    public class AknamezoViewModel : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler? PropertyChanged;

        private GameState _gameState; // Holds the model.

        private DispatcherTimer? _gameLoopTimer; // Main game loop that ticks every 16 milliseconds (roughly 60 fps).

        public GameState GameState
        {
            get => _gameState;
        }

        public AknamezoViewModel()
        {
            // -- INITIALIZING GAMESTATE
            _gameState = new GameState(
                new Submarine(400, 400, 50, 50, 50),
                new Easy()
            );

            // -- INITIALIZING THE TIMERS
            SetupTimer(
                ref _gameLoopTimer,
                16,
                new DelegateCommand(
                    _ => GameLoopTimerTick(),
                    _ => true
                )
            );

            // -- INITIALIZING SOME MINES FOR TESTING
            _gameState.AddMine(new LightMine(50, 50, 50, 50));
            _gameState.AddMine(new MediumMine(150, 50, 50, 50));
            _gameState.AddMine(new HeavyMine(250, 50, 50, 50));

            StartGame();
        }

        /// <summary>
        /// Starts the game by starting all of the neccessary timers.
        /// </summary>
        private void StartGame()
        {
            _gameLoopTimer?.Start();
        }

        /// <summary>
        /// This gets executed each time that _gameLoopTimer ticks.
        /// </summary>
        private void GameLoopTimerTick()
        {
            foreach (Mine mine in _gameState.Mines)
            {
                mine.Sink();
            }
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
    }
}