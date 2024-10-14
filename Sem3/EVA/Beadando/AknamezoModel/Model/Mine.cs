namespace AknamezoModel.Model
{
    public abstract class Mine
    {
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
        }
    }
}
