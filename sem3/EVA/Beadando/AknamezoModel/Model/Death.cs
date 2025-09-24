namespace AknamezoModel.Model
{
    public class Death : Difficulty
    {
        public override int MineIntervalMin()
        {
            return 500;
        }

        public override int MineIntervalMax()
        {
            return 3000;
        }

        public override int GetIdentifier()
        {
            return 3;
        }
    }
}
