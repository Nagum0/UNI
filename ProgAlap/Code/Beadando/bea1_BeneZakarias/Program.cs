using System;

/*
 * Bene Zakariás
 * UAUYQF
 * uauyqf@INF.ELTE.HU
 * Feladat: Vilagcsucs beallitasok szama
 */
class VilagcsucsBeallitasokSzama {
    static void Main(string[] args) {
        int n;
        int.TryParse(Console.ReadLine(), out n);

        int[] T = new int[n];
        int[] Mag = new int[n];

        for (int i = 0; i < n; i++) {
            var sor = Console.ReadLine();

            T[i] = int.Parse(sor.Split(" ")[0]);
            Mag[i] = int.Parse(sor.Split(" ")[1]);
        }

        int beallitasok = 0;

        for (int i = 1; i < n; i++) {
            if (Mag[i] == Mag[i - 1]) {
                beallitasok++;
            }
        }

        Console.WriteLine(beallitasok);
    }
}