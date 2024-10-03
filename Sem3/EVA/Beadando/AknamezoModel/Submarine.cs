namespace AknamezoModel
{
    public class Submarine 
    {
        public int X { get; private set; }
        public int Y { get; private set; }
        public int Speed { get; private set; }

        public Submarine(int x, int y, int speed)
        {
            X = x; 
            Y = y;
            Speed = speed;
        }

        public void MoveRight()
        {
            X += Speed;
        }
    }
}
