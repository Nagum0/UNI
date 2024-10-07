/**
 * 1. ship1 setup
 * 2. ship1_Tick(...)
 * 3. Throw mine
 * 4. get random ship1 mine interval
 * 5. ship1_Tick(...)
 * 6. Throw mine
 * 7. ...
 */

namespace AknamezoModel
{
    public class GameState
    {
        public Submarine Player { get; private set; }
        public List<Ship> Ships { get; private set; }
        public List<Mine> Mines { get; private set; }
        public int ElpasedTime { get; set; }
    
        public GameState(Submarine player)
        {
            Player = player;
            Ships = new List<Ship>();
            Mines = new List<Mine>();
        }

        public void AddShip(Ship ship)
        {
            Ships.Add(ship);
        }

        public void AddMine(Mine mine)
        {
            Mines.Add(mine);
        }

        public bool MineHit()
        {
            int playerXWidth = Player.X + Player.Width;
            int playerYHeight = Player.Y + Player.Height;

            foreach (Mine mine in Mines)
            {
                int mineXWidth = mine.X + mine.Width;
                int mineYHeight = mine.Y + mine.Height;
            
                if ((Player.X < mineXWidth && mine.X < playerXWidth) &&
                    (Player.Y < mineYHeight && mine.Y < playerYHeight))
                {
                    return true;
                }
            }

            return false;
        }
    }
}
