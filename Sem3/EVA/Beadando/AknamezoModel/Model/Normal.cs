namespace AknamezoModel.Model
{
    public class Normal : Difficulty
    {
        public override int MineIntervalMin()
        {
            return 3000;
        }

        public override int MineIntervalMax()
        {
            return 7000;
        }
    }
}
