using System;

namespace Gyak2 {
    class Loops {
        /* 1.Faktorialis
            Be: n eleme R
            Ki: f eleme R
            Ef: n > 0
            Uf: minden i eleme [1..n] : i|f
        */
        public static void Main(string[] args) {

            /* 
                Be: a, b eleme N
                Ki: r eleme N
                Ef: b != 0
                Uf: b | (a - r) es r < b
            */
            int a, b;

            int.TryParse(Console.ReadLine(), out a);
            int.TryParse(Console.ReadLine(), out b);

            if (b != 0) {
                while (a >= b) {
                    a = a - b;
                }
            }

            Console.WriteLine(a);
        }
    }
    
    class Gyak2 {

        /* 1.Feladat - Akcio
            Be: eredeti_ar eleme R; learazas_merteke eleme R;
            Ki: valasz eleme S; akcios_ar eleme R
            Ef: (eredeti_ar >= 0) es (learazas_merteke >= 0)
            Uf: ha learazas_merteke >= 50 => valasz = "megeri" ha nem valasz = "nem eri meg"
                akcios_ar = eredeti_ar / learazas_merteke
        */
        static void fel1(double price, double disc) {
            string output;
            double disc_price;

            if (price >= 0 && (disc >= 0 && disc <= 100)) {
                if (disc >= 50) {
                    output = "Megeri!";
                }
                else {
                    output = "Nem eri meg!";
                }

                disc_price = (price / 100) * disc;
                Console.WriteLine($"{output} Akcios ar: {disc_price}");
            }
        }

        /* 2.Feladat - Szignum 
            Be: x eleme R
            Ki: sig eleme {-1; 0; 1}
            Ef: -
            Uf: (x = 0 => sig = 0) es (x > 0 => sig = 1) es (x < 0 => sig = -1)
        */
        static int fel2(int n) {
            if (n == 0) {
                return 0;
            }
            else if (n > 0) {
                return 1;
            }
            else {
                return -1;
            }
        }

        /* 3.Feladat - Pont 
            Be: p eleme Pont; Pont = x eleme R, y eleme R
            Ki: siknegyed eleme Z
            Ef: -
            Uf: ha (p.x > 0 && p.y > 0) => siknegyed = 1
                ha (p.x > 0 && p.y < 0) => siknegyed = 4
                ha (p.x < 0 && p.y > 0) => siknegyed = 2 
                ha (p.x < 0 && p.y < 0) => siknegyed = 3 
        */
        public struct Pont {
            public int x;
            public int y;
        }

        static int fel3(Pont p) {
            if (p.x > 0 && p.y > 0) {
                return 1;
            }
            else if (p.x > 0 && p.y < 0) {
                return 4;
            }
            else if (p.x < 0 && p.y > 0) {
                return 2;
            }
            else if (p.x < 0 && p.y < 0) {
                return 3;
            }
            else {
                return 0;
            }
        }

        /* 7.Feladat - Max
            Be: a, b, c eleme R
            Ki: max eleme R
            Ef: (a != b) es (a != c) es (b != c)
            Uf: ((a > b && a > c) => max = a) es
                ((b > a && b > c) => max = b) es
                ((c > a && c > b) => max = c)
        */
        /* static double fel7(double a, double b, double c) {
            if ((a != b) && (a != c) && (b != c)) {
                if (a > b && a > c) {
                    return a;
                }
                else if (a > )
            }
        } */

        /* public static void Main(string[] args) {
            // 1.Feladat
            double price, disc;
            double.TryParse(Console.ReadLine(), out price);
            double.TryParse(Console.ReadLine(), out disc);
            Console.Write("Feladat 1: ");
            fel1(price, disc);

            // 2.Feladat
            int n;
            int.TryParse(Console.ReadLine(), out n);
            Console.WriteLine($"Feladat 2: {fel2(n)}");

            // 3.Feladat
            Pont p;
            int.TryParse(Console.ReadLine(), out p.x);
            int.TryParse(Console.ReadLine(), out p.y);
            Console.WriteLine($"Feladat 3: {fel3(p)}");
        } */
    }
}