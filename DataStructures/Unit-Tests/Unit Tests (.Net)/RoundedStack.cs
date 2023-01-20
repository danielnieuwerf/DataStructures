using Data_Structures__C_Sharp_;

namespace Unit_Tests__.Net_
{
    [TestClass]
    public class RoundedStackTests
    {
        [TestMethod]
        public void InitiallyEmpty()
        {
            RoundedStack<int> stack = new RoundedStack<int>(10);
            Assert.IsTrue(stack.Count == 0);
        }

        [TestMethod]
        public void BehavesLikeStackIfCapNotExceeded()
        {
            RoundedStack<char> stack = new RoundedStack<char>(30);
            string data= "data_to_push_on_stack";
            string expectedOutput = "kcats_no_hsup_ot_atad";
            string output = string.Empty;

            foreach(var elem in data)
                stack.Push(elem);

            Assert.AreEqual(stack.Count, data.Length);

            while(stack.Count > 0)
            {
                output += stack.Pop();
            }

            Assert.AreEqual(expectedOutput, output);
        }

        [TestMethod]
        public void BottomOfStackIsDroppedWhenFull()
        {
            RoundedStack<int> stack = new RoundedStack<int>(3);
            for(int i = 1; i<= 4; ++i)
                stack.Push(i);
            Assert.AreEqual(3, stack.Count);

            int expectedVal = 4;
            while(stack.Count > 0)
            {
                Assert.AreEqual(expectedVal, stack.Pop());
                --expectedVal;
            }
        }
    }
}