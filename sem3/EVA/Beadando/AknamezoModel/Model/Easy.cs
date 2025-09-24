namespace AknamezoModel.Model
{
    public class Easy : Difficulty
    {
        public override int MineIntervalMin()
        {
            return 4000;
        }

        public override int MineIntervalMax()
        {
            return 8000;
        }

        public override int GetIdentifier()
        {
            return 0;
        }
    }
}
