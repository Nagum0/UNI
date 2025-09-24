namespace Gyak08
{
    public class Vegetable : Plant
    {
        // Itt a base() meghivja a szulo osztaly konstruktorat es utana futatja le a kapcsos zarojelekben a kodot;
        public Vegetable(int harvestTime) : base(harvestTime) { }

        public override bool IsVegetable()
        {
            return true;
        }
    }
}
