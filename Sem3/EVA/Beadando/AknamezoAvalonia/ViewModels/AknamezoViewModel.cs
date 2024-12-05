using AknamezoModel.Model;
using AknamezoModel.Persistance;
using Avalonia.Controls;
using Avalonia.Threading;
using ReactiveUI;
using System;
using System.IO;
using System.Threading.Tasks;
using Avalonia.Platform.Storage;

namespace AknamezoAvalonia.ViewModels;

public class AknamezoViewModel : ViewModelBase
{
    #region Fields

    private double _canvasWidth = 1000;
    private double _canvasHeight = 500;
    private bool _menuOpen = true; // Used for mobile version to check whether the menu needs to be visible.
    private bool _gameActive = false;
    private string _gameTimeText = "Game time: 0";
    private string _deathMessage = "YOU DIED\nTotal gametime: 0";
    private bool _deathScreenIsEnabled = false;

    private int _playerStartX = 400;
    private int _playerStartY = 300;
    private int _ship1StartX = OriginalGameState.SHIP1_START_X;
    private int _ship1StartY = OriginalGameState.SHIP1_START_Y;
    private int _ship2StartX = OriginalGameState.SHIP2_START_X;
    private int _ship2StartY = OriginalGameState.SHIP2_START_Y;
    private int _ship3StartX = OriginalGameState.SHIP3_START_X;
    private int _ship3StartY = OriginalGameState.SHIP3_START_Y;

    private DispatcherTimer? _gameTimer;
    private DispatcherTimer? _gameLoopTimer;
    private DispatcherTimer? _ship1MineTimer;
    private DispatcherTimer? _ship2MineTimer;
    private DispatcherTimer? _ship3MineTimer;

    private GameState _gameState;

    #endregion

    #region Properties

    public bool DeathScreenIsEnabled
    {
        get => _deathScreenIsEnabled;
        private set
        {
            _deathScreenIsEnabled = value;
            this.RaisePropertyChanged(nameof(DeathScreenIsEnabled));
        }
    }

    public string DeathMessage
    {
        get => _deathMessage;
        private set {
            _deathMessage = value;
            this.RaisePropertyChanged(nameof(DeathMessage));
        }
    }

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
    public DelegateCommand SaveGameBtnClicked { get; set; }
    public DelegateCommand AcceptDeathCmd { get; set; }

    #endregion

    #region Public Methods

    public AknamezoViewModel(bool onMobile)
    {
        OnMobile = onMobile;

        if (OnMobile)
            CalculateSpawnPositionsForMobile();

        // -- MODEL:
        Submarine player = new Submarine(_playerStartX, _playerStartY, 50, 50, 50);
        _gameState = new GameState(player, new Easy());
        _gameState.MineCollison += GameState_MineCollision;

        // -- TIMERS:
        SetupTimer(
            ref _gameTimer,
            1000,
            new DelegateCommand(
                _ => OnGameTimerTick(),
                _ => true
            )
        );
        SetupTimer(
            ref _gameLoopTimer,
            16,
            new DelegateCommand(
                _ => OnGameLoopTimerTick(),
                _ => true
            )
        );

        // -- SHIPS:
        SetupShips();

        // -- COMMANDS:
        // -- FOR MOBILE VERSION: Opens the menu
        OpenMenuCmd = new DelegateCommand(_ => OnMenuOpened(), _ => true);
        MovePlayerCmd = new DelegateCommand(key => OnPlayerMove(key), _ => true);
        StartBtnClicked = new DelegateCommand(_ => OnStartBtnClicked(), _ => true);
        StopBtnClicked = new DelegateCommand(_ => OnStopBtnClicked(), _ => false);
        RestartBtnClicked = new DelegateCommand(_ => OnRestartBtnClicked(), _ => false);
        SaveGameBtnClicked = new DelegateCommand(_ => SaveGame(), _ => true);
        AcceptDeathCmd = new DelegateCommand(_ => OnAcceptDeathCmd(), _ => false);
    }

    /// <summary>
    /// Opens the death screen and shows the error message.
    /// </summary>
    /// <param name="message">The error message.</param>
    public void ShowError(string message)
    {
        MenuOpen = false;
        DeathMessage = message;
        DeathScreenIsEnabled = true;

        MovePlayerCmd.Predicate = _ => false;
        StartBtnClicked.Predicate = _ => false;
        StopBtnClicked.Predicate = _ => false;
        RestartBtnClicked.Predicate = _ => false;
        AcceptDeathCmd.Predicate = _ => true;
    }

    #endregion

    #region Event Handlers

    private void GameState_MineCollision(object? sender, EventArgs e)
    {
        StopGame();
        DeathMessage = $"\tYOU DIED\nTotal gametime: {_gameState.ElpasedTime}";
        DeathScreenIsEnabled = true;

        OpenMenuCmd.Predicate = _ => false;
        MovePlayerCmd.Predicate = _ => false;
        StartBtnClicked.Predicate = _ => false;
        StopBtnClicked.Predicate = _ => false;
        RestartBtnClicked.Predicate = _ => false;
        AcceptDeathCmd.Predicate = _ => true;
    }

    #endregion

    #region Command Methods

    private void OnGameLoopTimerTick()
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

    private void OnAcceptDeathCmd()
    {
        DeathScreenIsEnabled = false;

        OpenMenuCmd.Predicate = _ => true;
        MovePlayerCmd.Predicate = _ => true;
        StartBtnClicked.Predicate = _ => true;
        StopBtnClicked.Predicate = _ => false;
        RestartBtnClicked.Predicate = _ => true;
        AcceptDeathCmd.Predicate = _ => false;
    }

    private void OnGameTimerTick()
    {
        _gameState.ElpasedTime++;
        GameTimeText = $"Game time: {_gameState.ElpasedTime}";

        switch (_gameState.ElpasedTime)
        {
            case 10:
                _gameState.ChangeDifficulty(new Normal());
                break;
            case 15:
                _gameState.ChangeDifficulty(new Hard());
                break;
            case 20:
                _gameState.ChangeDifficulty(new Death());
                break;
            default:
                break;
        }
    }

    private void OnRestartBtnClicked()
    {
        _gameState.RestartGame();

        // This is to update the player location immediatly
        GameState.Player.MoveLeft();
        GameState.Player.MoveUp();
            
        // If we're on mobile change the spawn locations correctly
        if (OnMobile)
        {
            _gameState.Ships[0].ResetLocation(_ship1StartX, _ship1StartY);
            _gameState.Ships[1].ResetLocation(_ship2StartX, _ship2StartY);
            _gameState.Ships[2].ResetLocation(_ship3StartX, _ship3StartY);
        }
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
        _gameLoopTimer?.Start();
        _ship1MineTimer?.Start();
        _ship2MineTimer?.Start();
        _ship3MineTimer?.Start();

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
        _gameLoopTimer?.Stop();
        _ship1MineTimer?.Stop();
        _ship2MineTimer?.Stop();
        _ship3MineTimer?.Stop();

        _gameActive = false;
        StartBtnClicked.Predicate = _ => true;
        StopBtnClicked.Predicate = _ => false;
        RestartBtnClicked.Predicate = _ => true;
    }

    /// <summary>
    /// Saves the game state in a json format.
    /// 
    /// DOESN'T WORK LIKE THIS
    /// </summary>
    private void SaveGame()
    {
        try
        {
            if (OperatingSystem.IsAndroid())
            {
                // Plan for mobile:
                //  - Close the menu
                //  - Open deathscreen but with a textbox
                //  - User enters name for save file
                //  - We get that and save it
            }
            else
            {

            }
        }
        catch
        {
            MenuOpen = false;
            DeathMessage = "Error while saving game";
            DeathScreenIsEnabled = true;

            MovePlayerCmd.Predicate = _ => false;
            StartBtnClicked.Predicate = _ => false;
            StopBtnClicked.Predicate = _ => false;
            RestartBtnClicked.Predicate = _ => false;
            AcceptDeathCmd.Predicate = _ => true;
        }
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
    /// Sets up the ships and their mine drop timers.
    /// </summary>
    private void SetupShips()
    {
        // -- SHIP 1
        _gameState.AddShip(
           new Ship(
               _ship1StartX,
               _ship1StartY,
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
                _ship2StartX,
                _ship2StartY,
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
                _ship3StartX,
                _ship3StartY,
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
    /// Calculates the spawn positions for the ships and the player depending on the platform.
    /// </summary>
    private void CalculateSpawnPositionsForMobile()
    {
        _ship1StartX = 500;
        _ship1StartY = OriginalGameState.SHIP1_START_Y;

        _ship2StartX = 400;
        _ship2StartY = OriginalGameState.SHIP2_START_Y;

        _ship3StartX = 300;
        _ship3StartY = OriginalGameState.SHIP3_START_Y;
    }

    #endregion
}
