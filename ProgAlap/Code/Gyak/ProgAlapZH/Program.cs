// Bene Zakarias
// Neptun: UAUYQF
// A - csoport
using System;
using System.Collections.Generic;

namespace ProgAlapZH
{
    internal class Program
    {
        struct Konyv
        {
            public string szerzo;
            public string cim;
            public int peldanyszam;
            public int kikolcs;
        }

        static List<int> KonyvekSzama(int n, Konyv[] konyvek)
        {
            List<int> konyvekSzama = new List<int>();

            for (int i = 0; i < n; i++)
            {
                if (konyvek[i].peldanyszam - konyvek[i].kikolcs <= 2)
                {
                    konyvekSzama.Add(i + 1);
                }
            }

            return konyvekSzama;
        }

        static void Main(string[] args)
        {
            // Beolvasas:
            int n;
            int.TryParse(Console.ReadLine(), out n);
            Konyv[] konyvek = new Konyv[n];

            for (int i = 0; i < n; i++)
            {
                string sor = Console.ReadLine();
                konyvek[i].szerzo = sor.Split(';')[0];
                konyvek[i].cim = sor.Split(';')[1];
                konyvek[i].peldanyszam = int.Parse(sor.Split(';')[2]);
                konyvek[i].kikolcs = int.Parse(sor.Split(';')[3]);
            }

            // Feldolgozas:
            List<int> konyvekSzama = KonyvekSzama(n, konyvek);
            Console.Write($"{konyvekSzama.Count} ");
            Console.WriteLine(string.Join(" ", konyvekSzama));
        }
    }
}