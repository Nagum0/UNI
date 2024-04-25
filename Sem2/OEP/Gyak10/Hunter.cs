namespace Gyak10
{
    public class Hunter
    {
        private string name;
        private string birthYear;
        private HashSet<Trophy> trophies;

        public Hunter(string name, string birthYear)
        {
            this.name = name;
            this.birthYear = birthYear;
            trophies = new HashSet<Trophy>();
        }

        public void Hunt(string site, string date, Game prey)
        {
            trophies.Add(new Trophy(site, date, prey));
        }

        public int MaleLions()
        {
            return trophies.Count(
                (t) => t.getPrey() is Lion l && 
                       l.getSex() == Sex.MALE
            );
        }

        public (bool, double, Trophy) LargestHorn()
        {
            Trophy? max = trophies
                .Where(
                    (t) => t.getPrey() is Rhino
                )
                .MaxBy(
                    (t) => ((Rhino)t.getPrey()).horn / t.getPrey().weight
            );

            return (max == null, 
                    ((Rhino) max.getPrey()).horn / max.getPrey().weight, 
                    max
            );
        }

        public bool EqualLength()
        {
            return trophies.Any(
                (t) => t.getPrey() is Elephant e &&
                       e.right == e.left
            );
        }
    }
}
