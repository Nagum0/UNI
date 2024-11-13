using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Rectangles.ViewModel
{
    public class DelegateCommand : ICommand
    {
        /// <summary>
        /// Signals whether the execution policy has changed.
        /// </summary>
        public event EventHandler? CanExecuteChanged;

        private Action<object?> _execute;
        private Predicate<object?> _predicate;

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
    }
}
