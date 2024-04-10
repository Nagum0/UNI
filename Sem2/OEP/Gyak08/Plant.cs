namespace Gyak08
{
    public class Plant
    {
        protected int harvestTime;
        
        public Plant(int harvestTime)
        {
            this.harvestTime = harvestTime;
        }

        public virtual bool IsVegetable()
        { 
            return false; 
        }

        public virtual bool IsFlower() 
        {
            return false;
        }

        public int GetHarvestTime()
        {
            return harvestTime;
        }
    }
}
