namespace AknamezoModel
{
    public class GameState
    {
        public Submarine Player { get; private set; }
        public List<Ship> Ships { get; private set; }
        public int ElpasedTime { get; set; }
    
        public GameState(Submarine player)
        {
            Player = player;
            Ships = new List<Ship>();
        }

        public void AddShip(Ship ship)
        {
            Ships.Add(ship);
        }

        /*
        public bool MineHit()
        {
            int playerXWidth = Player.X + Player.Width;
            int playerYHeight = Player.Y + Player.Height;
            int mineXWidth = Mine.X + Mine.Width;
            int mineYHeight = Mine.Y + Mine.Height;

            return (Player.X < mineXWidth && Mine.X < playerXWidth) &&
                   (Player.Y < mineYHeight && Mine.Y < playerYHeight);
        }
        */
    }
}
