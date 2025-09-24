using AknamezoModel.Model;

namespace PropChangeTest.ViewModels;

public class MainViewModel : ViewModelBase
{
    #region Fields
    private Submarine _player;
    #endregion

    #region Properties
    public int CanvasWidth { get; private set; } = 1000;
    public int CanvasHeight { get; private set; } = 500;

    public Submarine Player
    {
        get => _player;
        set {
            _player = value;
        }
    }
    #endregion

    #region Commands
    public DelegateCommand MoveRightClicked { get; private set; }
    #endregion

    public MainViewModel()
    {
        _player = new Submarine(100, 100, 5, 50, 50);
        MoveRightClicked = new DelegateCommand(_ => MoveRightCommand(), _ => true);
    }

    private void MoveRightCommand()
    {
        Player.MoveRight();
    }
}
