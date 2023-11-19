/*
    Nev: Bene Zakarias
    Neptun: UAUYQF
    Biro feladat: Vitorlás verseny kezdő napja
*/
using System;

class Program {
    static int[] Beolvas(int n) {
        int[] szels = new int[n];

        for (int i = 0; i < n; i++) {
            int.TryParse(Console.ReadLine(), out szels[i]);
        }

        return szels;
    }

    static bool LehetVerseny(int k, int i, int[] szels) {
        for (int j = i; j < (i + k); j++) {
            if (szels[j] < 10 || szels[j] > 100) {
                return false;
            }
        }

        return true;
    }

    public static void Main(string[] args) {
        // Beolvasas.
        int n, k;

        string[] nkSor = Console.ReadLine().Split(" ");
        int.TryParse(nkSor[0], out n);
        int.TryParse(nkSor[1], out k);

        int[] szels = Beolvas(n);

        // Megoldas.
        bool van = false;
        int ind = 0;

        for (int i = 0; i < (n - k); i++) {
            if (van == false && LehetVerseny(k, i, szels)) {
                van = true;
                ind = i;
            }
        }

        Console.WriteLine(van ? (ind + 1): -1);
    }
}