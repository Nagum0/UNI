using System;

namespace Gyak3 {
    class Gyak3 {
        /* 1.Papirgyujtes
            Specifikacio:
            Be: n eleme R [1..n]
            Ki: x eleme R
            Ef: minden i eleme [1..n] : t[i] > 0
            Uf: x = SZUMMA(i=1..n, i, i|n)
        */
        static double Papirgyujtes(double[] data) {
            double sum = 0;

            foreach (double i in data) {
                if (i <= 0) {
                    continue;
                }
                sum += i;
            }
            
            return sum;
        }

        /* 3.Pokerverseny
            Specifikacio: - minimumos
            Be: n eleme N, t eleme S [1..n]
            Ki: v eleme S
            Ef: n > 0
            Uf: v = t[1]
        */
        
        /* 5.Nyaralas
            Specifikacio:
            Be: n eleme N, t eleme R [1..n]
            Ki: x eleme N
            Ef: (n > 0) es (t[i] >= 0) 
            Uf: 
        */

        /* HF - 7,8 */

        public static void Main(string[] args) {
            double[] data = {25.6, 18.9, 67.6, -100.0, 42.2};
            Console.WriteLine(Papirgyujtes(data));
        }
    }
}