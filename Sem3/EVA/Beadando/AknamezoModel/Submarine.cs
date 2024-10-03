namespace AknamezoModel
{
    public class Submarine 
    {
        public int X { get; private set; }
        public int Y { get; private set; }
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
        }

        public void MoveLeft()
        {
            X -= Speed;
        }

        public void MoveUp()
        {
            Y -= Speed;
        }

        public void MoveDown()
        {
            Y += Speed;
        }
    }
}
