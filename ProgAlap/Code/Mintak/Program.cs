using System;
using ProgAlap;

class App {
    static bool checkName(string name) {
        if (name.Length == 5 && name[0] == 'G') {
            return true;
        }

        return false;
    }

    public static void Main(string[] args) {
        List<string> strs = new List<string> {
            "Connor",
            "Chris",
            "Joey",
            "Garnt",
            "Astolfo"
        };

        Mintak mintak = new Mintak();

        // SZUMMA
        List<int> sum_xs = new List<int> {1,2,3,4,5};
        int s = mintak.Sum(sum_xs, i => sum_xs[i] % 2 == 0);
        Console.WriteLine($"Sum of list: {s}"); 

        // DARAB
        int db = mintak.Darab(strs, i => checkName(strs[i]));
        Console.WriteLine($"checkName db: {db}");

        // MAX
        List<int> max_xs = new List<int> {5,4,89,25,69};
        (int maxi, int maxe) = mintak.Max(max_xs, i => max_xs[i] != 89);
        Console.WriteLine($"Max: max_xs[{maxi}] : {maxe}");

        // MIN
        List<int> min_xs = new List<int> {5,4,89,25,69};
        (int mini, int mine) = mintak.Min(min_xs, i => min_xs[i] != 89);
        Console.WriteLine($"Min: min_xs[{mini}] : {mine}");

        // KERES
        (bool ker_van, int ker_ind) = mintak.Keres(strs, i => strs[i] == "Chris");
        Console.WriteLine(ker_van ? $"Chris was found at {ker_ind}" : "Not found");
    
        // VAN
        List<char> van_xs = new List<char>("1.785236498");
        bool van = mintak.Van(van_xs, i => van_xs[i] == '0');
        Console.WriteLine(van ? "Van 0 a szamban" : "Nem talalt!");

        // MIND
        List<char> mind_xs = new List<char>("00000000");
        bool mind = mintak.Mind(mind_xs, i => mind_xs[i] == '0');
        Console.WriteLine(mind ? "Minden szam 0" : "Nem minden szam 0!");

        // KIVALASZTAS
        int kiv_ind = mintak.Kivalaszt(strs, i => strs[i] == "Joey");
        Console.WriteLine(kiv_ind != -1 ? $"Nev Joey talat itt: strs[{kiv_ind}]" : "Nem talalt!"); 
    
        // MASOLAS
        List<int> mas_xs = new List<int> {1,2,3,4,5};
        List<int> mas_xs_uj = mintak.Masol(mas_xs, i => i * 2);
        Console.WriteLine(string.Join(", ", mas_xs_uj));

        // KIVALOGATAS
        List<int> kiv_xs = new List<int> {1,2,3,4,5};
        List<int> kiv_xs_uj = mintak.Kivalogat(mas_xs, i => kiv_xs[i] % 2 == 0);
        Console.WriteLine(string.Join(", ", kiv_xs_uj));
    }
}