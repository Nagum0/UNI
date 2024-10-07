namespace AknamezoModel.Model
{
    public class MediumMine : Mine
    {
        public MediumMine(int x, int y, int height, int width) : base(x, y, height, width) { }

        public override int Weight()
        {
            return 2;
        }
    }
}
