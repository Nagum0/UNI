public class Num {
    public static void main(String[] args) {
        // Feladat 7:
        if (args.length != 2) {
            System.out.println("2 numbers are needed!");
            return;
        }

        int n = Integer.parseInt(args[0]);
        int k = Integer.parseInt(args[1]);

        int ossz = n + k;
        int kul = n - k;
        int szor = n * k;

        if (k != 0) {
            int hanyados = n / k;
            int maradek = n % k;
            System.out.println(ossz + " " + kul + " " + szor + " " + hanyados + " " + maradek);
            return;
        }

        System.out.println(ossz + " " + kul + " " + szor + " ");
    }
}