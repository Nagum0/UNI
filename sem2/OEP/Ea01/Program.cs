namespace Ea01
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<int> data = new List<int> {0,1,4,4,4,5,6,4,4,8};
            Bag bag = new Bag(data.Count);
            foreach (int i in data) bag.PutIn(i);
            bag.Print();
            Console.WriteLine($"Most frequent value: {bag.MostFrequent()}");
            
            try
            {
                bag.PutIn(100);
            }
            catch (Exception e) 
            {
                Console.WriteLine(e.ToString());
            }
        }
    }
}