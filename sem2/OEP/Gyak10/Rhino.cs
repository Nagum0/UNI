namespace Gyak10
{
    public class Rhino : Game
    {
        public double horn;

        public Rhino(double horn, double weight, Sex sex) : base(weight, sex)
        {
            this.horn = horn;
        }
    }
}
