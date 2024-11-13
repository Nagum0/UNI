using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AknamezoModel.Model;

namespace AknamezoViewModel
{
    public class AknamezoViewModel
    {
        private GameState _gameState;

        public AknamezoViewModel()
        {
            _gameState = new GameState(
                new Submarine(50, 50, 50, 50, 50),
                new Easy()
            );
            _gameState.AddMine(new LightMine(50, 50, 50, 50));
            _gameState.AddMine(new HeavyMine(150, 50, 50, 50));
            _gameState.AddMine(new MediumMine(250, 50, 50, 50));
        }

        public GameState GameState
        {
            get => _gameState;
        }
    }
}
