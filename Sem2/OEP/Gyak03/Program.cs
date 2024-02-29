namespace Gyak03
{
    internal class Program
    {
        static void Main(string[] args)
        {
            LTM a = new LTM(3);
            try
            {
                a[0, 2] = 3;
            }
            catch (LTMException) { Console.WriteLine("LMAO"); }
            catch (Exception e) { Console.WriteLine(e.ToString()); }
        }
    }
}
