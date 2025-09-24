namespace src;

public class Sorting {
	private static void Swap(ref int a, ref int b) {
		int temp = a;
		a = b;
		b = temp;
	}

	public static void MaxKivRend(ref int[] t, int n) {
		for (int i = n - 1; i > 0; i--) {
			int ind = 0;
			for (int j = 0; j <= i; j++) {
				if (t[j] > t[ind])
					ind = j;
			}
			Swap(ref t[i], ref t[ind]);
		}
	}

	public static void InsertionSort(ref int[] t, int n) {
		
	}
}