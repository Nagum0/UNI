using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace ELTE.StudentsList.ViewModel
{
    public class DelegateCommand : ICommand
    {
        private Action<object?> _execute;
        private Predicate<object?> _predicate;
        private bool _hasExecuted;
        public event EventHandler? CanExecuteChanged;

        public DelegateCommand(Action<object?> execute, Predicate<object?> predicate)
        {
            _execute = execute;
            _predicate = predicate;
        }

        public void Execute(object? parameter)
        {
            _execute(parameter);
            CanExecuteChanged?.Invoke(this, EventArgs.Empty);
        }

        public bool CanExecute(object? parameter)
        {
            return _predicate(parameter);
        }
    }
}
