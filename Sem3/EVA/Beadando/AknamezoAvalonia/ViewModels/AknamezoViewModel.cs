using AknamezoModel.Model;
using AknamezoModel.Persistance;
using Avalonia.Threading;
using ReactiveUI;
using System;

namespace AknamezoAvalonia.ViewModels;

public class AknamezoViewModel : ViewModelBase
{
    #region Fields

    private double _canvasWidth = 1000;
    private double _canvasHeight = 500;
    private bool _menuOpen = true; // Used for mobile version to check whether the menu needs to be visible.
    private bool _gameActive = false;
    private string _gameTimeText = "Game time: 0";

    private DispatcherTimer? _gameTimer;

    private GameState _gameState;

    #endregion

    #region Properties

    public bool OnMobile { get; set; } = false;

    public double CanvasWidth
    {
        get => _canvasWidth;
        set
        {
            _canvasWidth = value;
            this.RaisePropertyChanged(nameof(CanvasWidth));
        }
    }

    public double CanvasHeight
    {
        get => _canvasHeight;
        set
        {
            _canvasHeight = value;
            this.RaisePropertyChanged(nameof(CanvasHeight));
        }
    }

    public bool MenuOpen
    {
        get => _menuOpen;
        private set
        {
            _menuOpen = value;
            this.RaisePropertyChanged(nameof(MenuOpen));
        }
    }

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

    #region Commands

    public DelegateCommand OpenMenuCmd { get; set; }
    public DelegateCommand MovePlayerCmd { get; set; }
    public DelegateCommand StartBtnClicked { get; set; }
    public DelegateCommand StopBtnClicked { get; set; }
    public DelegateCommand RestartBtnClicked { get; set; }

    #endregion

    #region Public Methods

    public AknamezoViewModel()
    {
        // -- MODEL:
        Submarine player = new Submarine(400, 200, 50, 50, 50);
        _gameState = new GameState(player, new Easy());

        // -- TIMERS:
        SetupTimer(
            ref _gameTimer,
            1000,
            new DelegateCommand(
                _ => OnGameTimerTick(),
                _ => true
            )
        );

        // -- COMMANDS:
        // -- FOR MOBILE VERSION: Opens the menu
        OpenMenuCmd = new DelegateCommand(_ => OnMenuOpened(), _ => true);
        MovePlayerCmd = new DelegateCommand(key => OnPlayerMove(key), _ => true);
        StartBtnClicked = new DelegateCommand(_ => OnStartBtnClicked(), _ => true);
        StopBtnClicked = new DelegateCommand(_ => OnStopBtnClicked(), _ => false);
        RestartBtnClicked = new DelegateCommand(_ => _gameState.RestartGame(), _ => false);
    }

    #endregion

    #region Command Methods

    private void OnGameTimerTick()
    {
        _gameState.ElpasedTime++;
        GameTimeText = $"Game time: {_gameState.ElpasedTime}";
    }

    private void OnStartBtnClicked()
    {
        // If on mobile close the menu
        if (OnMobile)
            MenuOpen = false;

        StartGame();
    }

    private void OnStopBtnClicked()
    {
        StopGame();
    }

    private void OnMenuOpened()
    {
        MenuOpen = !MenuOpen;

        if (MenuOpen)
        {
            StopGame();
        }
        else
        {
            StartGame();
        }
    }

    private void OnPlayerMove(object? param)
    {
        if (param is string key)
        {
            if (OnMobile && !MenuOpen)
                MovePlayer(key);
            else if (!OnMobile && _gameActive)
                MovePlayer(key);
        }
    }

    #endregion

    #region Private Methods

    /// <summary>
    /// Starts all of the timers and sets the execution predicates for the commands.
    /// </summary>
    private void StartGame()
    {
        _gameTimer?.Start();
        _gameActive = true;
        StartBtnClicked.Predicate = _ => false;
        StopBtnClicked.Predicate = _ => true;
    }

    /// <summary>
    /// Stops all of the timers and sets the execution predicates for the commands.
    /// </summary>
    private void StopGame()
    {
        _gameTimer?.Stop();
        _gameActive = false;
        StartBtnClicked.Predicate = _ => true;
        StopBtnClicked.Predicate = _ => false;
        RestartBtnClicked.Predicate = _ => true;
    }

    /// <summary>
    /// Sets up the given timer.
    /// </summary>
    /// <param name="timer"></param>
    /// <param name="interval"></param>
    /// <param name="tickCommand"></param>
    private void SetupTimer(ref DispatcherTimer? timer, int interval, DelegateCommand tickCommand)
    {
        timer = new DispatcherTimer();
        timer.Interval = TimeSpan.FromMilliseconds(interval);
        timer.Tick += (_, _) => tickCommand.Execute(null);
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

    #endregion
}
