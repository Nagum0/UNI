namespace Gyak06
{
    public struct Receipt
    {
        public string cName;
        public List<Item> items;
    }

    public struct Item
    {
        public int id;
        public int price;
    }

    public class Program
    {
        static void Main(string[] args)
        {
            // 1.Feladat
            IntEnum test = new IntEnum(args[0]);
            int db_pos = 0;
            int db_neg = 0;
            bool neg = false;

            foreach (int i in test)
            {
                if (i < 0)
                    neg = true;

                if (!neg && i % 2 == 0)
                    db_pos = i;
                else if (i % 2 == 0)
                    db_neg++;
            }

            Console.WriteLine(db_pos);
            Console.WriteLine(db_neg);


        }
    }
}
