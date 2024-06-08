namespace src;

class Program {
	public static void MergeSort(ref int[] A) {
		// B[0..n) := A[0..n)
		int[] B = A.Select(i => i).ToArray();
		Ms(ref B, ref A, 0, B.Length);	
	}

	private static void Ms(ref int[] B, ref int[] A, int u, int v) {
		if (v - u > 1) {
			int m = (u + v) / 2;
			Ms(ref A, ref B, u, m);
			Ms(ref A, ref B, m, v);
			Merge(ref B, ref A, u, m, v);
		}
		else {
			return;
		}
	}

	private static void Merge(ref int[] B, ref int[] A, int u, int m, int v) {
		int k = u;
		int i = u;
		int j = m;

		while (i < m && j < v) {
			if (B[i] <= B[j]) {
				A[k] = B[i];
				i++;
			}
			else {
				A[k] = B[j];
				j++;
			}
 			k++;
		}

		if (i < m) {
			for (; i < m; i++) {
				A[k] = B[i];
				k++;
			}
		}
		else
			for (; j < v; j++) {
				A[k] = B[j];
				k++;
			}
	}

	public static void Main(string[] args) {
		int[] xs = [2, 1, 4, 3, 5];
		Console.WriteLine(string.Join(", ", xs));
		MergeSort(ref xs);
		Console.WriteLine(string.Join(", ", xs));
	}
}