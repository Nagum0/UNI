using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace AknamezoModel.Model
{
    public class Submarine : INotifyPropertyChanged 
    {
        public event PropertyChangedEventHandler? PropertyChanged;

        public int X { get; set; }
        public int Y { get; set; }
        public int Speed { get; private set; }
        public int Height { get; private set; }
        public int Width { get; private set; }

        public Submarine(int x, int y, int speed, int height, int width)
        {
            X = x; 
            Y = y;
            Speed = speed;
            Height = height;
            Width = width;
        }

        public void MoveRight()
        {
            X += Speed;
            OnPropertyChanged(nameof(X));
        }

        public void MoveLeft()
        {
            X -= Speed;
            OnPropertyChanged(nameof(X));
        }

        public void MoveUp()
        {
            Y -= Speed;
            OnPropertyChanged(nameof(Y));
        }

        public void MoveDown()
        {
            Y += Speed;
            OnPropertyChanged(nameof(Y));
        }

        /// <summary>
        /// Invokes the PropertyChanged event with the given property.
        /// </summary>
        /// <param name="property">If null then it uses the CallerMemberName.</param>
        private void OnPropertyChanged([CallerMemberName] string? property = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));
        }
    }
}
