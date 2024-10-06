namespace AknamezoModel
{
    public class Ship
    {
        public int X { get; private set; }
        public int Y { get; private set; }
        public int Height { get; private set; }
        public int Width { get; private set; }
        public int Speed { get; private set; }
        public int MineIntervalSpeed { get; private set; }

        public Ship(int x, int y, int height, int width, int speed, int mineIntervalSpeed)
        {
            X = x;
            Y = y;
            Height = height;
            Width = width;
            Speed = speed;
            MineIntervalSpeed = mineIntervalSpeed;
        }

        public void ReverseDirection()
        {
            Speed = -Speed;
        }

        public void Move()
        {
            X += Speed;
        }
    }
}
