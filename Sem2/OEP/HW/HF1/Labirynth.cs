namespace HF1
{
    public class Labirynth
    {
        private Content[,] map;

        public Labirynth(Content[,] map)
        {
            this.map = map;
        }

        public Content WhatIsThere(int x, int y, Direction dir)
        {
            int x_check = x + dir.x;
            int y_check = y + dir.y;

            if (!(0 <= x_check && x_check <= map.GetLength(0) && 0 <= y_check && y_check <= map.GetLength(1)) && (x_check == 0 || y_check == 0))
            {
                throw new Exception();
            }

            return map[x_check, y_check];
        }

        public void Collect(int x, int y)
        {
            if (map[x, y] != Content.TREASURE)
            {
                throw new Exception();
            }
            
            map[x, y] = Content.EMPTY;
        }
    }
}
