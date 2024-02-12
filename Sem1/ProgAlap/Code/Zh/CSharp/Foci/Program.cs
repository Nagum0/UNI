using System;

class Meccs {
    public string hazai;
    public string idegen;
    public int hazai_gol;
    public int idegen_gol;

    public Meccs(string hazai, string idegen, int hazai_gol, int idegen_gol) {
        this.hazai = hazai;
        this.idegen = idegen;
        this.hazai_gol = hazai_gol;
        this.idegen_gol = idegen_gol;
    }
}

class FociEredmenyek {
    static (string, List<Meccs>) Beolvas() {
        string param = "";
        List<Meccs> meccsek = new List<Meccs>();

        string[] elso_sor = Console.ReadLine().Split(" ");
        int n = int.Parse(elso_sor[0]);
        param = elso_sor[1];

        for (int i = 0; i < n; i++) {
            string[] sor_adatok = Console.ReadLine().Split(" ");
            meccsek.Add(new Meccs(
                sor_adatok[0],
                sor_adatok[1],
                int.Parse(sor_adatok[2]),
                int.Parse(sor_adatok[3])
            ));   
        }

        return (param, meccsek);
    }
    
    // 1. részfeladat: Az első sorba a legtöbb gólt rúgó csapat nevét kell kiírni! Ha több ilyen lenne, akkor
    // a bemenet sorrendjében az első ilyet kell megadni.
    static string LegtobbGol(List<Meccs> meccsek) {
        string csapat = meccsek[0].hazai;
        int maxval = meccsek[0].hazai_gol;

        foreach (Meccs meccs in meccsek) {
            if (meccs.hazai_gol > maxval) {
                csapat = meccs.hazai;
                maxval = meccs.hazai_gol;
            }
            else if (meccs.idegen_gol > maxval) {
                csapat = meccs.idegen;
                maxval = meccs.idegen_gol;
            }             
        }

        return csapat;
    } 
    
    /* 2. részfeladat: Az első sorba azon csapatok darabszámát kell kiírni, amelyek több gólt lőttek, mint
    az ellenfelük, majd a csapatok neveit kell kiírni, szóközzel elválasztva, a bemenet sorrendjében, és
    minden csapat nevét csak egyszer. Ha nincs ilyen csapat, akkor a 0-t kell kiírni. */
    static (int, List<string>) Gyoztesek(List<Meccs> meccsek) {
        List<string> csapatok = new List<string>();
        int n = 0;

        foreach (Meccs meccs in meccsek) {
            if (meccs.hazai_gol > meccs.idegen_gol && !csapatok.Contains(meccs.hazai)) {
                csapatok.Add(meccs.hazai);
                n++;
            }
            else if (meccs.hazai_gol < meccs.idegen_gol && !csapatok.Contains(meccs.idegen)) {
                csapatok.Add(meccs.idegen);
                n++;
            }
        }

        return (n, csapatok);
    }

    /* 3. részfeladat: Az első sorba a meccseken játszó csapatok darabszámát kell kiírni. */
    static int CsapatokSzama(List<Meccs> meccsek) {
        int db = 0;
        List<string> csapatok = new List<string>();

        foreach (Meccs meccs in meccsek) {
            if (!csapatok.Contains(meccs.hazai) && !csapatok.Contains(meccs.idegen)) {
                csapatok.Add(meccs.hazai);
                csapatok.Add(meccs.idegen);
                db += 2;
            }
            else if (!csapatok.Contains(meccs.hazai)) {
                csapatok.Add(meccs.hazai);
                db++;
            }
            else if (!csapatok.Contains(meccs.idegen)) {
                csapatok.Add(meccs.idegen);
                db++;
            }
        }

        return db;
    }

    /* 4. részfeladat: Az első sorba három számot kell kiírni, szóközzel elválasztva, az első szám a para-
    méterben megadott csapat rúgott góljainak számát, a második szám a paraméterben megadott csa-
    pat kapott góljainak számát, valamint a harmadik szám a pataméterben megadott csapat által szer-
    zett pontok számát adja meg. Ha paraméterben megadott csapat nem játszott, akkor 0 0 0-t kell
    kiírni. */
    static (int, int, int) ParamCsapatAdatai(string csapat, List<Meccs> meccsek) {
        int golok = 0;
        int kapott = 0;
        int pontok = 0;

        foreach (Meccs meccs in meccsek) {
            if (meccs.hazai == csapat) {
                golok += meccs.hazai_gol;
                kapott += meccs.idegen_gol;
                if (meccs.hazai_gol > meccs.idegen_gol) {
                    pontok += 3;
                }
                else if (meccs.hazai_gol == meccs.idegen_gol) {
                    pontok += 1;
                }
            }
            else if (meccs.idegen == csapat) {
                golok += meccs.idegen_gol;
                kapott += meccs.hazai_gol;
                if (meccs.hazai_gol < meccs.idegen_gol) {
                    pontok += 3;
                }
                else if (meccs.hazai_gol == meccs.idegen_gol) {
                    pontok += 1;
                }
            }
        }

        return (golok, kapott, pontok); 
    }
    /* 5. részfeladat: Annyi sort kell kiírni, ahány csapat játszott. Minden sor egy csapatnevet és a csapat
      által lejátszott meccsek számát tartalmazza, a bemenet sorrendjében. */
    struct Csapat {
        public string nev;
        public int n;

        public Csapat(string nev) {
            this.nev = nev;
        }
    }

    static List<Csapat> JatszottCsapatok(List<Meccs> meccsek) {
        List<Csapat> csapatok = new List<Csapat>();
        
        // Csapatok keszitese:
        foreach (Meccs meccs in meccsek) {
            Csapat hazai = new Csapat(meccs.hazai);
            Csapat idegen = new Csapat(meccs.idegen);

            
        }

        return csapatok;
    } 

    public static void Main(string[] args) {
        // Beolvasas:
        (string param, List<Meccs> meccsek) = Beolvas();

        // Feldolgozas:
        // 1.reszfeladat:
        Console.WriteLine("#");
        Console.WriteLine($"{LegtobbGol(meccsek)}");
        // 2.reszfeladat:
        Console.WriteLine("#");
        (int db, List<string> gyoztes_csapatok) = Gyoztesek(meccsek);
        Console.WriteLine($"{db} {string.Join(" ", gyoztes_csapatok)}");
        // 3.reszfeladat:
        Console.WriteLine("#");
        Console.WriteLine($"{CsapatokSzama(meccsek)}");
        // 4.reszfeladat:
        Console.WriteLine("#");
        (int golok, int kapott, int pontok) = ParamCsapatAdatai(param, meccsek);
        Console.WriteLine($"{golok} {kapott} {pontok}");
        // 5.reszfeladat:
        Console.WriteLine("#");
        List<Csapat> csapatok = JatszottCsapatok(meccsek);
        foreach (Csapat csapat in csapatok) {
            Console.WriteLine($"{csapat.nev} {csapat.n}");
        }
    }
}