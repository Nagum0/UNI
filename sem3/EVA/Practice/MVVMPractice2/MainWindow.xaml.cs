using System.ComponentModel;
using System.Runtime.CompilerServices;
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

namespace MVVMPractice2
{
    public class Person : INotifyPropertyChanged
    {
        private string _name;
        public event PropertyChangedEventHandler? PropertyChanged;

        public void OnPropertyChanged([CallerMemberName] string? name = null)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
            }
        }

        public string Name
        {
            get { return _name; }
            set
            {
                if (value != _name)
                {
                    _name = value;
                    OnPropertyChanged("Name");
                }
            }
        }
    }

    public partial class MainWindow : Window
    {
        private Person p;

        public MainWindow()
        {
            InitializeComponent();
            p = new Person();
            nameTextBlock.DataContext = p;
            p.Name = "Zeki";
        }

        private void changeNameBtn_Click(object sender, RoutedEventArgs e)
        {
            p.Name = "Astolfo";
        }
    }
}