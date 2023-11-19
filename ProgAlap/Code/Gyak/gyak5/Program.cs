using System;

// Ezeken feladatok:
// biro.inf.elte.hu
// mester.inf.elte.hu

class Gyak5 {
    /* Esos napok szama: - Megszamolas
        Be: n eleme N, t eleme N[1..n]
        Ki: esos eleme N
        Ef: 0 <= n <= 100 es
            minden i eleme [1..n] : 0 <= t[i] <= 1000
        Uf: esos = DARAB(i = 1..n, t[i] > 0)
    */
    static void EsosNapok() {
        int n;

        Console.WriteLine("Napok szama: ");
        int.TryParse(Console.ReadLine(), out n);

        int[] t = new int[n];

        for (int i = 0; i < n; i++) {
            Console.WriteLine("Homerseklet: ");
            int.TryParse(Console.ReadLine(), out t[i]);
        }

        int esos = 0;

        if (0 <= n && n <= 100) {
            for (int i = 0; i < n; i++) {
                if (0 <= t[i] && t[i] <= 1000) {
                    if (t[i] > 0) {
                        esos++;
                    }
                }
            }
        }

        Console.WriteLine(esos);
    }

    /* Legemelegebb nap - Maximumkivalasztas
        Be: n eleme N, h eleme N[1..n]
        Ki: maxind eleme N
        Ef: 1 <= n <= 100 es
            minden i eleme [1..n] : -20 <= h[i] <= 50
        Uf: (maxind, -) = MAX(i = 1..n, h[i])
    */
    static void LegemelegebbNap() {
        int n;

        Console.WriteLine("Napok: ");
        int.TryParse(Console.ReadLine(), out n);

        int[] h = new int[n];

        for (int i = 0; i < n; i++) {
            Console.WriteLine("Homerseklet: ");
            int.TryParse(Console.ReadLine(), out h[i]);
        }

        int maxind = 0;
        int max = h[0];

        if (1 <= n && n <= 100) {
            for (int i = 1; i < n; i++) {
                if (max >= h[i]) {
                    max = h[i];
                    maxind = i;
                }
            }
        }

        Console.WriteLine(maxind);
    } 

    /* Legidosebb ember - Maximumkivalasztas
        Be: n eleme N,
            E eleme N[1..n],
            H eleme N[1..n],
            Nap eleme N[1..n]
        Ki: min eleme N
        Ef: 1 <= n <= 1000 es
            minden i eleme [1..n] : 1900 ≤ E[i] ≤ 2014
            minden i eleme [1..n] : 1 ≤ H[i] ≤ 12
            minden i eleme [1..n] : 1 ≤ N[i] ≤ 30
        Uf: minden i eleme [1..n]
            ((E[min] < E[]) vagy
            (E[min] = E[i]) es H[min] M H[i]) ... 
    */
    static void LegidosebbEmber() {

    }

    public static void Main(string[] args) {
        LegemelegebbNap();
    }
}
