using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace ColoringApp
{
    public class ViewModel : PropChanged
    {
        public Model Model { get; private set; }
        public Color SelectedColor { get; private set; } = Color.White;

        public DelegateCommand ColorRect { get; private set; }
        public DelegateCommand SelectColor { get; private set; }

        public ViewModel()
        {
            Model = new Model();

            ColorRect = new DelegateCommand(
                cell =>
                {
                    if (cell is Cell c)
                    {
                        Model.Color(c, SelectedColor);
                    }
                },
                _ => true
            );

            SelectColor = new DelegateCommand(
                c =>
                {
                    if (c is Color color)
                    {
                        SelectedColor = color;
                    }
                },
                _ => true
            );
        }
    }
}
