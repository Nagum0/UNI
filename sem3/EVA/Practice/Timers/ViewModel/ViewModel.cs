using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Timers.ViewModel
{
    public class ViewModel : INotifyPropertyChanged
    {
        private string _id;
        public event PropertyChangedEventHandler? PropertyChanged;

        public ViewModel()
        {
            _id = "test";
        }

        public string Id
        {
            get { return _id; }
            set
            {
                _id = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Id)));
            }
        }
    }
}
