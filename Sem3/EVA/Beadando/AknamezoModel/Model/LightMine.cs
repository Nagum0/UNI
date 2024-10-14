namespace AknamezoModel.Model
{
    public class LightMine : Mine
    {
        public LightMine(int x, int y, int height, int width) : base(x, y, height, width) { }

        public override int Weight()
        {
            return 1;
        }

        public override int GetIdentifier()
        {
            return 0;
        }
    }
}
