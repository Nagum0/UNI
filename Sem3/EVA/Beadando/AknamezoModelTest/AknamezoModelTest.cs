using AknamezoModel.Model;
using AknamezoModel.Persistance;

namespace AknamezoModelTest
{
    [TestClass]
    public class AknamezoModelTest
    {
        [TestMethod]
        public void MineHitTest()
        {
            GameState gameState = new GameState(
                new Submarine(50, 50, 500, 50, 50),
                new Easy()
            );

            gameState.AddMine(new LightMine(150, 150, 50, 50));
            gameState.AddMine(new MediumMine(50, 50, 50, 50));
            
            // Test collision
            bool eventWasRaised = false;
            gameState.MineCollison += (sender, args) => eventWasRaised = true;
            gameState.MineHit();
            Assert.IsTrue(eventWasRaised);

            // Test no collision
            eventWasRaised = false;
            gameState.Player.MoveRight();
            gameState.MineHit();
            Assert.IsFalse(eventWasRaised);
        }

        [TestMethod]
        public void DifficultyChangeTest()
        {
            GameState gameState = new GameState(
                new Submarine(50, 50,500, 50, 50),
                new Easy()
            );

            gameState.AddShip(new Ship(
                50,
                50,
                100,
                100,
                75,
                gameState.Difficulty.MineIntervalMin(),
                gameState.Difficulty.MineIntervalMax()
            ));

            Hard hard = new Hard();
            gameState.ChangeDifficulty(hard);
            
            Assert.AreEqual(
                gameState.Ships[0].MineIntervalMinimum,
                hard.MineIntervalMin()
            );
            Assert.AreEqual(
                gameState.Ships[0].MineIntervalMaximum,
                hard.MineIntervalMax()
            );
        }

        [TestMethod]
        public void GameMovementTest()
        {
            Submarine sub = new Submarine(50, 50, 50, 50, 50);
            sub.MoveRight();
            sub.MoveUp();
            sub.MoveLeft();
            sub.MoveDown();
            sub.MoveDown();
            Assert.AreEqual(sub.X, 50);
            Assert.AreEqual(sub.Y, 100);

            LightMine lm = new LightMine(50, 50, 50, 50);
            lm.Sink();
            Assert.AreEqual(lm.Y, 51);

            MediumMine mm = new MediumMine(50, 50, 50, 50);
            mm.Sink();
            Assert.AreEqual(mm.Y, 52);
            
            HeavyMine hm = new HeavyMine(50, 50, 50, 50);
            hm.Sink();
            Assert.AreEqual(hm.Y, 53);
            
            Ship ship = new Ship(5, 5, 50, 50, 10, 4000, 8000);
            ship.Move();
            Assert.AreEqual(ship.X, 15);
            ship.ReverseDirection();
            ship.Move();
            Assert.AreEqual(ship.X, 5);
        }

        [TestMethod]
        public void RestartGameTest()
        {
            GameState gameState = new GameState(
                new Submarine(50, 50, 500, 50, 50),
                new Death()
            );

            gameState.AddMine(new LightMine(150, 150, 50, 50));
            gameState.AddMine(new MediumMine(50, 50, 50, 50));

            gameState.AddShip(
                new Ship(5, 5, 50, 50, 10, 4000, 8000)
            );

            gameState.AddShip(
                    new Ship(5, 5, 50, 50, 10, 4000, 8000)
            );
            gameState.AddShip(
                    new Ship(5, 5, 50, 50, 10, 4000, 8000)
            );

            gameState.RestartGame();
            
            Assert.AreEqual(gameState.ElpasedTime, 0);
            Assert.AreEqual(gameState.Mines.Count, 0);
            Assert.IsInstanceOfType(gameState.Difficulty, new Easy().GetType());
            Assert.AreEqual(gameState.Player.X, OriginalGameState.PLAYER_START_X);
            Assert.AreEqual(gameState.Player.Y, OriginalGameState.PLAYER_START_Y);
            Assert.AreEqual(gameState.Ships[0].X, OriginalGameState.SHIP1_START_X);
            Assert.AreEqual(gameState.Ships[1].X, OriginalGameState.SHIP2_START_X);
            Assert.AreEqual(gameState.Ships[2].X, OriginalGameState.SHIP3_START_X);
            Assert.AreEqual(gameState.Ships[0].Y, OriginalGameState.SHIP1_START_Y);
            Assert.AreEqual(gameState.Ships[1].Y, OriginalGameState.SHIP2_START_Y);
            Assert.AreEqual(gameState.Ships[2].Y, OriginalGameState.SHIP3_START_Y);
        }

        [TestMethod]
        public void SaveAndLoadGameTest()
        {
            GameState gameState = new GameState(
                new Submarine(50, 50, 500, 50, 50),
                new Death()
            );

            gameState.AddMine(new LightMine(150, 150, 50, 50));
            gameState.AddMine(new MediumMine(50, 50, 50, 50));

            gameState.AddShip(
                new Ship(5, 5, 50, 50, 10, 4000, 8000)
            );

            gameState.AddShip(
                new Ship(5, 5, 50, 50, 10, 4000, 8000)
            );

            gameState.AddShip(
                new Ship(5, 5, 50, 50, 10, 4000, 8000)
            );
            
            // Saving the game
            JsonFileManager jfm = new JsonFileManager();

            try 
            {
                jfm.Save(gameState, "save_test.json");
            }
            catch (Exception) 
            {
                Console.Error.WriteLine("Error while saving file.");
                Assert.Fail();
            }

            // Loading up the file that was saved
            try
            {
                GameState loadedState = jfm.Load("save_test.json");
                
                for (int i = 0; i < gameState.Ships.Count; i++)
                {
                    Assert.AreEqual(gameState.Ships[i].X, loadedState.Ships[i].X);
                    Assert.AreEqual(gameState.Ships[i].Y, loadedState.Ships[i].Y);
                    Assert.AreEqual(gameState.Ships[i].Speed, loadedState.Ships[i].Speed);
                    Assert.AreEqual(gameState.Ships[i].MineIntervalSpeed, loadedState.Ships[i].MineIntervalSpeed);
                }
            }
            catch (Exception)
            {
                Console.Error.WriteLine("Error while reading file.");
                Assert.Fail();
            }
        }
    }
}
