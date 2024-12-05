using AknamezoAvalonia.ViewModels;
using AknamezoModel.Model;
using AknamezoModel.Persistance;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Interactivity;
using Avalonia.Markup.Xaml;
using Avalonia.Platform.Storage;
using System;
using System.IO;

namespace AknamezoAvalonia;

public partial class MobileView : UserControl
{
    public MobileView()
    {
        InitializeComponent();
    }

    /// <summary>
    /// Handle the save button's click event.
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="args"></param>
    private async void SaveBtn_Clicked(object? sender, RoutedEventArgs e)
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

        if (file is not null && DataContext is AknamezoViewModel vm)
        {
            string jsonString = jsonFileManager.Serialize(vm.GameState);
            await using var stream = await file.OpenWriteAsync();
            using var streamWriter = new StreamWriter(stream);
            await streamWriter.WriteLineAsync(jsonString);
        }
        else if (DataContext is AknamezoViewModel vm2)
        {
            vm2.ShowError("File is null");
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
                string filePath = files[0].Path.ToString();
                GameState readGameState = jsonFileManager.Load(filePath);
                vm.GameState.Player = readGameState.Player;
                vm.GameState.Ships = readGameState.Ships;
                vm.GameState.Mines = readGameState.Mines;
                vm.GameState.ElpasedTime = readGameState.ElpasedTime;
            }
            catch (Exception e)
            {
                vm.ShowError($"Error while reading saved game\n{e.Message}");
            }
        }
    }
}