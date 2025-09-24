using System;

namespace EA3 {
    class Ea3 {
        /* Papirgyujtes 
            Specifikacio:
            Be: n eleme N, kg eleme N[1..n]
            Ki: ossz eleme N
            Ef: n > 0, kg[i] > 0
            Uf: ossz = SZUMMA(i = 1..n, kg[i])
        */
        static int Papirgyujtes() {
            int n;
            int ossz = 0;

            Console.Write("Diakok szama: ");
            int.TryParse(Console.ReadLine(), out n);

            if (n > 0) {
                int[] kg = new int[n];

                for (int i = 0; i < n; i++) {
                    Console.Write("Kg: ");
                    int.TryParse(Console.ReadLine(), out kg[i]);
                }

                foreach(int i in kg) {
                    ossz += i;
                }

                return ossz;
            }
            else {
                Console.WriteLine("Hiba az adatmegadasnal!");
                Environment.Exit(1);
            }

            return 1;
        }

        /* Skalaris szorzat 
            Specifikacio:
            Be: n eleme N, a eleme Z[1..n], b eleme Z[1..n]
            Ki: s eleme Z
            Ef: -
            Uf: s = SZUMMA(i=1..n, a[i] * b[i])
        */
        static int SkalarisSzorzat() {
            int s = 0;
            int n;

            Console.Write("n: ");
            int.TryParse(Console.ReadLine(), out n);

            Random rnd = new Random();

            int[] a = new int[n];
            int[] b = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = rnd.Next(0, 10);
                b[i] = rnd.Next(0, 10);
            }

            for (int i = 0; i < n; i++) {
                s += a[i] * b[i];
            }

            return s;
        }

        /* Szamok osszege 
            Specifikacio:
            Be: a eleme Z, b eleme Z
            Ki: s eleme Z
            Ef: a <= b
            Uf: s = SZUMMA(i = a..b, i)
        */
        static int SzamokOsszege() {
            int a, b;
            int s = 0;

            Console.Write("a: ");
            int.TryParse(Console.ReadLine(), out a);

            Console.Write("b: ");
            int.TryParse(Console.ReadLine(), out b);

            if (a <= b) {
                for (int i = a; i <= b; i++) {
                    if (i % 2 == 0) {
                        s += i;
                    }
                    else {
                        continue;
                    }
                }

                return s;
            }
            else {
                Console.WriteLine("Hiba az adatmegadasnal!");
                Environment.Exit(1);

                return 0;
            }
        }

        /* EviVagyon
            Specifikacio:
            Be: n eleme N, jov eleme Jovedelem[1..n],
                Jovedelem = Be x Ki, Be eleme N, Ki eleme N
            Ki: s eleme N
            Ef: -
            Uf: s = SZUMMA(i = 1..n, CalcJov(i))
        */
        public struct Jovedelem {
            public int Be;
            public int Ki;
        }

        static int CalcJov(Jovedelem jov) {
            return jov.Be - jov.Ki;
        }

        static int EviVagyon() {
            int s = 0;

            int n;
            int.TryParse(Console.ReadLine(), out n);

            Jovedelem[] jov = new Jovedelem[n];

            Random rnd = new Random();

            for (int i = 0; i < n; i++) {
                jov[i].Be = rnd.Next(-1000, 1000);
                jov[i].Ki = rnd.Next(-1000, 1000);
            }

            foreach (Jovedelem i in jov) {
                s += CalcJov(i);
            }

            return s;
        }

        // -- Dia: 56

        public static void Main(string[] args) {
            //int ossz = Papirgyujtes();
            //Console.WriteLine($"Papir kg: {ossz}");

            //int s = SkalarisSzorzat();
            //Console.WriteLine($"Skalaris szorzat: {s}");

            //int s = SzamokOsszege();
            //Console.WriteLine($"Szamok osszege: {s}");

            int jov = EviVagyon();
            Console.WriteLine($"Nott vagyon: {jov}");
        }
    }
}