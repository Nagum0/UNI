namespace AknamezoModel
{
    public class GameState
    {
        public Submarine Player { get; private set; }
        public int ElpasedTime { get; set; }
        
        // -- TESTING MINE
        public Mine Mine { get; private set; }
    
        public GameState(Submarine player, Mine mine)
        {
            Player = player;
            Mine = mine;
        }

        public bool MineHit()
        {
            int playerXWidth = Player.X + Player.Width;
            int playerYHeight = Player.Y + Player.Height;
            int mineXWidth = Mine.X + Mine.Width;
            int mineYHeight = Mine.Y + Mine.Height;

            return (Player.X < mineXWidth && Mine.X < playerXWidth) &&
                   (Player.Y < mineYHeight && Mine.Y < playerYHeight);
        }
    }
}
