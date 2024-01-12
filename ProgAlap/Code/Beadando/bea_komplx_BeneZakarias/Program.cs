/*
Bene Zakarias
UAUYQF
zackbene9gmail.com
Biro feladat: Az átlagnál melegebb napok száma szerinti sorrend
*/

using System;
using System.Collections.Generic;

class IdojarasElorejelzes {
    static List<List<int>> Beolvas() {
        if (Console.IsInputRedirected) {
            return BeolvasBiro();
        }
        else {
            return BeolvasKezi();
        }
    }

    static List<List<int>> BeolvasBiro() {
        
    }

    static double Atlag(List<int> telepules) {
        double result = 0;

        foreach (int i in telepules) {
            result += i;
        }

        return result / telepules.Count;
    }

    static List<int> MelegebbNapokSzama(List<List<int>> telepulesek) {
        List<int> result = new List<int>();

        for (int i = 0; i < telepulesek.Count; i++) {
            double atlag = Atlag(telepulesek[i]);
            int count = 0;

            for (int j = 0; j < telepulesek[i].Count; j++) {
                if (telepulesek[i][j] > atlag) {
                    count++;
                }
            }

            result.Add(count);
        }

        return result;
    }

    static int FindMaxIndex(List<int> list) {
        int maxind = 0;
        int maxval = list[0];

        for (int i = 0; i < list.Count; i++) {
            if (list[i] != -1 && list[i] > maxval) {
                maxval = list[i];
                maxind = i;
            }
        }

        list[maxind] = -1;
        return maxind;
    }

    public static void Main(string[] args) {
        // Beolvasas:
        List<List<int>> telepulesek = Beolvas();

        // Feldolgozas:
        List<int> eredmeny = MelegebbNapokSzama(telepulesek);
        List<int> sorban_eredmeny = new List<int>();
        
        for (int i = 0; i < eredmeny.Count; i++) {
            int maxind = FindMaxIndex(eredmeny);
            sorban_eredmeny.Add(maxind + 1);
        }

        // Kiiratas:
        Console.WriteLine(string.Join(" ", sorban_eredmeny));
    }
}