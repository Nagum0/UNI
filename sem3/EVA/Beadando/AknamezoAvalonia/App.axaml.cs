using AknamezoAvalonia.ViewModels;
using AknamezoAvalonia.Views;

using Avalonia;
using Avalonia.Controls;
using Avalonia.Controls.ApplicationLifetimes;
using Avalonia.Markup.Xaml;
using System;

namespace AknamezoAvalonia;

public partial class App : Application
{
    public override void Initialize()
    {
        AvaloniaXamlLoader.Load(this);
    }

    public override void OnFrameworkInitializationCompleted()
    {
        if (ApplicationLifetime is IClassicDesktopStyleApplicationLifetime desktop)
        {
            AknamezoViewModel viewModel = new AknamezoViewModel(false);

            desktop.MainWindow = new MainWindow
            {
                DataContext = viewModel
            };
        }
        else if (ApplicationLifetime is ISingleViewApplicationLifetime singleViewPlatform)
        {
            AknamezoViewModel viewModel = new AknamezoViewModel(true);

            singleViewPlatform.MainView = new MobileView
            {
                DataContext = viewModel
            };

            // When the size of the phone changes (when we load it too or flip it) update the sizes in the viewmodel
            singleViewPlatform.MainView.SizeChanged += (s, e) =>
            {
                viewModel.CanvasWidth = singleViewPlatform.MainView.Bounds.Width;
                viewModel.CanvasHeight = singleViewPlatform.MainView.Bounds.Height;
            };
        }

        base.OnFrameworkInitializationCompleted();
    }
}
