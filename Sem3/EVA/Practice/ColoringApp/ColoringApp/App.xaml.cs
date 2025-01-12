using System.Configuration;
using System.Data;
using System.Windows;
using System.Windows.Input;

namespace ColoringApp
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
            ViewModel vm = new ViewModel();
            window.DataContext = vm;
            window.Show();
        }
    }
}
