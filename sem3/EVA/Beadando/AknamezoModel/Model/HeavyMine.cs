namespace AknamezoModel.Model
{
    public class HeavyMine : Mine
    {
        public HeavyMine(int x, int y, int height, int width) : base(x, y, height, width) { }

        public override int Weight()
        {
            return 3;
        }

        public override int GetIdentifier()
        {
            return 2;
        }
    }
}
