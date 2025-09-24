namespace Gyak9Func
{
    class Fa
    {
        public int ev;
        public int mag;
        public int atmero;

        public Fa(int ev, int atmero, int mag)
        {
            this.ev = ev;
            this.mag = mag;
            this.atmero = atmero;
        }
    }

    class Program
    {

        /*
            1. Mennyi az erdő átlag életkora? (összegzés)
            2. Hány éves a legfiatalabb fa? (minimum)
            3. Melyik a legmagasabb fa? (maximum)
            4. Az 50 évnél idősebb, de 50cm átmérőt el nem érő fákat kivágásra jelölik meg. Hány fát vágnak ki? (megszámlálás)
            5. Van-e olyan fa, aminek az átmérője nagyobb mint 100cm, és magassága eléri a 15 métert? (eldöntés)
            6. Hány éves volt az első 10 méternél magasabb fa? (kiválasztás)
         */

        // 1. Mennyi az erdő átlag életkora? (összegzés)
        static int AtlagEletkor(Fa[] meresek)
        {
            int atlagEletkor = 0;

            for (int i = 0; i < meresek.Length; i++)
            {
                atlagEletkor += meresek[i].ev;
            }

            return atlagEletkor / meresek.Length;
        }

        // 2. Hány éves a legfiatalabb fa? (minimum)
        static int LegfiatalabbFa(Fa[] meresek)
        {
            int min = meresek[0].ev;

            for (int i = 0; i < meresek.Length; i++)
            {
                if (min > meresek[i].ev)
                {
                    min = meresek[i].ev;
                }
            }

            return min;
        }

        // 3. Melyik a legmagasabb fa? (maximum)
        static int LegmagasabbFa(Fa[] meresek)
        {
            int ind = 0;
            int max = meresek[0].mag;

            for (int i = 0; i < meresek.Length; i++)
            {
                if (max < meresek[i].mag)
                {
                    max = meresek[i].mag;
                    ind = i;
                }
            }

            return ind + 1;
        }

        // 4. Az 50 évnél idősebb, de 50cm átmérőt el nem érő fákat kivágásra jelölik meg. Hány fát vágnak ki? (megszámlálás)
        static int FakKivagasra(Fa[] meresek)
        {
            int darab = 0;

            for (int i = 0; i < meresek.Length; i++)
            {
                if (meresek[i].ev > 50 && meresek[i].atmero < 50)
                {
                    darab++;
                }
            }

            return darab;
        }

        // 5. Van-e olyan fa, aminek az átmérője nagyobb mint 100cm, és magassága eléri a 15 métert? (eldöntés)
        static bool VanNagyFa(Fa[] meresek)
        {
            for (int i = 0; i < meresek.Length; i++)
            {
                if (meresek[i].atmero > 100 && meresek[i].mag >= 15)
                {
                    return true;
                }
            }

            return false;
        }

        // 6. Hány éves volt az első 10 méternél magasabb fa? (kiválasztás)
        static int ElsoMagasFa(Fa[] meresek)
        {
            for (int i = 0; i < meresek.Length; i++)
            {
                if (meresek[i].mag > 10)
                {
                    return meresek[i].ev;
                }
            }

            return -1;
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
            Console.WriteLine($"Erdo atlageletkora: {AtlagEletkor(meresek)}.");

            // 2.Hány éves a legfiatalabb fa? (minimum)
            Console.WriteLine($"Legfiatalabb fa eletkora: {LegfiatalabbFa(meresek)}.");

            // 3. Melyik a legmagasabb fa? (maximum)
            Console.WriteLine($"Legmagasabb fa: {LegmagasabbFa(meresek)}");

            // 4. Az 50 évnél idősebb, de 50cm átmérőt el nem érő fákat kivágásra jelölik meg. Hány fát vágnak ki? (megszámlálás)
            Console.WriteLine($"Fak kivagasra: {FakKivagasra(meresek)}");

            // 5. Van-e olyan fa, aminek az átmérője nagyobb mint 100cm, és magassága eléri a 15 métert? (eldöntés)
            Console.WriteLine(VanNagyFa(meresek) ? "Van nagy fa." : "Nincs nagy fa.");

            // 6.Hány éves volt az első 10 méternél magasabb fa ? (kiválasztás)
            Console.WriteLine(ElsoMagasFa(meresek) != -1 ? $"Elso magas fa eletkora: {ElsoMagasFa(meresek)}." : "Nincs ilyen fa.");
        }
    }
}