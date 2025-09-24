using AknamezoAvalonia.ViewModels;
using Avalonia.Controls;

namespace AknamezoAvalonia.Views;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    /// <summary>
    /// Handles the keydown event on the window for desktop platforms.
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void Window_KeyDown(object? sender, Avalonia.Input.KeyEventArgs e)
    {
        if (DataContext is AknamezoViewModel vm)
        {
            switch (e.Key)
            {
                case Avalonia.Input.Key.W:
                    vm.MovePlayerCmd.Execute("W");
                    break;
                case Avalonia.Input.Key.S:
                    vm.MovePlayerCmd.Execute("S");
                    break;
                case Avalonia.Input.Key.A:
                    vm.MovePlayerCmd.Execute("A");
                    break;
                case Avalonia.Input.Key.D:
                    vm.MovePlayerCmd.Execute("D");
                    break;
            }
        }
    }
}
