using AknamezoModel.Model;
using System.Text.Json;

namespace AknamezoModel.Persistance
{
    public class JsonFileManager : IFileManager
    {
        private JsonSerializerOptions jsonOptions = new  JsonSerializerOptions { WriteIndented = true };

        public void Save(GameState gameState, string filePath)
        {
            var serializedGameState = new
            {
                elapsed_time = gameState.ElpasedTime,
                difficulty = gameState.Difficulty.GetIdentifier(),
                player = new 
                {
                    x = gameState.Player.X,
                    y = gameState.Player.Y,
                    speed = gameState.Player.Speed
                },
                ships = gameState.Ships.Select(ship => new {
                    x = ship.X,
                    y = ship.Y,
                    mine_interval = ship.MineIntervalSpeed,
                    speed = ship.Speed
                }).ToList(),
                mines = gameState.Mines.Select(mine => new {
                    x = mine.X,
                    y = mine.Y,
                    type = mine.GetIdentifier()
                }).ToList()
            };
            
            

            string jsonString = JsonSerializer.Serialize(serializedGameState, jsonOptions); 

            File.WriteAllText(filePath, jsonString);
        }

        public GameState Load(string filePath)
        {
            string jsonString = File.ReadAllText(filePath);
            JsonDocument deserializedGameState = JsonDocument.Parse(jsonString);
            JsonElement root = deserializedGameState.RootElement;
            
            JsonElement player = root.GetProperty("player");
            Submarine submarine = new Submarine(
                player.GetProperty("x").GetInt32(),
                player.GetProperty("y").GetInt32(),
                player.GetProperty("speed").GetInt32(),
                50,
                50
            );

            Difficulty difficulty = root.GetProperty("difficulty").GetInt32() switch
            {
                1 => new Normal(),
                2 => new Hard(),
                3 => new Death(),
                _ => new Easy(),
            };

            GameState gameState = new GameState(submarine, difficulty);

            // Collecting the ships
            foreach (var ship in root.GetProperty("ships").EnumerateArray())
            {
                gameState.AddShip(new Ship(
                    ship.GetProperty("x").GetInt32(),
                    ship.GetProperty("y").GetInt32(),
                    50,
                    180,
                    ship.GetProperty("speed").GetInt32(),
                    difficulty.MineIntervalMin(),
                    difficulty.MineIntervalMax()
                ));
            }

            // Collecting the mines
            foreach (var mine in root.GetProperty("mines").EnumerateArray())
            {
                int x = mine.GetProperty("x").GetInt32();
                int y = mine.GetProperty("y").GetInt32();

                switch (mine.GetProperty("type").GetInt32())
                {
                    case 1:
                        gameState.AddMine(new MediumMine(x, y, 50, 50));
                        break;
                    case 2:
                        gameState.AddMine(new HeavyMine(x, y, 50, 50));
                        break;
                    default:
                        gameState.AddMine(new LightMine(x, y, 50, 50));
                        break;
                }
            }

            gameState.ElpasedTime = root.GetProperty("elapsed_time").GetInt32();

            return gameState;
        }
    }
}
