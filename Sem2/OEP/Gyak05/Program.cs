namespace Gyak05
{
    public struct Kaktusz
    {
        public string nev;
        public string szin;
        public string os;
    }

    public enum Status
    {
        NORMAL,
        ABNORMAL,
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            /*
            List<string> p = new List<string>();
            List<string> m = new List<string>();

            using StreamReader inFile = new StreamReader(args[0]);
            string[] input;
            Status st = Status.ABNORMAL;
            Kaktusz e = new Kaktusz();
            input = inFile.ReadLine().Split();
            
            if (input[0] != "")
            {
                e.nev = input[0];
                e.szin = input[1];
                e.os = input[2];
                st = Status.NORMAL;
            }

            while (!inFile.EndOfStream)
            {
                if (e.szin == "piros")
                    p.Add(e.nev);
                if (e.os == "mexiko")
                    m.Add(e.nev);

                input = inFile.ReadLine().Split();
                if (input[0] != "")
                {
                    e.nev = input[0];
                    e.szin = input[1];
                    e.os = input[2];
                    st = Status.NORMAL;
                }
                else
                    st = Status.ABNORMAL;
            }
            
            foreach (string nev in p)
                Console.Write($"{nev} ");

            Console.WriteLine();

            foreach (string nev in m)
                Console.Write($"{nev} ");
            */

            int e;
            using StreamReader inFile = new StreamReader(args[0]);
            string input;
            int m = 0;
            bool l = true;

            while (!inFile.EndOfStream)
            {
                input = inFile.ReadLine();
                e = int.Parse(input);
                if (e > m)
                    m = e;
                l = l && e % 2 == 0;
                Console.WriteLine($"{m} {l}");  
            }
        }
    }
}
