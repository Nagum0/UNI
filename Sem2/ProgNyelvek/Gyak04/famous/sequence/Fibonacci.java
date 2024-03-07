package famous.sequence;

public class Fibonacci {
    public static int fib(int n) {
        if (n < 1) {
            throw new IllegalArgumentException("LMAO DUMBASS!");
        }

        if (n == 1) {
            return 1;
        }
        else if (n == 2) {
            return 1;
        }

        return fib(n - 1) + fib(n - 2);
    }
}