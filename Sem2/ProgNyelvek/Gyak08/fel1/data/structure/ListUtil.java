package data.structure;

import java.util.*;

public class ListUtil {
    public static ArrayList<Integer> divisors(int n) {
        if (n <= 0)
            return new ArrayList<Integer>();

        ArrayList<Integer> result = new ArrayList<Integer>();

        int k = 1;

        while (k <= n) {
            if (n % k == 0)
                result.add(k);
            k++;
        }

        return result;
    }

    public static ArrayList<String> withSameStartEnd(ArrayList<String> xs) {
        return new ArrayList<String>();
    }

    public static void maxToFront(ArrayList<String> xs) {}
}