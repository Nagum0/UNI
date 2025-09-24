namespace Gyak10
{
    public enum Sex
    {
        MALE,
        FEMALE
    }

    public class Game
    {
        public double weight;
        protected Sex sex;

        protected Game(double weight, Sex sex)
        {
            this.weight = weight;
            this.sex = sex;
        }
        public Sex getSex()
        {
            return sex;
        }
    }
}
