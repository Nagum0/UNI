using System;

namespace GYAK4 {
    class Gyak4 {
        public static string[] PAKLI = {"a", "f", "k", "7", "8", "9", "10", "A"};
        public static int[] ERTEK = {2, 3, 5, 7, 8, 9, 10, 11};

        /* 1.Kartya 
            Specifikacio:
            Be: PAKLI eleme S[0..7](a, f, k, 7, 8, 9, 10, A),
                ERTEK eleme N[0..7](2, 3, 5, 7, 8, 9, 10, 11),
                kartya eleme S
            Ki: ertek eleme N
            Ef: kartya eleme PAKLI
            Uf: ertek = ERTEK[KIVALASZT(i = 0..7, PAKLI[i] == kar]
        */
        static void MagyarKartya() {
            Console.Write("Kartya: ");
            string? kartya = Console.ReadLine();

            for (int i = 0; i < PAKLI.Length; i++) {
                if (kartya == PAKLI[i]) {
                    Console.WriteLine(ERTEK[i]);
                }
            }
        }

        /* 2.Kartyajatek
            Specifikacio: 
            Be: db eleme N, k eleme S[1..db],
                PAKLI eleme S[0..7](a, f, k, 7, 8, 9, 10, A),
                ERTEK eleme N[0..7](2, 3, 5, 7, 8, 9, 10, 11)
            Ki: osszeg eleme N
            Ef: minden i eleme [1..db] k[i] eleme PAKLI
            Uf: osszeg = SZUM(i = 1..db, ERTEK[KIVALASZT[PAKLI[k[i]]]])
        */
        static void Kartyajatek() {
            int db;
            int.TryParse(Console.ReadLine(), out db);

            string[] k = new string[db];

            for (int i = 0; i < db; i++) {
                k[i] = Console.ReadLine();
            }

            int osszeg = 0;

            for (int i = 0; i < k.Length; i ++) {
                for (int j = 0; j < PAKLI.Length; j ++) {
                    if (k[i] == PAKLI[j]) {
                        osszeg += ERTEK[j];
                    }
                }
            }

            Console.WriteLine($"Osszeg: {osszeg}");
        }

        /* 3.Homerseklet 
            Specifikacio:
            Be: hom eleme N [1..5]
            Ki: nov eleme L
            Ef: -
            Uf: nov = VAN(i eleme [1..5], )
        */
        static void Homerseklet() {
            int[] homersekletek = {37, 38, 39, 40, 43, 45};

            bool nov = true;

            for (int i = 0; i < (homersekletek.Length - 1) && nov; i++) {
                if (homersekletek[i] >= homersekletek[i + 1]) {
                    nov = false;
                }
            }

            Console.WriteLine($"Szigoruan monoton novekvo: {nov}");
        }

        /* 4.Nyelvvizsga 
            Specifikacio:
            Be: 
            Ki:
            Ef:
            Uf:
        */
        static void Nyelvvizsga() {
            int[] pontok = {55, 66, 75, 75, 10};
            bool van = false;
            int hely = 0; 

            for (int i = 0; i < (pontok.Length - 1); i++) {
                if (pontok[i] == pontok[i + 1]) {
                    van = true;
                    hely = i;
                }
            }

            Console.WriteLine($"Van: {van}");

            if (van) {
                Console.WriteLine($"Hely: {hely + 1}");
            }
        }

        public static void Main(string[] args) {
            //MagyarKartya();
            //Kartyajatek();
            //Homerseklet();
            Nyelvvizsga();
        }
    }
}