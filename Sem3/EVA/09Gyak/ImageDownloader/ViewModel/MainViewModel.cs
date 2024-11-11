using ELTE.ImageDownloader.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace ELTE.ImageDownloader.ViewModel
{
    public class MainViewModel : ViewModelBase
    {
        private WebPage _model;
        private bool _isDownloading;
        private float _progress;
        private DelegateCommand _downloadCommand;
        private ObservableCollection<BitmapImage> _images;

        public MainViewModel()
        {
            Images = new ObservableCollection<BitmapImage>();
            DownloadCommand = new DelegateCommand(
                async (url) => 
                {
                    Uri uri = (Uri)url;
                    await LoadAsync(uri);
                }, 
                (_) => 
                { 
                    return !IsDownloading; 
                }
            );
        }

        public async Task LoadAsync(Uri url)
        {
            IsDownloading = true;
            Images.Clear();
            _model = new WebPage(url);
            _model.ImageLoaded += OnImageLoaded;
            _model.LoadProgress += OnLoadProgress;
            await _model.LoadImagesAsync();
            IsDownloading = false;
        }

        private void OnLoadProgress(object? sender, int e)
        {
            Progress = e;
        }

        private void OnImageLoaded(object? sender, WebImage e)
        {
            var bitmap = new BitmapImage();
            bitmap.BeginInit();
            bitmap.StreamSource = new MemoryStream(e.Data);
            bitmap.EndInit();
            Images.Add(bitmap);
        }

        public WebPage Model 
        {
            get { return _model; }
            private set
            {
                _model = value;
                OnPropertyChanged();
            }
        }

        public bool IsDownloading
        {
            get { return _isDownloading; }
            private set
            {
                _isDownloading = value;
                OnPropertyChanged();
                DownloadCommand.RaiseCanExecuteChanged();
            }
        }

        public float Progress
        {
            get { return _progress; }
            private set 
            { 
                _progress = value; 
                OnPropertyChanged();
            }
        }

        public DelegateCommand DownloadCommand
        {
            get { return _downloadCommand; }
            private set
            {
                _downloadCommand = value;
                OnPropertyChanged();
            }
        }

        public ObservableCollection<BitmapImage> Images
        {
            get { return _images; }
            private set
            {
                _images = value;
                OnPropertyChanged();
            }
        }
    }
}
