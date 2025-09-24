namespace Gyak08
{
    // Ez egy 'singleton';
    // singleton = a program alatt csak 1 peldany letezik belole;
    // Ezert private a kons.;
    // Az instance static, mert osztalyszintu es csak egy van belole;
    public class Potato : Vegetable
    {
        private static Potato? instance = null;
        
        private Potato(int harvestTime) : base(harvestTime) { }
        
        public static Potato Instance()
        {
            if (instance == null)
            {
                instance = new Potato(10);
            }

            return instance;
        }
    }

    // Ha abstract, akkor nincs metodus megvalositas. Tehat, ha egy masik osztaly szarmazodik rola,
    // akkor ott kell implementalni;
    public abstract class Registration
    {
        public abstract int GetSize();
    }
}
