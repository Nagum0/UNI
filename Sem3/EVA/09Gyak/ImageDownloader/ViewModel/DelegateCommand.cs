using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace ELTE.ImageDownloader.ViewModel
{
    public class DelegateCommand : ICommand
    {
        private Action<object?> _execute;
        private Predicate<object?>? _canExecute;
        public event EventHandler? CanExecuteChanged;

        public DelegateCommand(Action<object?> execute, Predicate<object?>? canExecute = null)
        {
            if (_execute == null)
            {
                throw new ArgumentNullException(nameof(execute));
            }

            _execute = execute;
            _canExecute = canExecute;
        }

        public bool CanExecute(object? parameter)
        {
            return _canExecute == null ? true : _canExecute(parameter);
        }

        public void Execute(object? parameter)
        {
            if (!CanExecute(parameter))
            {
                throw new InvalidOperationException("Execution is disabled.");
            }

            _execute(parameter);
        }

        public void RaiseCanExecuteChanged()
        {
            CanExecuteChanged?.Invoke(this, EventArgs.Empty);
        }
    }
}
