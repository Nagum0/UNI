namespace src;

class Program {
	public static void Main(string[] args) {
		int[] xs = {5, 6, 1, 19, 0, 420};
		Sorting.MaxKivRend(ref xs, xs.Length);
		Console.WriteLine(string.Join(", ", xs));
	}
}