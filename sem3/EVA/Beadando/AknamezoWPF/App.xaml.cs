using System.Configuration;
using System.Data;
using System.Windows;

namespace AknamezoWPF
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);
            View.AknamezoWindow window = new View.AknamezoWindow();
            AknamezoViewModel.AknamezoViewModel viewModel = new AknamezoViewModel.AknamezoViewModel();
            window.DataContext = viewModel;
            window.Show();
        }
    }
}
