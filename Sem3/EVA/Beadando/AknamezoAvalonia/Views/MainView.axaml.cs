using Avalonia.Controls;
using Avalonia.Interactivity;
using Avalonia.Platform.Storage;

using AknamezoModel.Model;
using AknamezoModel.Persistance;
using System.IO;
using AknamezoAvalonia.ViewModels;
using System;

namespace AknamezoAvalonia.Views;

public partial class MainView : UserControl
{
    public MainView()
    {
        InitializeComponent();
    }

    /// <summary>
    /// Handle the save button's click event.
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="args"></param>
    private async void SaveBtn_Clicked(object? sender, RoutedEventArgs args)
    {
        var topLevel = TopLevel.GetTopLevel(this);

        if (topLevel == null)
            return;

        var file = await topLevel.StorageProvider.SaveFilePickerAsync(new FilePickerSaveOptions
        {
            Title = "Save game",
            FileTypeChoices = 
            [
                new FilePickerFileType("JSON")
                {
                    Patterns = [ "*.json" ]
                }
            ]
        });

        JsonFileManager jsonFileManager = new JsonFileManager();

        if (file is not null && topLevel.DataContext is AknamezoViewModel vm)
        {
            try
            {
                string filePath = file.Path.ToString().Substring(8);
                jsonFileManager.Save(vm.GameState, filePath);
            }
            catch
            {
                vm.ShowError("Error while saving game");
            }
        }
    }

    /// <summary>
    /// Handle the load button's click event.
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="args"></param>
    private async void LoadBtn_Clicked(object? sender, RoutedEventArgs args)
    {
        var topLevel = TopLevel.GetTopLevel(this);

        if (topLevel == null)
            return;

        var files = await topLevel.StorageProvider.OpenFilePickerAsync(new FilePickerOpenOptions
        {
            Title = "Load game",
            AllowMultiple = false,
            FileTypeFilter =
            [
                new FilePickerFileType("JSON")
                {
                    Patterns = [ "*.json" ]
                }
            ]
        });

        JsonFileManager jsonFileManager = new JsonFileManager();

        if (files.Count == 1 && DataContext is AknamezoViewModel vm)
        {
            try
            {
                string filePath = files[0].Path.ToString().Substring(8);
                GameState readGameState = jsonFileManager.Load(filePath);
                vm.GameState.Player = readGameState.Player;
                vm.GameState.Ships = readGameState.Ships;
                vm.GameState.Mines = readGameState.Mines;
                vm.GameState.ElpasedTime = readGameState.ElpasedTime;
            }
            catch
            {
                vm.ShowError("Error while reading saved game");
            }
        }
    }
}
