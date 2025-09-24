using Gyak11;

namespace DummyTest
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestCorrectIsDivisible()
        {
            Dummy tested = new Dummy("Zeki");
            Assert.IsTrue(tested.IsDivisible(3, 3));
            Assert.IsTrue(tested.IsDivisible(6, 3));
        }

        [TestMethod]
        public void TestIncorrectIsDivisible()
        {
            Dummy tested = new Dummy("Zeki");
            Assert.IsFalse(tested.IsDivisible(2, 3));
        }

        [TestMethod]
        public void TestIsDivisibleException()
        {
            Dummy tested = new Dummy("Zeki");
            Assert.ThrowsException<ArgumentException>(() => tested.IsDivisible(5, 0));
        }
    }
}