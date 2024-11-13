using System.ComponentModel;

namespace AknamezoModel.Model
{
    public abstract class Mine : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler? PropertyChanged;

        public int X { get; set; }
        public int Y { get; set; }
        public int Height { get; private set; }
        public int Width { get; private set; }

        public Mine(int x, int y, int height, int width)
        {
            X = x;
            Y = y;
            Height = height;
            Width = width;
        }

        public abstract int Weight();
        public abstract int GetIdentifier();

        public void Sink()
        {
            Y += Weight();
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Y)));
        }
    }
}
