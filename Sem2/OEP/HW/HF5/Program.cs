namespace HF5 {
    internal class Program {
        public static void Main(string[] args) {
            double s = 0.0;
            int db = 0;
            StreamReader x = new StreamReader(args[0]);
            double e = double.Parse(x.ReadLine());

            while (!x.EndOfStream && e >= 0) {
                s = s + e;
                db++;
                e = double.Parse(x.ReadLine());
            }

            double a = s / db;
            bool l = true;
            double kicsi = e;
            e = double.Parse(x.ReadLine());

            while (!x.EndOfStream) {
                l = l && e < 0;

                if (e < kicsi) {
                    kicsi = e;
                }

                e = double.Parse(x.ReadLine());
            }

            l = l && e < 0;

            Console.WriteLine(a);
            Console.WriteLine(l);
            Console.WriteLine(kicsi);
        }
    }
}
