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
}
