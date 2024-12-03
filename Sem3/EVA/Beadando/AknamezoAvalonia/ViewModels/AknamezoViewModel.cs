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
    private bool _menuOpen = false; // Used for mobile version to check whether the menu needs to be visible.

    private GameState _gameState;

    #endregion

    #region Properties

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

    #endregion

    #region Commands

    public DelegateCommand OpenMenuCmd { get; set; }
    public DelegateCommand MovePlayerCmd { get; set; }

    #endregion

    #region Public Methods

    public AknamezoViewModel()
    {
        // -- MODEL:
        Submarine player = new Submarine(400, 200, 50, 50, 50);
        _gameState = new GameState(player, new Easy());

        // -- COMMANDS:
        // -- FOR MOBILE VERSION: Opens the menu
        OpenMenuCmd = new DelegateCommand(_ => MenuOpen = !MenuOpen, _ => true);
        MovePlayerCmd = new DelegateCommand(key =>
        {
            if (key is string k)
                MovePlayer(k);
        }, _ => true);
    }

    #endregion

    #region Private Methods

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
