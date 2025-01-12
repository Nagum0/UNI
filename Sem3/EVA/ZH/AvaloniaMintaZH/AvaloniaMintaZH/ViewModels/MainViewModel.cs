using Avalonia.Threading;
using ReactiveUI;
using System;

namespace AvaloniaMintaZH.ViewModels;

public class MainViewModel : ViewModelBase
{
    private int _time = 0;
    private string _timeText = "Time: 0";
    private string _castleHealthText = "Castle: 3";
    private string _soldiersText = "Soldiers: 0";
    private string _moneyText = "Money: 2";

    public Model Model { get; set; }
    public DispatcherTimer _gameTimer;
    public DelegateCommand BuySoldierCmd { get; set; }
    public DelegateCommand PlaceSoldierCmd { get; set; }

    public string TimeText
    {
        get => _timeText;
        private set
        {
            _timeText = value;
            this.RaisePropertyChanged();
        }
    }
    public string CastleHealthText
    {
        get => _castleHealthText;
        private set
        {
            _castleHealthText = value;
            this.RaisePropertyChanged();
        }
    }
    public string SoldiersText
    {
        get => _soldiersText;
        private set
        {
            _soldiersText = value;
            this.RaisePropertyChanged();
        }
    }

    public string MoneyText
    {
        get => _moneyText;
        private set
        {
            _moneyText = value;
            this.RaisePropertyChanged();
        }
    }

    public MainViewModel()
    {
        Model = new Model();
        Model.CastleHit += Model_CastleHit;
        TimeText = $"Time: {_time}";
        CastleHealthText = $"Castle: {Model.CastleHealth}";
        SoldiersText = $"Soldiers: {Model.AvailableSoldiers}";
        MoneyText = $"Money: {Model.Money}";

        _gameTimer = new DispatcherTimer();
        _gameTimer.Interval = TimeSpan.FromSeconds(2);
        _gameTimer.Tick += GameTimer_Tick;
        _gameTimer.Start();

        BuySoldierCmd = new DelegateCommand(
            _ =>
            {
                Model.BuySoldier();
                MoneyText = $"Money: {Model.Money}";
                SoldiersText = $"Soldiers: {Model.AvailableSoldiers}"; 
            },
            _ => true
        );
        PlaceSoldierCmd = new DelegateCommand(
            _ => { },
            _ => true
        );
    }

    private void GameTimer_Tick(object? sender, EventArgs e)
    {
        _time++;
        TimeText = $"Time: {_time}";
        Model.Update();
        Model.GenerateRandomEnemies();
    }

    private void Model_CastleHit(object? sender, EventArgs args)
    {
        if (Model.CastleHealth <= 0)
        {
            CastleHealthText = "DEAD XD";
            _gameTimer.Stop();
        }
        else
            CastleHealthText = $"Castle: {Model.CastleHealth}";
    }
}
