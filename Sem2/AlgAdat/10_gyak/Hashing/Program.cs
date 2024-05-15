using Hashing;

class Program {
    public static void Main(string[] args) {
        HashDirect<string> table = new HashDirect<string>(5);
        table.Insert(new Record<string>(69, "Zeki"));
        table.Insert(new Record<string>(420, "Astolfo"));
        table.Insert(new Record<string>(420, "Ferris"));
        Console.WriteLine(table.ToString());
    }
}