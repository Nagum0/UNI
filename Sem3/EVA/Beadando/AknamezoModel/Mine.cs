namespace AknamezoModel
{
    public abstract class Mine
    {
        public int X { get; private set; }
        public int Y { get; private set; }
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

        public void Sink()
        {
            Y += Weight();
        }
    }
}
