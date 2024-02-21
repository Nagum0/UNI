namespace Gyak02
{
    class Program
    {
        static void Main(string[] args)
        {
            Complex c1 = new Complex(1, 2);
            Complex c2 = new Complex(2, 3);
            Console.WriteLine(c1 + c2);

            Complex a = new Complex(3, 2);
            Complex b = new Complex(1, 6);
            Console.WriteLine(a - b);
        }
    }
}
