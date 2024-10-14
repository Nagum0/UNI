namespace AknamezoModel.Model
{
    public abstract class Difficulty 
    {
        public abstract int MineIntervalMin();
        public abstract int MineIntervalMax();
        public abstract int GetIdentifier();
    }
}
