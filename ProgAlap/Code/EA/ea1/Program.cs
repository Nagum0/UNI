using System;
using System.Diagnostics;

namespace EA1 {
    class Ea1 {
        /* Sebesseg 
            Specifikacio:
            Be: s eleme R, t eleme R
            Ki: v eleme R
            Ef: s >= 0 es t > 0
            Uf: v = s/t
        */
        static void Speed() {
            double s, t, v;

            Console.Write("s: ");
            double.TryParse(Console.ReadLine(), out s);

            Console.Write("t: ");
            double.TryParse(Console.ReadLine(), out t);

            if (s >= 0 && t > 0) {
                v = s / t;

                Console.WriteLine($"v: {v} km/h");  
            }
            else {
                Console.WriteLine("Hiba az adatoknal!");
                Environment.Exit(1);
            }
        }

        /* Haromszog
            Specifikacio:
            Be: a elem R, b eleme R, c eleme R
            Ki: lehet elem L
            Ef: a > 0 es b > 0 es c > 0
            Uf: (a^2 + b^2 = c^2 -> lehet = igaz) es
                (a^2 + b^2 != c^2 -> lehet = hamis)
        */
        static void Haromszog() {
            double a, b, c;
            bool lehet;

            Console.Write("a: ");
            double.TryParse(Console.ReadLine(), out a);

            Console.Write("b: ");
            double.TryParse(Console.ReadLine(), out b);

            Console.Write("c: ");
            double.TryParse(Console.ReadLine(), out c);

            if (a > 0 && b > 0 && c > 0) {
                if (c * c == a * a + b * b) {
                    lehet = true;
                }
                else {
                    lehet = false;
                }

                Console.WriteLine($"Lehet: {lehet}");
            }
            else {
                Console.WriteLine("Hiba az adat megadasnal!");
                Environment.Exit(1);
            }
        }

        /* Masodfoku egyenlet egy megoldasa
            Specifikacio:
            Be: a eleme R, b eleme R, c eleme R
            Ki: x elem R, van eleme L
            Ef: a != 0
            Uf: van = (b^2 - 4 * a * c >= 0) es 
                van -> x = -b + sqrt(b^2 - 4 * a * c) / 2a
        */
        static void Masodfoku() {
            double a, b, c;
            double x;
            bool van;

            Console.Write("a: ");
            double.TryParse(Console.ReadLine(), out a);

            Console.Write("b: ");
            double.TryParse(Console.ReadLine(), out b);

            Console.Write("c: ");
            double.TryParse(Console.ReadLine(), out c);

            if (a != 0) {
                double d = Math.Sqrt(Math.Pow(b, 2) - 4 * a * c);
                van = d >= 0;

                if (van) {
                    x = (b * (-1) + d) / 2 * a;
                    Console.WriteLine($"x = {x}");
                }
                else {
                    Console.WriteLine("Nincs megoldas!");
                    Environment.Exit(0);
                }
            }
            else {
                Console.WriteLine("Az a nem lehet 0!");
                Environment.Exit(1);
            }
        }

        public static void Main(string[] args) {
            //Speed();
            //Haromszog();
            Masodfoku();
        }
    }
}