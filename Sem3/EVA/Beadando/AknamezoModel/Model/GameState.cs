using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace AknamezoModel.Model
{
    public class GameState : INotifyPropertyChanged
    {
        public Submarine _player;
        public ObservableCollection<Ship> _ships;
        public ObservableCollection<Mine> _mines;
        public int _elpased_time;
        public Difficulty Difficulty { get; private set; }
        
        public event PropertyChangedEventHandler? PropertyChanged;
        public event EventHandler? MineCollison;

        public GameState(Submarine player, Difficulty difficulty)
        {
            _player = player;
            _ships = new ObservableCollection<Ship>();
            _mines = new ObservableCollection<Mine>();
            Difficulty = difficulty;
        }

        public Submarine Player
        {
            get => _player;
            set
            {
                _player = value;
                OnPropertyChanged();
            }
        }

        public ObservableCollection<Ship> Ships
        {
            get => _ships;
            set
            {
                _ships = value;
                OnPropertyChanged();
            }
        }

        public ObservableCollection<Mine> Mines
        {
            get => _mines;
            set
            {
                _mines = value;
                OnPropertyChanged();
            }
        }

        public int ElpasedTime
        {
            get => _elpased_time;
            set
            {
                _elpased_time = value;
                OnPropertyChanged();
            }
        }
        
        public void ChangeDifficulty(Difficulty diff)
        {
            //Console.WriteLine($"Difficulty changed: {diff}");

            Difficulty = diff;
            
            // Update the mine drop rate for each ship after difficulty change
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

        public void MineHit()
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
                    MineCollison?.Invoke(this, EventArgs.Empty);
                }
            }
        }

        public void RestartGame()
        {
            // Resetting player position
            Player.X = OriginalGameState.PLAYER_START_X;
            Player.Y = OriginalGameState.PLAYER_START_Y;
            
            // Resetting the ships locations
            Ships[0].ResetLocation(
                OriginalGameState.SHIP1_START_X, 
                OriginalGameState.SHIP1_START_Y
            );
            Ships[1].ResetLocation(
                OriginalGameState.SHIP2_START_X,
                OriginalGameState.SHIP2_START_Y
            );
            Ships[2].ResetLocation(
                OriginalGameState.SHIP3_START_X,
                OriginalGameState.SHIP3_START_Y
            );
             
            // Removing mines
            Mines.Clear();
            
            // Changing the difficulty back to easy
            ChangeDifficulty(new Easy());

            // Reset the ship directions
            foreach (Ship ship in Ships)
            {
                ship.Speed = Math.Abs(ship.Speed);
            }

            // Reset the elapsed time
            ElpasedTime = 0;
        }

        private void OnPropertyChanged([CallerMemberName] string? property = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));
        }

        // -- FOR DEBUGGING
        public override string ToString()
        {
            System.Text.StringBuilder sbr = new();

            sbr.Append($"GAME STATE ({ElpasedTime}):\n");
            
            sbr.Append($"DIFFICULTY:\n  {Difficulty}\n");

            sbr.Append($"PLAYER:\n  X: {Player.X} Y: {Player.Y}\n");

            sbr.Append("  SHIPS:\n");
            for (int i = 0; i < Ships.Count; i++)
            {
                sbr.Append($"    Ship[{i}] {Ships[i]}");
            }
            
            sbr.Append("\n  MINES:\n");
            sbr.Append($"    {string.Join(", ", Mines)}");

            return sbr.ToString();
        }
    }
}
