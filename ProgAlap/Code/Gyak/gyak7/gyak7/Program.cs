namespace gyak7
{
    internal class Program
    {
        /*
         * 1.a Feladat: (osszegzes)
         * Specifikcaio:
         *  Be: n eleme N, pontok eleme N[1..n], pontSullyok eleme N[1..n]
         *  Ki: s eleme N
         *  Ef: minden i eleme [1..n] : (0 <= pontok[i] <= 100)
         *  Uf: s = SZUMMA(i = 1..n, pontSullyok[i] * pontok[i])
         */
        static void Feladat1A()
        {
            int n;
            int.TryParse(Console.ReadLine(), out n);

            int[] pontok = new int[n];
            int[] pontSullyok = new int[n];

            for (int i = 0; i < n; i++)
            {
                string sor = Console.ReadLine();
                pontok[i] = int.Parse(sor.Split(" ")[0]);
                pontSullyok[i] = int.Parse(sor.Split(" ")[1]);
            }

            int s = 0;

            for (int i = 0; i < n; i++)
            {
                s += pontSullyok[i] * pontok[i];
            }

            Console.WriteLine(s);
        }

        /* 1.b Feladat: (masolas)
         * Specifikacio:
         *  Be: n eleme N, pontok eleme N[1..n], pontSullyok eleme N[1..n]
         *  Ki: y eleme N[1..n]
         *  Ef: minden i eleme [1..n] : (0 <= pontok[i] <= 100)
         *  Uf: y = MASOL(i = 1..n, pontok[i] * pontSullyok[i])
         */
        static void Feladat1B()
        {
            int n;
            int.TryParse(Console.ReadLine(), out n);

            int[] pontok = new int[n];
            int[] pontSullyok = new int[n];

            for (int i = 0; i < n; i++)
            {
                string sor = Console.ReadLine();
                pontok[i] = int.Parse(sor.Split(" ")[0]);
                pontSullyok[i] = int.Parse(sor.Split(" ")[1]);
            }

            int[] y = new int[n];

            for (int i = 0; i < n; i++)
            {
                y[i] = pontSullyok[i] * pontok[i];
            }

            Console.WriteLine(string.Join(" ", y));
        }

        /*
         * 2. Feladat (kivalogatas)
         * Specifikacio:
         *  Be: n eleme N, arak eleme N[1..n], penz eleme N
         *  Ki: db eleme N, y eleme N[1..db]
         *  Ef: -
         *  Uf: (db, y) = KIVALOGAT(i = 1..n, arak[i] <= penz, i)
         *  Ide a vegere azert kell az i, mert az indexeket gyujtjuk ossze!
         */
        static void Feladat2()
        {
            int n;
            int.TryParse(Console.ReadLine(), out n);

            int[] arak = new int[n];

            int penz;
            int.TryParse(Console.ReadLine(), out penz);

            List<int> y = new List<int>();

            for (int i = 0; i < n; i++)
            {
                int.TryParse(Console.ReadLine(), out arak[i]);
            }

            for (int i = 0; i < n; i++)
            {
                if (arak[i] <= penz)
                {;
                    y.Add(i);
                }
            }

            Console.WriteLine(string.Join(" ", y));
        }

        static void Main(string[] args)
        {
            //Feladat1A();
            Feladat1B();
            //Feladat2();
        }
    }
}