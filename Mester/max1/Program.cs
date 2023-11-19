using System;

class ElőrejelzésekMaximumaLegnagyobb {
    public static void Main(string[] args) {
        int t;
        int n;
        int ossz;

        string? sor = Console.ReadLine();

        t = int.Parse(sor.Split(" ")[0]);
        n = int.Parse(sor.Split(" ")[1]);
        ossz = int.Parse(sor.Split(" ")[2]);

        int[,] hom = new int[t, n];

        for (int i = 0; i < t; i++) {
            sor = Console.ReadLine();
            string[] sorParts = sor.Split(" ");

            for (int j = 0; j < n; j++) {
                int data = int.Parse(sorParts[j]);

                if (20 <= data && data <= 50) {
                    hom[i, j] = data;
                }
            }
        }
        
        int maxind = 0;
        int max = hom[0, 0];

        for (int i = 0; i < t; i++) {
            for (int j = 0; j < n; j++) {
                if (hom[i, j] > max) {
                    max = hom[i, j];
                    maxind = i + 1;
                }
            }
        }

        Console.WriteLine(maxind);
    }
}
