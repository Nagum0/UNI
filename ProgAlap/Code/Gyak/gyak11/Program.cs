using System;

class Gyak11 {
    // 1. Iskola verseny: (Kivalogatas + Eldontes)
    static bool VanDiak(string nev, List<string> strs) {
        bool van = false;

        for (int i = 0; i < strs.Count && !van; i++) {
            if (nev == strs[i]) {
                return true;
            }
        }

        return false;
    }

    static void Feladat1() {
        // Beolvasas:
        List<string> targy1 = new List<string> {"Dani", "Zeki", "Laci", "Zalan", "Balazs"};
        List<string> targy2 = new List<string> {"Zeki", "Laci", "Zalan"};
        List<string> kirandulok = new List<string>();

        // Feldolgozas:
        for (int i = 0; i < targy1.Count; i++) {
            if (VanDiak(targy1[i], targy2)) {
                kirandulok.Add(targy1[i]);
            }
        }

        //Kiiras:
        Console.WriteLine(string.Join(", ", kirandulok));
    }

    // 2. Verseny eredmenyek (A):


    static void Feladat2A() {
        // Beolvasas:
        int n, m;
        n = int.Parse(Console.ReadLine().Split(' ')[0]);
        m = int.Parse(Console.ReadLine().Split(' ')[1]);
        int[,] verseny = new int[n, m];

        for (int i = 0; i < n; i++) {
            string[] sor = Console.ReadLine().Split(' ');

            for (int j = 0; j < m; j++) {
                verseny[i, j] = int.Parse(sor[j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Console.Write($"{verseny[i,j]} ");
            }
            Console.Write("\n");
        }
    }

    public static void Main(string[] args) {
        // 1. Iskola verseny: (Kivalogatas + Eldontes)
        Feladat1();

        // 2. Verseny eredmenyek (A):
        Feladat2A();
    }
}