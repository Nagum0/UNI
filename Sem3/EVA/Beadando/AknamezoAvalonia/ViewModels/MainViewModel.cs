using AknamezoModel.Model;
using AknamezoModel.Persistance;
using Avalonia.Threading;
using ReactiveUI;
using System;

namespace AknamezoAvalonia.ViewModels;

public class MainViewModel : ViewModelBase
{
    #region Fields

    private GameState _gameState; // Model.
    private JsonFileManager _jsonFileManager; // File manager.
    private string _gameTimeText; // Shows the game time.

    private DispatcherTimer? _gameTimer; // Timer that ticks every second for keeping track of gametime.
    private DispatcherTimer? _gameLoopTimer; // Main game loop that ticks every 16 milliseconds (roughly 60 fps).
    private DispatcherTimer? _ship1MineTimer; // Timer for ship 1 to drop a new mine.
    private DispatcherTimer? _ship2MineTimer; // Timer for ship 2 to drop a new mine.
    private DispatcherTimer? _ship3MineTimer; // Timer for ship 3 to drop a new mine.

    #endregion

    #region Properties

    public int WindowWidth { get; private set; } = 1100; // Width of the game window.
    public int WindowHeight { get; private set; } = 650; // Height of the game window.
    public int CanvasHeight { get; set; } = 500; // Height of the game canvas.
    public int CanvasWidth { get; set; } = 1000; // Widht of the game canvas.

    public DelegateCommand StartBtnClicked { get; private set; }
    public DelegateCommand StopBtnClicked { get; private set; }
    public DelegateCommand RestartBtnClicked { get; private set; }
    public DelegateCommand SaveBtnClicked { get; private set; }
    public DelegateCommand LoadBtnClicked { get; private set; }
    public DelegateCommand MovePlayerCmd { get; private set; } // Used as the window keyboard binding.

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
            this.RaisePropertyChanged(nameof(GameTimeText));
        }
    }

    #endregion

    #region Public Methods

    public MainViewModel()
    {
        _gameState = new GameState(null, null);
        _gameTimeText = "Game time: ";

        _gameTimer = new DispatcherTimer();
        _gameTimer.Interval = TimeSpan.FromMilliseconds(1000);
        //_gameTimer.Tick += (_, _) => new DelegateCommand();
        _gameTimer.Start();
    }

    #endregion

    #region Private Methods

    private void GameTimerTick()
    {
        _gameState.ElpasedTime++;
        GameTimeText = $"Game time: {_gameState.ElpasedTime}";
    }

    #endregion
}
