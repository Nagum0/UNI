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
        ArrayList<String> result = new ArrayList<String>();
        
        for (String x : xs) {
            if (x == null) 
                continue;

            if (!x.equals("") && x.charAt(0) == x.charAt(x.length() - 1))
                result.add(x);
        }

        return result;
    }

    public static void maxToFront(ArrayList<String> xs) {
        if (xs == null || xs.isEmpty())
            return;
        
        String max = Collections.max(xs);
        xs.remove(max);
        xs.add(0, max);
    }
}