/*
Bene Zakarias
UAUYQF
zackbene9gmail.com
Biro feladat: Az átlagnál melegebb napok száma szerinti sorrend
*/

using System;
using System.Collections.Generic;

namespace IdojarasElorejelzes {
    class TelepulesAdat {
        public int index;
        public int k = 0;

        public TelepulesAdat(int index)
        {
            this.index = index;
        }
    }

    internal class Program {
        static List<List<int>> Beolvas() {
            if (Console.IsInputRedirected) {
                return BeolvasBiro();
            }
            else {
                return BeolvasKezi();
            }
        }

        static List<List<int>> BeolvasBiro() {
            int n, m;
            string[] elso_sor = Console.ReadLine().Split(' ');
            int.TryParse(elso_sor[0], out n);
            int.TryParse(elso_sor[1], out m);

            List<List<int>> result = new List<List<int>>();

            for (int i = 0; i < n; i++) {
                string[] sor = Console.ReadLine().Split(' ');

                // Uj sor kezdese:
                result.Add(new List<int>());

                for (int j = 0; j < m; j++) {
                    result[i].Add(int.Parse(sor[j]));
                }
            }

            return result;
        }

        static List<List<int>> BeolvasKezi() {
            int n, m;
            bool jo;

            do {
                Console.ResetColor();
                Console.Write("Telepulesek szama: ");
                jo = int.TryParse(Console.ReadLine(), out n);
                if (!jo)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("Termeszetes szam kell!");
                }
            } while (!jo);

            do {
                Console.ResetColor();
                Console.Write("Napok szama: ");
                jo = int.TryParse(Console.ReadLine(), out m);
                if (!jo)
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("Termeszetes szam kell!");
                }
            } while (!jo);

            List<List<int>> result = new List<List<int>>();

            for (int i = 0; i < n; i++) {
                result.Add(new List<int>());
                for (int j = 0; j < m; j++) {
                    do {
                        Console.ResetColor();
                        Console.Write($"{i + 1}.telepules {j + 1}.nap: ");
                        int h;
                        jo = int.TryParse(Console.ReadLine(), out h);
                        if (!jo) {
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.WriteLine("Termeszetes szam kell!");
                        }
                        else {
                            result[i].Add(h);
                        }
                    } while (!jo);
                }
            }

            return result;
        }

        static int Atlag(List<int> napok) {
            int s = 0;

            // Szumma:
            for (int i = 0; i < napok.Count; i++) {
                s += napok[i];
            }

            // Atlag szamitas:
            return s / napok.Count;
        }

        static TelepulesAdat TelepulesAdatCalc(int telepules, List<int> napok) {
            TelepulesAdat adat = new TelepulesAdat(telepules + 1);
            int n = Atlag(napok);

            // Megszamlalas:
            for (int i = 0; i < napok.Count; i++) {
                if (napok[i] > n)
                {
                    adat.k++;
                }
            }

            return adat;
        }

        // Sorting (bubble sort):
        static void RendezettAdatok(ref List<TelepulesAdat> telepulesek) {
            for (int i = 1; i < telepulesek.Count; i++) {
                for (int j = 0; j < telepulesek.Count - 1; j++) {
                    if (telepulesek[j].k < telepulesek[j + 1].k) {
                        TelepulesAdat temp = telepulesek[j];
                        telepulesek[j] = telepulesek[j + 1];
                        telepulesek[j + 1] = temp;
                    }
                }
            }
        }

        public static void Main(string[] args) {
            // Beolvasas:
            List<List<int>> telepulesek = Beolvas();

            // Feldolgozas:
            List<TelepulesAdat> adatok = new List<TelepulesAdat>();
            for (int i = 0; i < telepulesek.Count; i++) {
                adatok.Add(TelepulesAdatCalc(i, telepulesek[i]));
            }
            RendezettAdatok(ref adatok);

            // Kiiratas:
            for (int i = 0; i < adatok.Count; i++) {
                Console.Write($"{adatok[i].index} ");
            }
        }
    }
}