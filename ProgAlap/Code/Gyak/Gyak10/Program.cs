namespace Gyak10
{
    class Program
    {
        static List<H> Filter<H>(List<H> xs, Func<int, bool>? T = null)
        {
            List<H> result = new List<H>();
            
            for (int i = 0; i < xs.Count; i++)
            {
                if (T == null || T(i))
                {
                    result.Add(xs[i]);
                }
            }

            return result;
        }

        static List<HOut> Map<HIn, HOut>(List<HIn> xs, Func<HIn, HOut> T)
        {
            List<HOut> result = new List<HOut>();
            
            for (int i = 0; i < xs.Count; i++)
            {
                result.Add(T(xs[i]));
            }

            return result;
        }

        static void Main(string[] args)
        {
            List<int> ints = new List<int> {1,2,3,4,5};
            List<int> f_xs = Filter(ints, i => ints[i] % 2 == 0);
            Console.WriteLine(string.Join(", ", f_xs));

            List<int> m_xs = Map(ints, i => i + 1);
            Console.WriteLine(string.Join(", ", m_xs));
        }
    }
}