using System;

class Mintak {

    #region METHODS

    // SZUMMA
    static int Sum(List<int> xs, Func<int, bool>? T = null) {
        int sum = 0;

        for (int i = 0; i < xs.Count; i++) {
            if (T == null || T(i)) {
                sum += xs[i];
            }
        }

        return sum;
    }

    // MEGSZAMOLAS - DARAB
    static int Darab<H>(List<H> xs, Func<int, bool> T) {
        int db = 0;

        for (int i = 0; i < xs.Count; i++) {
            if (T(i)) {
                db++;
            }
        }

        return db;
    }

    // KERES
    static (bool van, int ind) GenKeres<H>(List<H> xs, Func<int, bool> T) {
        bool van = false;
        int ind = 0;

        for (int i = 0; i < xs.Count; i++) {
            if (T(i)) {
                van = true;
                break;
            }
            else {
                ind++;
            }
        }

        return (van, ind);
    }

    // MAXIMUM KIVALASZTAS
    static (int maxind, int maxert) Max(List<int> xs, Func<int, bool>? T = null) {
        int maxind = 0;
        int maxert = xs[0];
        
        for (int i = 0; i < xs.Count; i++) {
            if (T == null || T(xs[i])) {
                if (xs[i] > maxert) {
                    maxind = i;
                    maxert = xs[i];
                }
            }
        }

        return (maxind, maxert);
    }

    // KIVALASZTAS
    static int Kivalaszt<H>(List<H> xs, Func<int, bool> T) {
        int ind;

        for (ind = 0; ind < xs.Count; ind++) {
            if (T(ind)) {
                return ind;
            }
        }

        return -1;
    }

    #endregion

    static void Main(string[] args) {
        #region SZUMMA
        List<int> sum_xs = new List<int> {1,2,3,4,5};
        int sum = Sum(sum_xs, i => sum_xs[i] % 2 == 0); 
        Console.WriteLine($"Sum: {sum}");
        #endregion

        #region DARAB
        List<string> db_xs = new List<string> {"Astolfo", "Zeki", "Lmao", "Zeki"};
        int db = Darab(db_xs, i => db_xs[i] == "Zeki");
        Console.WriteLine($"Zeki was found {db} times.");
        #endregion

        #region KERES
        List<string> strs = new List<string> {"Astolfo", "Zeki"};
        (bool van, int ind) = GenKeres(strs, i => strs[i] == "Fee");
        Console.WriteLine(van ? $"{van} : strs[{ind}] -> {strs[ind]}" : "Nem talalt!");
        #endregion

        #region MAX
        List<int> xsl = new List<int> {57, 69, 10, 1000};
        (int maxind, int maxert) = Max(xsl, i => i % 2 != 0);
        Console.WriteLine($"xsl[{maxind} : {maxert}]");
        #endregion

        #region KIVALASZT
        List<string> kiv_xs = new List<string> {"Astolfo", "Zeki", "Ferris", "Zeki"};
        int kiv_ind = Kivalaszt(kiv_xs, i => kiv_xs[i] == "Zeki");
        Console.WriteLine(kiv_ind != -1 ? $"Zeki found at: {kiv_ind}" : "Nem talalt!");
        #endregion
    }
}