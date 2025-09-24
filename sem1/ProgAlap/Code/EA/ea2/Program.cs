using System;

namespace EA2 {
    class Ea2 {
        /* Vercsoport 1
            Specfikacio:
            Be: gen1 eleme C, gen2 eleme C
            Ki: v eleme S
            Ef: (gen1 = '+' vagy gen1 = '-') es (gen2 = '+' vagy gen2 = '-')
            Uf: (gen1 = '+' es gen2 = '-') vagy
                (gen1 = '+' es gen2 = '+' -> v = "Rh+") es 
                (nem(gen1 = '-' es gen2 = '-') -> v = "Rh-")
        */

        /* Vercsoport 2 
            Specifikacio:
            Be: x eleme C, y eleme C
            Ki: v elme S
            Ef: (x = 'a' vagy x = 'b' vagy x = '0') es
                (y = 'a' vagy y = 'b' vagy y = '0')
            Uf: ((x = 'a' es y != 'b' vagy x != 'b' es y = 'a') -> v = "A") es
                ((x = 'b' es y != 'a' vagy x != 'a' es y = 'b')) -> v = "B")) es
                ((x = 'a' es y = 'b' vagy x = 'b' es y = 'a') -> v = "AB") es
                ((x = '0' es y = '0') -> v = "0")
        */
        static void Vercsoport() {
            char x, y;
            string v;

            Console.Write("x: ");
            char.TryParse(Console.ReadLine(), out x);

            Console.Write("y: ");
            char.TryParse(Console.ReadLine(), out y);

            if ((x == 'a' || x == 'b' || x == '0') && (y == 'a' || y == 'b' || y == '0')) {
                if ((x == 'a' && y != 'b') || (x != 'b' && y == 'a')) {
                    v = "A";
                }
                else if ((x == 'b' && y != 'a') || (x != 'a' && y == 'b')) {
                    v = "B";
                }
                else if ((x == 'a' && y == 'b') || (x == 'b' && y == 'a')) {
                    v = "AB";
                }
                else {
                    v = "0";
                }

                Console.WriteLine($"Vercsoport: {v}");
            }
            else {
                Console.WriteLine("Adat hiba!");
                Environment.Exit(1);
            }
        }

        /* Paratlan oszto szumma
            Specifikacio:
            Be: n eleme N 
            Ki: s eleme N
            Ef: n > 0
            Uf: s = SZUMMA(i = 1..n, i, i|n es paratlan(i))
        */
        static int Szumma() {
            int n;
            int s = 0;

            Console.Write("n: ");
            int.TryParse(Console.ReadLine(), out n);

            if (n > 0) {
                for (int i = 1; i <= n; i++) {
                    if (n % i == 0 && i % 2 == 0) {
                        s += i;
                    }
                    else {
                        continue;
                    }
                }
            }
            else {
                Console.WriteLine("Hiba az adatbeolvasasnal!");
                Environment.Exit(1);
            }

            return s;
        }
        /* Siknegyed
            Specifkacio:
            Be: p eleme Pont
                Pont = X x Y; X eleme R, Y eleme R
            Ki: sn eleme N
            Ef: -
            Uf: ((p.x > 0 es p.y > 0) -> sn = 1) es
                ((p.x < 0 es p.y > 0) -> sn = 2) es
                ((p.x < 0 es p.y < 0) -> sn = 3) es
                ((p.x > 0 es p.y < 0) -> sn = 4) es
                ((p.x = 0 es p.y = 0) -> sn = 0)
        */
        public struct Pont {
            public int x;
            public int y;
        }

        static int Siknegyed() {
            Pont p;
            int sn;

            Console.Write("X: ");
            int.TryParse(Console.ReadLine(), out p.x);

            Console.Write("Y: ");
            int.TryParse(Console.ReadLine(), out p.y);

            if (p.x > 0 && p.y > 0) {
                sn = 1;
            }
            else if (p.x < 0 && p.y > 0) {
                sn = 2;
            }
            else if (p.x < 0 && p.y < 0) {
                sn = 3;
            }
            else if (p.x > 0 && p.y < 0) {
                sn = 4;
            }
            else {
                sn = 0;
            }

            return sn;
        }

        /* Szamok 1-99 kozt szavakkal:
            Specifikacio:
            Be: n eleme N,
                EGYES eleme S[0..9] = ("egy".."kilenc"),
                TIZES eleme S[0..9] = ("tizen".."kilencven")
            Ki: s eleme S
            Ef: n >= 1 es n <= 99
            Uf: ((n > 10 es n mod 10 != 0) -> s = TIZES((n div 10) - 1) + EGYES((n mod 10) - 1)) es
                ((n > 10 es n mod 10 == 0) -> s = TIZES((n div 10) - 1)) es
                ((n < 10) -> s = EGYES(n - 1)) es
                ((n = 10) -> s = "tiz") es
                ((n = 20) -> s = "husz")
        */
        static string IntToString() {
            int n;
            string s = "";
            string[] Egyes = {"egy", "ketto", "harom", "negy",  "ot", "hat", "het", "nyolc", "kilenc"};
            string[] Tizes = {"tizen", "huszon", "harminc", "negyven", "otven", "hatvan", "hetven", "nyolcvan", "kilencven"};
            
            Console.Write("n: ");
            int.TryParse(Console.ReadLine(), out n);

            if (n >= 1 && n <= 99) {
                if (n == 10) {
                    s = "tiz";
                }
                else if (n == 20) {
                    s = "husz";
                }
                else if (n > 10 && n % 10 != 0) {
                    s = Tizes[(n / 10) - 1] + Egyes[(n % 10) - 1];
                }
                else if (n > 10 && n % 10 == 0) {
                    s = Tizes[(n / 10) - 1];
                }
                else if (n < 10) {
                    s = Egyes[n - 1];
                }
            }
            else {
                Console.WriteLine("Hiba az adatmegadasnal!");
                Environment.Exit(1);
            }

            return s;
        }

        public static void Main(string[] args) {
            //Vercsoport();

            //int s = Szumma();
            //Console.WriteLine($"Szumma: {s}");

            //int sn = Siknegyed();
            //Console.WriteLine($"Siknegyed: {sn}");

            string s = IntToString();
            Console.WriteLine($"szam: {s}");
        }
    }
}