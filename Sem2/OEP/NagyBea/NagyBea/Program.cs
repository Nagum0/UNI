namespace NagyBea {
    public class Program {
        static void Main(string[] args) {
            Planet creek = new Planet(new List<Plant> {
                new Puffancs("pufi1", 10),
                new Deltafa("delti1", 8),
                new Parabokor("pari1", 5)
            });

            int n = 3;

            for (int i = 0; i < n; i++) {
                creek.Day();
            }
        }
    }
}
