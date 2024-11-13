using System.Configuration;
using System.Data;
using System.Windows;

namespace Timers2
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);
            View.Timers2Window window = new View.Timers2Window();
            ViewModel.ViewModel viewModel = new ViewModel.ViewModel();
            window.DataContext = viewModel;
            window.Show();
        }
    }

}
