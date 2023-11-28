using System;
using System.Collections.Generic;

class EsosNapok {
    static (int n, List<int> xs) Beolvas() {
        int n;
        List<int> xs = new List<int>();

        int.TryParse(Console.ReadLine(), out n);

        for (int i = 0; i < n; i++) {
            string? sor = Console.ReadLine();

            if (sor != null) {
                xs.Add(int.Parse(sor));
            }
        }

        return (n, xs);
    }

    static int Darab<H>(List<H> xs, Func<int, bool> T) {
            int db = 0;

            for (int i = 0; i < xs.Count; i++) {
                if (T(i)) {
                    db++;
                }
            }

            return db;
        }

    public static void Main(string[] args) {
        // Beolvasas.
        (int n, List<int> xs) = Beolvas();

        // Megoldas.
        int db = Darab(xs, i => xs[i] > 0);
        Console.WriteLine(db);
    }
}