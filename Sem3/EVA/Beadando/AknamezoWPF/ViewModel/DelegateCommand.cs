using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace AknamezoViewModel
{
    public class DelegateCommand : ICommand
    {
        private Action<object?> _execute;
        private Predicate<object?> _predicate;

        public event EventHandler? CanExecuteChanged;

        public Predicate<object?> Predicate
        {
            get => _predicate;
            set
            {
                _predicate = value;
                RaiseCanExecuteChanged();
            }
        }

        public DelegateCommand(Action<object?> execute, Predicate<object?> predicate)
        {
            _execute = execute;
            _predicate = predicate;
        }

        public void Execute(object? param)
        {
            if (CanExecute(param))
                _execute(param);
        }

        public bool CanExecute(object? param)
        {
            return _predicate(param);
        }

        public void RaiseCanExecuteChanged()
        {
            CanExecuteChanged?.Invoke(this, EventArgs.Empty);
        }
    }
}

