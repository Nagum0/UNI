using System;

class Mintak {

    // KERES
    static (bool van, int ind) Keres(int e, int u, Func<int, bool> T) {
        bool van = false;
        int ind = 0;

        for (int i = e; i < u; i++) {
            if (T(i)) {
                van = true;
            }
            else {
                ind++;
            }
        }

        return (van, ind);
    }

    // Generis type KERES
    static (bool van, int ind) GenKeres<T>(List<T> xs, Func<int, bool> F) {
        bool van = false;
        int ind = 0;

        for (int i = 0; i < xs.Count; i++) {
            if (F(i)) {
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

    static void Main(string[] args) {
        #region KERES
        int e = 0;
        int u = 5;
        int[] xs = {1,2,3,-4,5};
        (bool van, int ind) = Keres(e, u, i => xs[i] < 0);
        Console.WriteLine(van ? $"Van negativ szam: xs[{ind}]" : "Nincs negativ szam");
        #endregion

        #region GenKERES
        List<string> strs = new List<string> {"Astolfo", "Zeki"};
        (bool van2, int ind2) = GenKeres(strs, i => strs[i] == "Fee");
        Console.WriteLine(van2 ? $"{van2} : strs[{ind2}] -> {strs[ind2]}" : "Nem talalt!");
        #endregion

        #region MAX
        List<int> xsl = new List<int> {57, 69, 10, 1000};
        (int maxind, int maxert) = Max(xsl, i => i % 2 != 0);
        Console.WriteLine($"xsl[{maxind} : {maxert}]");
        #endregion
    }
}