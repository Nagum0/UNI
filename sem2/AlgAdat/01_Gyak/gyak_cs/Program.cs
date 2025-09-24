namespace GYAK01 {
    internal class Program {

        /* Linear search: */
        static uint LinKer<T>(T[] a, Func<T, bool> f) {
            uint i = 0;
            while (i < a.Length && !f(a[i])) i++;
            return i;
        }

        /* Maximum search: */
        static (int, uint) MaxKer(int[] a) {
            int maxe = a[0];
            uint maxi = 0;

            for (uint i = 1; i < a.Length; i++) {
                if (a[i] > maxe) {
                    maxe = a[i];
                    maxi = i;
                }
            }

            return (maxe, maxi);
        }

        /* InsertionSort/MaxKivRendezes */
        static void InsertionSort(ref int[] a) {
            for (int i = a.Length - 1; i >= 1; i--) {
                int ind = 0;
                for (int j = 0; j < i; j++) {
                    if (a[j] > a[ind]) {
                        ind = j;
                    }
                }
                int temp = a[i];
                a[i] = a[ind];
                a[ind] = temp;
            }
        }

        public static void Main(string[] args) {
            string[] strs = {
                "Astolfo",
                "Zeki",
                "Sheeesh",
                "Cute catgirl"
            };
            uint i1 = LinKer(strs, x => x == "Zeki");
            Console.WriteLine(i1);

            int[] xs = {4,5,2,69,1,3};
            (int maxe, uint maxi) = MaxKer(xs);
            Console.WriteLine($"Maxe: {maxe}; Maxi: {maxi}");

            InsertionSort(ref xs);
            Console.WriteLine(string.Join(", ", xs));
        }
    }
}