namespace HF6 {
    public class Program {
        public static void Main(string[] args) {
            uint income = 0;
            Receipts rs = new Receipts(args[0]); 

            foreach (Receipt r in rs) {
                income += r.Sum();
            }

            Console.WriteLine(income);
        }
    }
}
