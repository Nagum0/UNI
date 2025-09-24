namespace Gyak04
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Map map = new Map();
            map.Insert(new Item(1, "asednwdhfwiuw"));
            string v1 = map[1];
            Console.WriteLine(v1);
            map.Remove(1);

            try
            {
                Console.WriteLine(map[1]);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

            map.Insert(new Item(1, "Zeki"));
            map.Insert(new Item(32, "Lmao"));
            map.Insert(new Item(2, "Lmao"));

            Console.WriteLine(map[32]);
        }
    }
}
