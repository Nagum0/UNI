using System.Configuration;
using System.Data;
using System.Windows;

namespace Rectangles
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);
            View.MainWindow window = new View.MainWindow();
            ViewModel.MainViewModel viewModel = new ViewModel.MainViewModel();
            window.DataContext = viewModel;
            window.Show();
        }
    }

}
