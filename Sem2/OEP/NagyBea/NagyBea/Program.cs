namespace NagyBea {
    public class Program {
        static (Planet, int) ReadFile(string path) {
            List<Plant> plants = new List<Plant>();
            int days = 0;

            using (StreamReader infile = new StreamReader(path)) {
                string line = infile.ReadLine();
                days = int.Parse(line);

                while ((line = infile.ReadLine()) != null) {
                    string[] data = line.Split(" ");
                    
                    switch (data[1]) {
                        case "p":
                            plants.Add(new Puffancs(data[0], int.Parse(data[2])));
                            break;
                        case "d":
                            plants.Add(new Deltafa(data[0], int.Parse(data[2])));
                            break;
                        case "b":
                            plants.Add(new Parabokor(data[0], int.Parse(data[2])));
                            break;
                    }
                }
            }

            return (new Planet(plants), days);
        }

        static void Main(string[] args) {
            (Planet p, int days) = ReadFile("input.txt");

            p.Day();
        }
    }
}
