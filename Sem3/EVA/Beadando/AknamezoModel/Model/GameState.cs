namespace AknamezoModel.Model
{
    public class GameState
    {
        public Submarine Player { get; private set; }
        public List<Ship> Ships { get; private set; }
        public List<Mine> Mines { get; private set; }
        public int ElpasedTime { get; set; }
        public Difficulty Difficulty { get; private set; }

        public GameState(Submarine player, Difficulty difficulty)
        {
            Player = player;
            Ships = new List<Ship>();
            Mines = new List<Mine>();
            Difficulty = difficulty;
        }

        public void ChangeDifficulty(Difficulty diff)
        {
            Difficulty = diff;

            // Update the mine drop rate for each ship after difficulty change!
            foreach (Ship ship in Ships)
            {
                ship.UpdateMineDropRate(diff);
            }
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
