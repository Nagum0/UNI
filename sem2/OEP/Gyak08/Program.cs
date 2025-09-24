namespace Gyak08
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Potato pt = Potato.Instance();
            Potato pt2 = Potato.Instance();
            Console.WriteLine($"pt1: {pt.GetHarvestTime()}; pt2: {pt2.GetHarvestTime()}");
        }
    }
}
