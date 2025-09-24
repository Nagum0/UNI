using ImageDownloader.Model;
using System.IO;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ImageDownloader
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private WebPage _model;

        public MainWindow()
        {
            InitializeComponent();
        }

        private async void LoadImagesBtn_Click(object sender, RoutedEventArgs e)
        {
            ImageCounterTextBlock.Text = "Number of images: 0";
            ImageProgressBar.Visibility = Visibility.Visible;
            LoadImagesBtn.IsEnabled = false;
            ImgWrapPanel.Children.Clear();
            _model = new WebPage(new Uri(UrlTextBox.Text));
            _model.ImageLoaded += _model_ImageLoaded;
            _model.LoadProgress += _model_LoadProgress;
            await _model.LoadImageAsync();
            LoadImagesBtn.IsEnabled = true;
            ImageProgressBar.Visibility = Visibility.Hidden;
        }

        private void _model_LoadProgress(object? sender, int e)
        {
            ImageProgressBar.Value = e;
        }

        private void _model_ImageLoaded(object? sender, WebImage e)
        {
            BitmapImage bitmap = new BitmapImage();
            bitmap.BeginInit();
            bitmap.StreamSource = new MemoryStream(e.Data);
            bitmap.EndInit();
            
            Image img = new Image();
            img.Width = 100;
            img.Height = 100;
            img.Source = bitmap;
            ImgWrapPanel.Children.Add(img);
        }
    }
}