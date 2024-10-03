namespace AknamezoModel
{
    public class GameState
    {
        public Submarine Player { get; private set; }
        public int ElpasedTime { get; set; }
    
        public GameState(Submarine player)
        {
            Player = player;
        }
    }
}
