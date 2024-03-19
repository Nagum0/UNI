package famous.sequence;

public class TriangularNumbers {
    public static int getTriangularNumber(int index) {
        if (index < 1) {
            throw new IllegalArgumentException("Only positive!");
        }

        int res = 0;

        for (int i = 0; i <= index; i++) {
            res += i;
        }

        return res;
    }
}
