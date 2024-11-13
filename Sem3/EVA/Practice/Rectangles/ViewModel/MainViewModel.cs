using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Threading;
using System.Windows.Media;
using System.Diagnostics;

namespace Rectangles.ViewModel
{
    public class Mine : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler? PropertyChanged;
        public int X { get; set; }
        public int Y { get; set; }
        public int Width { get; set; }
        public int Height { get; set; }
        public int Speed { get; set; }
        public Brush Fill { get; set; }

        public Mine(int x, int y, int width, int height, int speed, Brush fill)
        {
            X = x;
            Y = y;
            Width = width;
            Height = height;
            Speed = speed;
            Fill = fill;
        }

        public void Sink()
        {
            Y += Speed;
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Y)));
        }
    }

    public class MainViewModel : INotifyPropertyChanged
    {
        const int WIDTH = 800;
        const int HEIGHT = 450;

        /// <summary>
        /// Signals the change of a property.
        /// </summary>
        public event PropertyChangedEventHandler? PropertyChanged;

        private ObservableCollection<Mine> _mines;
        private DispatcherTimer? _mineDropTimer;
        private DelegateCommand _mineDropTimerCmd;
        private Random _mineRandonXGenerator;

        private DispatcherTimer? _gameLoopTimer;
        private DelegateCommand _gameLoopTimerCmd;

        public MainViewModel()
        {
            // -- Mines setup
            _mines = new ObservableCollection<Mine>();
            _mineRandonXGenerator = new Random();
            _mineDropTimerCmd = new DelegateCommand(
                _ => DropMine(),
                _ => true
            );
            SetupTimer(_mineDropTimer, 1000, _mineDropTimerCmd);

            // -- Gameloop
            _gameLoopTimerCmd = new DelegateCommand(
                _ => GameLoop(),
                _ => true
            );
            SetupTimer(_gameLoopTimer, 16, _gameLoopTimerCmd);
        }

        public ObservableCollection<Mine> Mines
        {
            get => _mines;
        }

        private void SetupTimer(DispatcherTimer? timer, int interval, DelegateCommand tickCommand)
        {
            timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromMilliseconds(interval);
            timer.Tick += (_, _) => tickCommand.Execute(null);
            timer.Start();
        }

        private void DropMine()
        {
            int x = _mineRandonXGenerator.Next(50, WIDTH - 50);
            Mine mine = new Mine(x, 100, 50, 50, 2, Brushes.Red);
            _mines.Add(mine);
        }

        private void GameLoop()
        {
            foreach (Mine mine in _mines)
            {
                mine.Sink();
            }
        }

        private void OnPropertyChanged([CallerMemberName] string? propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
     }
}
