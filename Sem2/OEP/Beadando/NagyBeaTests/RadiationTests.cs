using NagyBea;

namespace NagyBeaTests {
    [TestClass]
    public class RadiationTests {
        [TestMethod]
        public void TestEffectAlpha() {
            Alpha alpha = new Alpha();
            Puffancs puffancs = new Puffancs("Falánk", 7);
            Deltafa deltafa = new Deltafa("Sudár", 5);
            Parabokor parabokor = new Parabokor("Köpcös", 4);
        
            alpha.Effect(puffancs);
            Assert.AreEqual(9, puffancs.Sustenance);

            alpha.Effect(deltafa);
            Assert.AreEqual(2, deltafa.Sustenance);

            alpha.Effect(parabokor);
            Assert.AreEqual(5, parabokor.Sustenance);    
        }

        [TestMethod]
        public void TestEffectDelta() {
            Delta delta = new Delta();
            Puffancs puffancs = new Puffancs("Falánk", 7);
            Deltafa deltafa = new Deltafa("Sudár", 5);
            Parabokor parabokor = new Parabokor("Köpcös", 4);

            delta.Effect(puffancs);
            Assert.AreEqual(5, puffancs.Sustenance);

            delta.Effect(deltafa);
            Assert.AreEqual(6, deltafa.Sustenance);

            delta.Effect(parabokor);
            Assert.AreEqual(5, parabokor.Sustenance);
        }

        [TestMethod]
        public void TestEffectNone() {
            None none = new None();
            Puffancs puffancs = new Puffancs("Falánk", 7);
            Deltafa deltafa = new Deltafa("Sudár", 5);
            Parabokor parabokor = new Parabokor("Köpcös", 4);
        
            none.Effect(puffancs);
            Assert.AreEqual(6, puffancs.Sustenance);

            none.Effect(deltafa);
            Assert.AreEqual(4, deltafa.Sustenance);

            none.Effect(parabokor);
            Assert.AreEqual(3, parabokor.Sustenance);
        }
    }
}