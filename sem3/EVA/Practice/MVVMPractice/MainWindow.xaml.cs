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

namespace MVVMPractice
{
    class Person
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
    }

    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            Person p = new Person { FirstName = "Zeki", LastName = "Bene" };
            textBox2.DataContext = p;

            List<Person> ps = [
                    new Person { FirstName = "Zeki", LastName = "Bene" },
                    new Person { FirstName = "Dani", LastName = "Bene" },
                    new Person { FirstName = "Felix", LastName = "Argyle" },
                    new Person { FirstName = "John", LastName = "Doe" }
                ];
            comboBox.DataContext = ps;
        }

        private void textBox1_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}