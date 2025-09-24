namespace Gyak11
{
    public class Dummy
    {
        private string name;

        public Dummy(string name)
        {   
            this.name = name;
        }

        public bool IsDivisible(int a, int b)
        {
            if (b == 0)
                throw new ArgumentException("0");
            return a % b == 0;
        }

        public string GetName()
        {
            return name;
        }

        public void ChangeName(string name)
        {
            this.name = name;
        }
    }
}
