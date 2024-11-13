using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Timers2.ViewModel
{
    public class DelegateCommand : ICommand
    {
        public Action<object?> _execute;
        public Predicate<object?> _predicate;
        public event EventHandler? CanExecuteChanged;

        public DelegateCommand(Action<object?> execute, Predicate<object?> predicate) 
        {
            _execute = execute;
            _predicate = predicate;
        }

        public void Execute(object parameter)
        {
            if (CanExecute(parameter))
                _execute(parameter);
        }

        public bool CanExecute(object parameter)
        {
            return _predicate(parameter);
        }
    }
}
