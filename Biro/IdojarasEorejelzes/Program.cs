using System;

class IdojarasElorejelzes
{
    // 1. részfeladat: azon napok számát kell kiírni, amikor fagyi fog! (megszamolas)
    /*
        Specifikacio:
        Be: homersekletek eleme Nap[e..u],
            Nap = legkisebb x legnagyobb, legkisebb eleme Z, legnagyobb eleme Z
        Ki: fagyNapok eleme N
        Ef: -
        Uf: fagyNapok = DARAB(i = e..u, homersekletek[i].legkisebb <= 0)
    */
    static void FagyNapok(Nap[] homersekletek)
    {
        int fagyNapok = 0;

        for (int i = 0; i < homersekletek.Length; i++)
        {
            if (homersekletek[i].legkisebb <= 0)
            {
                fagyNapok++;
            }
        }

        Console.WriteLine(fagyNapok);
    }

    /*
        2. részfeladat: azt a napot kell kiírni, ahol a legnagyobb a különbség a várható minimális és 
           maximális hőmérséklet között (ha több ilyen van, akkor a legkisebb sorszámút)! (maximumkivalasztas)
    */
    /*
        Specifikacio:
        Be: kulonbsegek eleme N[e..u]
        Ki: maxind eleme N
        Ef: -
        Uf: (maxind, maxert) = MAX(i = e..u, kulonbsegek[i] < kulonbsegek[i + 1])
    */
    static void LegnagyobbKulonbseg(int[] kulonbsegek)
    {
        int maxind = 0;
        int maxert = kulonbsegek[0];

        for (int i = 1; i < kulonbsegek.Length - 1; i++)
        {
            if (maxert < kulonbsegek[i + 1])
            {
                maxind = i + 1;
                maxert = kulonbsegek[i + 1];
            }
        }

        Console.WriteLine(maxind + 1);
    }

    /*
        3. részfeladat: egy olyan napot kell kiírni, amikor a napi maximum kisebb az előző napi minimumnál
           (ha több ilyen van, akkor a legkisebb sorszámút; -1-et, ha nincs ilyen nap)! (kereses)
    */
    /*
        Specifikacio:
        Be: homersekletek eleme Nap[e..u],
            Nap = legkisebb x legnagyobb, legkisebb eleme Z, legnagyobb eleme Z
        Ki: van eleme L, ind eleme N
        Ef: -
        Uf: (van, ind) = KERES(i = e..u, homersekletek[i].legnagyobb < homersekletek[i - 1].legkisebb)
    */
    static void KissebbMax(Nap[] homersekletek)
    {
        int ind = 0;
        bool van = false;

        for (int i = 1; i < homersekletek.Length; i++)
        {
            if (homersekletek[i].legnagyobb < homersekletek[i - 1].legkisebb)
            {
                ind = i;
                van = true;
                break;
            }
        }

        Console.WriteLine(van ? (ind + 1) : -1);
    }

    /*
        4. részfeladat: azon napok számát és sorszámait kell kiírni, ahol fagyni is fog és olvadni is 
            (a sorszámokat növekvő sorrendben) egy-egy szóközzel elválasztva! (kivalogatas)
    */
    /*
        Specifikacio:
        Be: homersekletek eleme Nap[e..u],
            Nap = legkisebb x legnagyobb, legkisebb eleme Z, legnagyobb eleme Z
        Ki: db eleme N, napok eleme Z[1..db]
        Ef: -
        Uf: (db, napok) = KIVALOGAT(i = e..u, homersekletek[i].legkisebb <= 0, homersekletek[i].legnagyobb > 0)
    */
    static void FagyasOlvadas(Nap[] homersekletek)
    {
        int db = 0;
        int[] napok = new int[homersekletek.Length];

        for (int i = 0; i < homersekletek.Length; i++)
        {
            if (homersekletek[i].legkisebb <= 0 && homersekletek[i].legnagyobb > 0)
            {
                napok[db] = i + 1;
                db++;
            }
        }

        Console.Write($"{db} ");

        for (int i = 0; i < db; i++)
        {
            Console.Write($"{napok[i]} ");
        }

        Console.WriteLine("");
    }

    struct Nap
    {
        public int legkisebb;
        public int legnagyobb;
    }

    public static void Main(string[] args)
    {
        int n;
        int.TryParse(Console.ReadLine() , out n);

        Nap[] homersekletek = new Nap[n];

        for (int i = 0; i < n; i++)
        {
            string sor = Console.ReadLine();

            homersekletek[i].legkisebb = int.Parse(sor.Split(" ")[0]);
            homersekletek[i].legnagyobb = int.Parse(sor.Split(" ")[1]);
        }

        // 1. részfeladat: azon napok számát kell kiírni, amikor fagyi fog! (megszamolas)
        Console.WriteLine("#");
        FagyNapok(homersekletek);

        /*
            2. részfeladat: azt a napot kell kiírni, ahol a legnagyobb a különbség a várható minimális és 
               maximális hőmérséklet között (ha több ilyen van, akkor a legkisebb sorszámút)!
        */
        Console.WriteLine("#");

        int[] kulonbsegek = new int[n];

        for (int i = 0; i < n; i++)
        {
            kulonbsegek[i] = (homersekletek[i].legnagyobb - homersekletek[i].legkisebb);
        }

        LegnagyobbKulonbseg(kulonbsegek);

        /*
            3. részfeladat: egy olyan napot kell kiírni, amikor a napi maximum kisebb az előző napi minimumnál
               (ha több ilyen van, akkor a legkisebb sorszámút; -1-et, ha nincs ilyen nap)! 
        */
        Console.WriteLine("#");
        KissebbMax(homersekletek);

        /*
            4. részfeladat: azon napok számát és sorszámait kell kiírni, ahol fagyni is fog és olvadni is 
               (a sorszámokat növekvő sorrendben) egy-egy szóközzel elválasztva!
        */
        Console.WriteLine("#");
        FagyasOlvadas(homersekletek);
    }
}