using Gyak04;

namespace Gyak04Test
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void EmptyOnCreation()
        {
            Map map = new Map();
            Assert.AreEqual(0, map.Count());
            Assert.IsTrue(map.Count() == 0);
            Item item = new Item(1, "Zeki");
            Assert.ThrowsException<Exception>(() => map.Remove(1));
        }

        [TestMethod]
        public void TestIdk()
        {
            Map map = new Map();
            Assert.AreEqual(0, map.Count());
        }
    }
}