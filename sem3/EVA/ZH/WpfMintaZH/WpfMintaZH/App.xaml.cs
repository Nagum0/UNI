using System.Configuration;
using System.Data;
using System.Windows;

namespace WpfMintaZH
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);
            MainWindow window = new MainWindow();
            ViewModel viewModel = new ViewModel();
            window.DataContext = viewModel;
            window.Show();
        }
    }
}
