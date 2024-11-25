using ELTE.ImageDownloader.Model;
using System.Collections.Generic;

namespace ImageDownloader.ViewModels;

public class MainViewModel : ViewModelBase
{
    private WebPage? _model;
    private bool _isDownloading;
    private float _progress;
    private static List<string> SupportedExtensions { get; set; }

    public MainViewModel()
    {

    }


}
