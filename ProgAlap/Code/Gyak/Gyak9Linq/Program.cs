namespace Gyak9Linq
{
    class Fa
    {
        public int ev;
        public int atmero;
        public int mag;

        public Fa(int ev, int atmero, int mag)
        {
            this.ev = ev;
            this.atmero = atmero;
            this.mag = mag;
        }
    }

    class Program
    {
        static double Kerulet(int atmero)
        {
            return 2 * (atmero / 2) * Math.PI;
        }

        static void Main(string[] args)
        {
            Fa[] meresek =
            {
                new Fa(119, 236, 19),
                new Fa(86, 125, 14),
                new Fa(49, 149, 21),
                new Fa(51, 49, 17)
            };

            // 1. Mennyi az erdő átlag életkora? (összegzés)
            double atlagEletkor = meresek.Average(x => x.ev);
            Console.WriteLine($"Atlag eletkor: {atlagEletkor}");

            // 2. Hány éves a legfiatalabb fa? (minimum)
            int min = meresek.Min(x => x.ev);
            Console.WriteLine($"Legfiatalabb fa: {min}");

            // 3. Melyik a legmagasabb fa? (maximum)
            int maxind = meresek.Select((x, id) => new { Fa = x, Index = id })
                                .Aggregate((a, b) => (a.Fa.mag > b.Fa.mag) ? a : b)
                                .Index;
            Console.WriteLine($"Legmagasamm fa: {maxind + 1}");

            // 4. Az 50 évnél idősebb, de 50cm átmérőt el nem érő fákat kivágásra jelölik meg. Hány fát vágnak ki? (megszámlálás)
            int darab = meresek.Where(x => x.ev > 50 && x.atmero < 50).Count();
            Console.WriteLine($"Kivaghato fak szama: {darab}");

            // 5. Van-e olyan fa, aminek az átmérője nagyobb mint 100cm, és magassága eléri a 15 métert? (eldöntés)
            bool van = meresek.Any(x => x.atmero > 100 && x.mag >= 15);
            Console.WriteLine(van ? "Van nagy fa." : "Nincs nagy fa.");

            // 6. Hány éves volt az első 10 méternél magasabb fa? (kiválasztás)


            // 7. Add meg minden fa esetén, hogy mekkora a törzsének kerülete.
            double[] keruletek = meresek.Select(x => Kerulet(x.atmero)).ToArray();
            Console.WriteLine($"Keruletek: {string.Join(", ", keruletek)}");
        }
    }
}