using NagyBea;

namespace NagyBeaTest {
    [TestClass]
    public class PlantTests {
        [TestMethod]
        public void TestEditSustenance() {
            Deltafa d1 = new Deltafa("Zeki", 12);
            d1.EditSustenance(57);
            Assert.AreEqual(69, d1.Sustenance);
        }

        [TestMethod]
        public void TestPlantIsAlive() {
            Deltafa d1 = new Deltafa("Zeki", 12);
            Assert.IsTrue(d1.IsAlive());

            Puffancs p1 = new Puffancs("Bossman", 69);
            p1.EditSustenance(-69);
            Assert.IsFalse(p1.IsAlive());
        }
    }
}