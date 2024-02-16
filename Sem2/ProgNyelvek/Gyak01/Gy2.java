public class Gy2 {
    static boolean isPerfect(int n) {
        int s = 1;

        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                s += i;
            }
        }

        return (n == s) ? true : false;
    } 

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int count = 0;

        for (int i = 2; i < n; i++) {
            if (isPerfect(i)) {
                count++;
            }
        }

        if (count == 0) {
            System.out.println("No perfect numbers were found!");
            return;
        }

        System.out.println(count + " perfect numbers were found!");
    }
}