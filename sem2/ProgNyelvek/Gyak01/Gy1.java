public class Gy1 {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int s = 1;

        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                s += i;
            }
        }

        if (s == n) {
            System.out.println(n + " is a perfect number!");
        }
        else {
            System.out.println(n + " is not a perfect number!");
        }
    }
}