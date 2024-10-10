namespace AknamezoModel.Model
{
    public class Hard : Difficulty
    {
        public override int MineIntervalMin()
        {
            return 2000;
        }

        public override int MineIntervalMax()
        {
            return 6000;
        }
    }
}
