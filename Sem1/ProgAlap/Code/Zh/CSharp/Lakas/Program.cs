using System;
using System.Collections.Generic;

class Lakas {
    public int terulet;
    public int ar;

    public Lakas(int terulet, int ar) {
        this.terulet = terulet;
        this.ar = ar;
    }

    public static void Print(List<Lakas> lakasok) {
        foreach (Lakas lakas in lakasok) {
            Console.WriteLine($"[{lakas.terulet}, {lakas.ar}]");
        }
    }
}

class IngatlanFelmeres {
    static List<Lakas> Beolvas() {
        int n;
        int.TryParse(Console.ReadLine(), out n);

        List<Lakas> lakasok = new List<Lakas>();

        for (int i = 0; i < n; i++) {
            string[] sor_adatok = Console.ReadLine().Split(' ');
            lakasok.Add(new Lakas(
                int.Parse(sor_adatok[0]),
                int.Parse(sor_adatok[1])
            ));
        }

        return lakasok;
    } 

    static int LegdragabbLakas(List<Lakas> lakasok) {
        int maxval = lakasok[0].ar;
        int maxind = 0;

        for (int i = 0; i < (lakasok.Count - 1); i++) {
            if (lakasok[i].ar > maxval) {
                maxval = lakasok[i].ar;
                maxind = i;
            }
        }
        
        return maxind;
    }

    static int NagyOlcso(List<Lakas> lakasok) {
        int s = 0;

        foreach (Lakas lakas in lakasok) {
            if (lakas.terulet > 100 && lakas.ar < 40) {
                s++;
            }
        }

        return s;
    }

    static int HanyfeleKulonbozoLakasVan(List<Lakas> lakasok) {
        List<int> teruletek = new List<int>();
        teruletek.Add(lakasok[0].terulet);

        foreach (Lakas lakas in lakasok) {
            if (!teruletek.Contains(lakas.terulet)) {
                teruletek.Add(lakas.terulet);
            }
        }

        return teruletek.Count;
    }

    static (int, List<int>) DragaLakasok(List<Lakas> lakasok) {
        int n = 0;
        List<int> sorszamok = new List<int>();

        for (int i = 0; i < lakasok.Count; i++) {
            if (lakasok[i].ar > 100) {
                n++;
                sorszamok.Add(i + 1);
            }
        } 

        return (n, sorszamok); 
    }

    public static void Main(string[] args) {
        // Beolvasas:
        List<Lakas> lakasok = Beolvas();
        //Lakas.Print(lakasok);

        // Feldolgozas:
        // a)
        Console.WriteLine($"{LegdragabbLakas(lakasok) + 1}");
        // b)
        Console.WriteLine($"{NagyOlcso(lakasok)}");
        // c)
        Console.WriteLine($"{HanyfeleKulonbozoLakasVan(lakasok)}");
        // d)
        (int n, List<int> sorszamok) = DragaLakasok(lakasok);
        Console.WriteLine($"{n} {string.Join(" ", sorszamok)}"); 
    }
}