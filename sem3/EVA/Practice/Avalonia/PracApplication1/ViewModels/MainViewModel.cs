using CommunityToolkit.Mvvm;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using AknamezoModel.Model;

namespace PracApplication1.ViewModels;

public partial class MainViewModel : ViewModelBase
{
    [ObservableProperty]
    private string _greetingMessage;

    private Submarine _player;

    public Submarine Player
    {
        get => _player;
        set => SetProperty(ref _player, value);
    }

    public MainViewModel()
    {
        _greetingMessage = "Hello, World!";
        _player = new Submarine(50, 50, 5, 30, 100);
    }

    [RelayCommand]
    public void ChangeGreetingMessage()
    {
        GreetingMessage = "Hola, Amigo!";
    }

    [RelayCommand]
    public void ChangePlayerX()
    {
        Player.X += 10;
    }
}
