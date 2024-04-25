namespace Gyak10
{
    public class Elephant : Game
    {
        public double left;
        public double right;

        public Elephant(double left, double right, double weight, Sex sex) : base(weight, sex)
        {
            this.left = left;
            this.right = right;
        }
    }
}
