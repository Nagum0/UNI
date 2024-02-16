public class Gy3 {
    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    static long gcdMult(long[] args) {
        long result = args[0];

        for (int i = 1; i < args.length; i++) {
            result = gcd(result, args[i]);
        }

        return result;
    }

    public static void main(String[] args) {
        long[] nums = new long[args.length];

        for (int i = 0; i < args.length; i++) {
            nums[i] = Long.parseLong(args[i]);
        }

        System.out.println(gcdMult(nums));
    }
}