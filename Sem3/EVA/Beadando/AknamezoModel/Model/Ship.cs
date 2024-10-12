namespace AknamezoModel.Model
{
    public class Ship
    {
        public int X { get; private set; }
        public int Y { get; private set; }
        public int Height { get; private set; }
        public int Width { get; private set; }
        public int Speed { get; private set; }
        public int MineIntervalSpeed { get; private set; }
               
        private int mineIntervalMinimum;
        private int mineIntervalMaximum;
        private Random mineIntervalGenerator;
        private Random randomMineTypeGenerator;
                                              
        public Ship(int x, int y, int height, int width, int speed, int mineIntervalMinimum, int mineIntervalMaximum)
        {
            X = x;
            Y = y;
            Height = height;
            Width = width;
            Speed = speed;
            this.mineIntervalMinimum = mineIntervalMinimum;
            this.mineIntervalMaximum = mineIntervalMaximum;
            mineIntervalGenerator = new Random();
            randomMineTypeGenerator = new Random();
            MineIntervalSpeed = mineIntervalGenerator.Next(mineIntervalMinimum, mineIntervalMaximum);
        }

        public void ReverseDirection()
        {
            Speed = -Speed;
        }

        public void Move()
        {
            X += Speed;
        }

        public Mine DropMine()
        {
            int mineType = randomMineTypeGenerator.Next(0, 3);

            switch (mineType)
            {
                case 1:
                    return new MediumMine(X + Width / 2, Y + Height / 2 + 30, 50, 50);
                case 2:
                    return new HeavyMine(X + Width / 2, Y + Height / 2 + 30, 50, 50);
                default:
                    return new LightMine(X + Width / 2, Y + Height / 2 + 30, 50, 50);
            }
        }
        
        public int ChangeMineDropInterval()
        {
            int newMineDropInterval = mineIntervalGenerator.Next(mineIntervalMinimum, mineIntervalMaximum);
            MineIntervalSpeed = newMineDropInterval;
            Console.WriteLine($"New mine interval speed: {MineIntervalSpeed}");
            return newMineDropInterval;
        }
              
        public void UpdateMineDropRate(Difficulty diff)
        {
            mineIntervalMinimum = diff.MineIntervalMin();
            mineIntervalMaximum = diff.MineIntervalMax();
        }

        // -- FOR DEBUGGING ONLY
        public override string ToString()
        {
            return $"[{mineIntervalMinimum}, {mineIntervalMaximum}] ({MineIntervalSpeed})";
        }
    }
}
