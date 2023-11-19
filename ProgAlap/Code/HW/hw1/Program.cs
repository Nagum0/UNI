using System;

namespace HW1 {
    class Hw1 {
        /* Forgalom 
            Specifikacio:
            Be: n eleme N, napok eleme N[1..n]
            Ki: atlag eleme R
            Ef: n > 0 es napok[i] >= 0
            Uf: atlag = ATLAG(i = 1..n, napok[i] > 0)
        */
        static int Forgalom() {
            int n;
            int atlag = 0;

            int.TryParse(Console.ReadLine(), out n);

            if (n > 0) {
                int[] napok = new int[n];

                for (int i = 0; i < n; i++) {
                    Console.Write("Nap: ");
                    int.TryParse(Console.ReadLine(), out napok[i]);
                }

                for (int i = 0; i < n; i++) {
                    Console.Write($"{napok[i]} ");
                }
                Console.Write("\n");

                for (int i = 0; i <= n; i++) {
                    if (napok[i] == 0) {
                        n--;
                    }
                    else {
                        atlag += napok[i];
                    }
                }

                return atlag / n;
            }
            else {
                Environment.Exit(1);
                return 0;
            }
        }

        /* Casino 
            Specifikacio:
            Be: n eleme N, nyeremenyek eleme N[1..n]
            Ki: min eleme N
            Ef: -
            Uf: min = MIN(i = 1..n, nyeremenyek[i])
        */
        static int Casino() {
            int n;

            int.TryParse(Console.ReadLine(), out n);
            int[] nyeremenyek = new int[n];

            for (int i = 0; i < n; i++) {
                Console.Write("Nyeremeny: ");
                int.TryParse(Console.ReadLine(), out nyeremenyek[i]);
            }

            int min = nyeremenyek[0];

            foreach (int i in nyeremenyek) {
                if (i < min) {
                    min = i;
                }
            }

            return min;
        }

        public static void Main(string[] args) {
            //int avg = Forgalom();
            //Console.WriteLine($"Avg: {avg}");

            int min = Casino();
            Console.WriteLine($"Min: {min}");
        }
    }
}