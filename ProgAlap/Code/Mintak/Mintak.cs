using System;

namespace ProgAlap {
    public class Mintak {
        #region METHODS

        // OSSZEGZES - SZUMMA
        /*
            Visszadja az lista elemeinek az osszeget a feltetel szerint.
            Ha nincs feltetel, akkor az osszes elemet osszadja.
        */
        public int Sum(List<int> xs, Func<int, bool>? T = null) {
            int s = 0;

            for (int i = 0; i < xs.Count; i++) {
                if (T == null || T(i)) {
                    s += xs[i];
                }
            }

            return s;
        }

        // MEGSZAMOLAS
        /*
            Megszamolja, hogy hany darab elem talalhato a listaban, 
            ami megfelel a feltetlnek.
        */
        public int Darab<H>(List<H> xs, Func<int, bool> T) {
            int db = 0;

            for (int i = 0; i < xs.Count; i++) {
                if (T(i)) {
                    db++;
                }
            }

            return db;
        }

        // MAX
        /*
            Visszadja a legnagyobb elem indexet es erteket a listaban.
            Feltetelt is kaphat.
        */
        public (int maxi, int maxe) Max(List<int> xs, Func<int, bool>? T = null) {
            int maxi = 0;
            int maxe = xs[0];

            for (int i = 0; i < xs.Count; i++) {
                if (T == null || T(i)) {
                    if (xs[i] > maxe) {
                        maxe = xs[i];
                        maxi = i;
                    }
                }
            }

            return (maxi, maxe);
        }

        // MIN
        /*
            Visszadja a legkisebb elem indexet es erteket a listaban.
            Feltetelt is kaphat.
        */
        public (int mini, int mine) Min(List<int> xs, Func<int, bool>? T = null) {
            int mini = 0;
            int mine = xs[0];

            for (int i = 0; i < xs.Count; i++) {
                if (T == null || T(i)) {
                    if (xs[i] < mine) {
                        mine = xs[i];
                        mini = i;
                    }
                }
            }

            return (mini, mine);
        }

        // KERES
        /*
            Keres egy erteket a listaban feltetel szerint es visszaadja azt,
            hogy letezik e ilyen elem es az indexet.
        */
        public (bool van, int ind) Keres<H>(List<H> xs, Func<int, bool> T) {
            bool van = false;
            int ind = 0;

            for (int i = 0; i < xs.Count && !van; i++) {
                if (T(i)) {
                    van = true;
                }
                else {
                    ind++;
                }
            }

            return (van, ind);
        }

        // VAN
        /*
            Feltel szerint megallapitsa, hogy van e megfelelo elem.
        */
        public bool Van<H>(List<H> xs, Func<int, bool> T) {
            bool van = false;

            for (int i = 0; i < xs.Count && !van; i++) {
                if (T(i)) {
                    van = true;
                }
            }

            return van;
        }

        // MIND
        /*
            Ellenorzi, hogy minden elem megfelel e a feltetelnek.
        */
        public bool Mind<H>(List<H> xs, Func<int, bool> T) {
            bool mind = true;

            for (int i = 0; i < xs.Count && mind; i++) {
                if (!T(i)) {
                    mind = false;
                }
            }

            return mind;
        }

        // KIVALASZTAS
        /*
            Visszaadja az elso olyan elem indexet, ami megfelel a feltetelnek.
        */
        public int Kivalaszt<H>(List<H> xs, Func<int, bool> T) {
            for (int i = 0; i < xs.Count; i++) {
                if (T(i)) {
                    return i;
                }
            }

            return -1;
        }

        // MASOLAS
        /*
            Egy lista minden elemere alkamaz egy fuggvenyt es atmasolja egy
            masik listaba.
            Hasonlo egy `map` fuggvenyre.
        */
        public List<HOut> Masol<HIn, HOut>(List<HIn> xs, Func<HIn, HOut> T) {
            List<HOut> out_xs = new List<HOut>();

            for (int i = 0; i < xs.Count; i++) {
                out_xs.Add(T(xs[i]));
            }

            return out_xs;
        }

        // KIVALOGATAS
        /*
            Atmasolja azokat az elemeket egy uj listaba, amik megfelelnek a
            feltetelnek.
            Hasonlo a `filter` fuggvenyre.
        */
        public List<H> Kivalogat<H>(List<H> xs, Func<int, bool> T) {
            List<H> out_xs = new List<H>();

            for (int i = 0; i < xs.Count; i++) {
                if (T(i)) {
                    out_xs.Add(xs[i]);
                }
            }

            return out_xs;
        }

        #endregion
    }
}