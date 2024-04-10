package text.util;

import java.util.*;

public class CharacterStatistics {
    private HashMap<Character, Integer> charToCount;

    public CharacterStatistics(String text) {
        this.charToCount = new HashMap<Character, Integer>();

        for (char c : text.toCharArray()) {
            if (this.charToCount.containsKey(c)) {
                this.charToCount.put(c, this.charToCount.get(c) + 1);
                continue;
            }
            this.charToCount.put(c, 1);
        }
    }

    @Override
    public String toString() {
        String result = "";

        for (Map.Entry<Character, Integer> entry : this.charToCount.entrySet())
            result = result.concat(entry.getKey() + "(" + entry.getValue() + ") ");

        return result;
    }

    public int getCount(char c) {
        if (this.charToCount.containsKey(c)) {
            return this.charToCount.get(c);
        }

        return 0;
    }
}