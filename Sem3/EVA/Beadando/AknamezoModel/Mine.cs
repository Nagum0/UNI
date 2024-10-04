/**
 * TODOs:
 *      - Different mine types.
 */

namespace AknamezoModel
{
    public class Mine
    {
        public int X { get; private set; }
        public int Y { get; private set; }
        public int Weight { get; private set; }
        public int Height { get; private set; }
        public int Width { get; private set; }

        public Mine(int x, int y, int weight, int height, int width)
        {
            X = x;
            Y = y;
            Weight = weight;
            Height = height;
            Width = width;
        }

        public void Sink()
        {
            Y += Weight;
        }
    }
}
