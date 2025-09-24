using NagyBea;

namespace NagyBeaTests {
    [TestClass]
    public class PlanetTests {
        [TestMethod]
        public void TestDay() {
            Planet p = new Planet(new List<Plant> {
                new Puffancs("Falánk", 7),
                new Deltafa("Sudár", 5),
                new Parabokor("Köpcös", 4),
                new Deltafa("Nyúlánk", 3)
            });

            p.Day();

            Assert.AreEqual(11, p.Alpha);
            Assert.AreEqual(4, p.Delta);
            
            Assert.AreEqual(6, p.GetPlants()[0].Sustenance);
            Assert.AreEqual(4, p.GetPlants()[1].Sustenance);
            Assert.AreEqual(3, p.GetPlants()[2].Sustenance);
            Assert.AreEqual(2, p.GetPlants()[3].Sustenance);

            // With this I test ChangeRadiation too;
            Assert.AreEqual("Alpha", p.GetRadiation().ToString());
        }

        [TestMethod]
        public void TestEditAphaAndEditDelta() {
            Planet p = new Planet(new List<Plant>());
            p.EditAlpha(2);
            p.EditDelta(3);

            Assert.AreEqual(2, p.Alpha);
            Assert.AreEqual(3, p.Delta);
        }
    }
}
