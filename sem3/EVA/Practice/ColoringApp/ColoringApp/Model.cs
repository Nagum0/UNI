using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ColoringApp
{
    public enum Color
    {
        White,
        Red,
        Green,
        Blue,
    }

    public class Cell : PropChanged
    {
        private Color _color;

        public int X { get; set; }
        public int Y { get; set; }
        public Color Color
        {
            get => _color;
            set {
                _color = value;
                OnPropertyChanged();
            }
        }

        public Cell(int x, int y)
        {
            X = x;
            Y = y;
            _color = Color.White;
        }
    }

    public class Model : PropChanged
    {
        public int CanvasHeight { get; private set; } = 15;
        public int CanvasWidth { get; private set; } = 50;
        public ObservableCollection<Cell> Cells { get; set; }

        public Model()
        {
            Cells = new ObservableCollection<Cell>();
            InitCells();
        }

        public void Color(Cell cell, Color color)
        {
            for (int i = 0; i < Cells.Count; i++)
            {
                if (cell.X == Cells[i].X && cell.Y == Cells[i].Y)
                    Cells[i].Color = color;
            }
        }

        private void InitCells()
        {
            for (int i = 0; i < CanvasHeight; i++)
            {
                for (int j = 0; j < CanvasWidth; j++)
                {
                    Cells.Add(new Cell(i, j));
                }
            }
        }
    }
}
