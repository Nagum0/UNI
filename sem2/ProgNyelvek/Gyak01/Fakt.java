public class Fakt {
    static int fact_rect(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        return n * fact_rect(n - 1);
    }

    static int fact_loop(int n) {
        int f = 1;

        for (int i = n; i > 0; i--) {
            f = f * i;
        }

        System.out.println(f);

        return f;
    }

    public static void main(String[] args) {
        int n = Integer.parseInt(System.console().readLine());
        System.out.println("Fact loop: " + fact_loop(n));
        System.out.println("Fact rect: " + fact_rect(n));
    }
}