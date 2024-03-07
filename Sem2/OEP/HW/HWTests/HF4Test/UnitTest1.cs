using HF4;

namespace HF4Test
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void SetEmptyTest()
        {
            PrQueue prq = new PrQueue();
            prq.Add(new Element(1, "Zeki"));
            prq.Add(new Element(12, "Astolfo"));
            prq.SetEmpty();
            Assert.IsTrue(prq.isEmpty());
        }

        [TestMethod]
        public void AddTest()
        {
            PrQueue prq = new PrQueue();
            prq.Add(new Element(1, "Zeki"));
            Assert.IsTrue(!prq.isEmpty());
        }

        [TestMethod]
        public void GetMaxTest()
        {
            PrQueue prq = new PrQueue();
            prq.Add(new Element(1, "Zeki"));
            prq.Add(new Element(100, "Astolfo"));
            prq.Add(new Element(23, "Sheeesh"));
            
        }
    }
}