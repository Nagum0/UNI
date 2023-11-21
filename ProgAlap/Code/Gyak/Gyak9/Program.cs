namespace Gyak9
{   
    class Tree
    {
        public int ev;
        public int ker;
        public int mag;

        public Tree(int ev, int ker, int mag)
        {
            this.ev = ev;
            this.ker = ker;
            this.mag = mag;
        }
    }

    class Program
    {
        /*
            1. Mennyi az erdő átlag életkora? (összegzés)
            2. Hány éves a legfiatalabb fa? (minimum)
            3. Melyik a legmagasabb fa? (maximum)
            4. Az 50 évnél idősebb, de 50cm átmérőt el nem érő fákat kivágásra jelölik meg. Hány fát vágnak ki? (megszámlálás)
            5. Van-e olyan fa, aminek a kerülete nagyobb mint 100cm, és magassága eléri a 15 métert? (eldöntés)
            6. Hány éves volt az első 10 méternél magasabb fa? (kiválasztás)
         */

        static void Main(string[] args)
        {
            Tree[] meresek =
            {
                new Tree(100, 300, 14),
                new Tree(110, 69, 15),
                new Tree(123, 300, 20),
                new Tree(86, 85, 19),
                new Tree(100, 49, 12)
            };

            // 1. Mennyi az erdő átlag életkora? (összegzés)
            int atlagEletkor = 0;

            for (int i = 0; i <= (meresek.Length - 1); i++)
            {
                atlagEletkor += meresek[i].ev;
            }

            Console.WriteLine($"Atlag eletker: {atlagEletkor / meresek.Length}.");

            // 2.Hány éves a legfiatalabb fa? (minimum)
            int min = meresek[0].ev;

            for (int i = 0; i <= (meresek.Length - 1); i++)
            {
                if (min > meresek[i].ev)
                {
                    min = meresek[i].ev;
                }
            }

            Console.WriteLine($"Legfiatalabb eletkora: {min}.");

            // 3. Melyik a legmagasabb fa? (maximum)
            int max = meresek[0].mag;
            int ind = 0;

            for (int i = 0; i <= (meresek.Length - 1); i++)
            {
                if (max < meresek[i].mag)
                {
                    max = meresek[i].mag;
                    ind = i;
                }
            }

            Console.WriteLine($"Legmagasabb fa: {ind + 1}.");

            // 4. Az 50 évnél idősebb, de 50cm átmérőt el nem érő fákat kivágásra jelölik meg. Hány fát vágnak ki? (megszámlálás)
            int darab = 0;

            for (int i = 0; i <= (meresek.Length - 1); i++)
            {
                if (meresek[i].ev >= 50 && meresek[i].ker <= 50)
                {
                    darab++;
                }
            }

            Console.WriteLine($"Kivagasra varo fak: {darab}.");

            // 5. Van-e olyan fa, aminek a kerülete nagyobb mint 100cm, és magassága eléri a 15 métert? (eldöntés)
            bool van = false;

            for (int i = 0; i <= (meresek.Length - 1); i++)
            {
                if (!van && meresek[i].ker > 100 && meresek[i].mag >= 15)
                {
                    van = true;
                }
            }

            Console.WriteLine(van ? "Van olyan fa." : "Nincs olyan fa.");

            // 6. Hány éves volt az első 10 méternél magasabb fa? (kiválasztás)
            bool van2 = false;
            int faEv = 0;

            for (int i = 0; i <= (meresek.Length - 1); i++)
            {
                if (!van2 && meresek[i].mag > 10)
                {
                    faEv = meresek[i].ev;
                }
            }

            Console.WriteLine($"Elso 10 meternel magasabb fa eletkora: {faEv}.");
        }
    }
}