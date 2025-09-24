using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Threading;

namespace Timers2.ViewModel
{
    public class ViewModel : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler? PropertyChanged;
        private int _id;
        private ObservableCollection<string> _names;
        private string _textBox1Value;
        private DispatcherTimer _mainTimer;
        private Thickness _minePosition;
        private int _mineX = 150;
        private int _mineY = 180;
        public DelegateCommand ClickMeCmd { get; set; }

        public ViewModel()
        {
            _id = 10;
            _names = ["Zeki", "Dani", "Astolfo", "Felix"];
            _textBox1Value = "";
            _mainTimer = new DispatcherTimer();
            _mainTimer.Interval = TimeSpan.FromMilliseconds(16);
            _mainTimer.Tick += new EventHandler(MainTimer_Tick);
            _mainTimer.Start();
            _minePosition = new Thickness(_mineX, _mineY, 0, 0);
            ClickMeCmd = new DelegateCommand(
                    _ => _names.Add(_textBox1Value),
                    _ => true
                );
        }

        private void MainTimer_Tick(object sender, EventArgs e)
        {
            _mineY += 1;
            MinePosition = new Thickness(_mineX, _mineY, 0, 0);
        }

        public int Id
        {
            get => _id;
            set
            {
                _id = value;
                OnPropertyChanged();
            }
        }

        public ObservableCollection<string> Names
        {
            get { return _names; }
        }

        public string TextBox1Value
        {
            get => _textBox1Value;
            set
            {
                _textBox1Value = value;
                OnPropertyChanged();
            }
        }

        public Thickness MinePosition
        {
            get => _minePosition;
            private set
            {
                _minePosition = value;
                OnPropertyChanged();
            }
        }

        private void OnPropertyChanged([CallerMemberName] string? propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
