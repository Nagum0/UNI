namespace Gyak01
{
    public class Soap
    {
        // Fields:
        private int full;
        private int portion;
        private int actual;

        // Methods:
        public Soap(int f, int p)
        {
            full = f;
            portion = p;
            actual = 0;
        }

        public void Take()
        {
            actual = actual - portion > 0 ? actual - portion : 0;
        }

        public void Fill()
        {
            // Pass
        }
    }
}
