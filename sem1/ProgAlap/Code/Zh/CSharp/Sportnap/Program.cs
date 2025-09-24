using System;
using System.Collections.Generic;

internal class SportnapFelmeres {
    class Nevezes {
        public string nev = "";
        public List<int> sport_agak = new List<int>();

        public Nevezes(string nev) {
            this.nev = nev;
        }

        public void PrintNevezes() {
            Console.Error.Write($"{this.nev} ");
            Console.Error.WriteLine(string.Join(", ", this.sport_agak));
        }
    }

    // Beolvasas:
    static (int, List<Nevezes>) Beolvas() {
        string[] elso_sor = Console.ReadLine().Split(" ");
        int sport_agak_szama = int.Parse(elso_sor[0]);
        int n = int.Parse(elso_sor[1]);

        List<Nevezes> nevezesek = new List<Nevezes>();
        List<string> foglalt_nevek = new List<string>();

        for (int i = 0; i < n; i++) {
            string[] sor = Console.ReadLine().Split(" ");
                        
            if (foglalt_nevek.Contains(sor[0])) {
                foreach (Nevezes nevezes in nevezesek) {
                    if (nevezes.nev == sor[0]) {
                        nevezes.sport_agak.Add(int.Parse(sor[1]));
                    }
                }
            }
            else {
                Nevezes nevezes = new Nevezes(sor[0]);
                nevezes.sport_agak.Add(int.Parse(sor[1]));
                nevezesek.Add(nevezes);
                foglalt_nevek.Add(sor[0]);
            }
        }

        return (sport_agak_szama, nevezesek);
    }

    /* 1. részfeladat: Egy olyan tanuló nevét kell kiírni, aki pontosan egy sportágra nevezett! Ha nincs
    ilyen tanuló, akkor üres sort kell kiírni! */
    static string EgySportagasTanulo(List<Nevezes> nevezesek) {
        foreach (Nevezes nevezes in nevezesek) {
            if (nevezes.sport_agak.Count == 1) {
                return nevezes.nev;
            }
        }

        return "";
    }

    /* 2. részfeladat: A legtöbb sportágban nevezett tanuló nevét kell kiírni! Ha több is van, akkor tet-
    szőlegeset!*/
    static string LegtobbSportagasTanulo(List<Nevezes> nevezesek) {
        string tanulo = "";
        int maxval = nevezesek[0].sport_agak.Count;

        foreach (Nevezes nevezes in nevezesek) {
            if (nevezes.sport_agak.Count > maxval) {
                tanulo = nevezes.nev;
                maxval = nevezes.sport_agak.Count;
            }
        }

        return tanulo;
    }

    /* 3. részfeladat: Egy sorban S egész számot kell kiírni, az i-edik szám az i-edik sportágra nevezet-
    tek száma legyen!*/
    static List<int> SportagakAdatai(int x, List<Nevezes> nevezesek) {
        List<int> sportagak_elofordulasa = new List<int>();
        for (int i = 0; i < x; i++) {
            sportagak_elofordulasa.Add(0);
        }

        foreach (Nevezes nevezes in nevezesek) {
            foreach (int i in nevezes.sport_agak) {
                sportagak_elofordulasa[i - 1] += 1;
            }
        }

        return sportagak_elofordulasa;
    }

    /* 4. részfeladat: Annyi sort kell kiírni, ahány olyan sportág-pár van, amelyek versenye egyidőben
    rendezhető (azaz nincs olyan tanuló, aki mindkettőre nevezett)! Minden sorban a két sportág sor-
    száma legyen, a sorokat lexikografikus sorrendben kell megadni! Az olyan sportág, amelyre senki
    nem nevezett, ne szerepeljen a felsorolásban!*/
    static void EgyidosSportok(List<Nevezes> nevezesek) {
        foreach (Nevezes nevezes in nevezesek) {

        }
    }

    /* 5. részfeladat: Annyi sort kell kiírni, ahány tanuló nevezett a versenyre! Minden sor elején a tanu-
    ló neve legyen, majd tőle egy szóközzel elválasztva azon tanulók száma, akikkel nevezett azonos
    versenyre!*/
    static void AzonosVersenyekSzama(List<Nevezes> nevezesek) {
        foreach (Nevezes nevezes in nevezesek) {
            int n = 0;

            foreach (int sportag in nevezes.sport_agak) {
                foreach (Nevezes nevezes_j in nevezesek) {
                    if (nevezes_j.sport_agak.Contains(sportag) && nevezes.nev != nevezes_j.nev) {
                        Console.WriteLine($"Here({nevezes_j.nev}): {sportag}");
                        n++;
                    }
                }
            }

            Console.WriteLine($"{nevezes.nev} {n}");
        }
    }

    public static void Main(string[] args) {
        // Beolvasas:
        (int sportagak_szama, List<Nevezes> nevezesek) = Beolvas();
        Console.Error.WriteLine("");
        foreach (Nevezes nevezes in nevezesek) {
            nevezes.PrintNevezes();
        }

        // Feldogozas:
        Console.WriteLine("#");
        Console.WriteLine(EgySportagasTanulo(nevezesek));
        Console.WriteLine("#");
        Console.WriteLine(LegtobbSportagasTanulo(nevezesek));
        Console.WriteLine("#");
        Console.WriteLine(string.Join(" ", SportagakAdatai(sportagak_szama, nevezesek)));
        Console.WriteLine("#");
        Console.WriteLine("#");
        AzonosVersenyekSzama(nevezesek);
    }
}