namespace Ea01
{
    public class Bag
    {
        // Fields:
        private int m;
        private int max;
        private List<int> bag = new List<int>();

        // Methods:
        public Bag(int m)
        {
            this.m = m;
            max = 0;
            for (int i = 0; i < m; i++) bag.Add(0);
        }

        public void PutIn(int val)
        {
            if (val > m) throw new Exception();

            bag[val]++;
            if (bag[val] > max) max = val;
        }

        public int MostFrequent()
        {
            if (max <= 0) throw new Exception();
            return max;
        }

        public void Print()
        {
            Console.WriteLine($"Size: {m}");
            Console.WriteLine($"Bag: {string.Join(", ", bag)}");
        }
    }
}
