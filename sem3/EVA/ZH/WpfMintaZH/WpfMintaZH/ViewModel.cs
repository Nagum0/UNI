using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows;

namespace WpfMintaZH
{   
    public class ViewModel : ViewModelBase
    {
        public Model Model { get; set; }
        public DelegateCommand Step { get; private set; }

        public ViewModel()
        {
            Model = new Model();

            Step = new DelegateCommand(
                param =>
                {
                    if (param is Field f)
                    {
                        Model.UpdateFields(f);
                    }
                },
                _ => true
            );
        }
    }
}
