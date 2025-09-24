import data.structure.*;
import java.util.*;

import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;

public class ListUtilTest {
    @Test
    public void testDivisors() {
        assertEquals(new ArrayList<Integer>(), ListUtil.divisors(0));
        
        ArrayList<Integer> one = new ArrayList<Integer>();
        one.add(1);
        assertEquals(one, ListUtil.divisors(1));

        ArrayList<Integer> sixtyfour = new ArrayList<Integer>();
        for (int i = 1; i <= 64; i++) {
            if (64 % i == 0)
                sixtyfour.add(i);
        }
        assertEquals(sixtyfour, ListUtil.divisors(64));
    }

    @Test
    public void testWithSameStartEnd() {
        ArrayList<String> output = new ArrayList<String>();
        ArrayList<String> xs = new ArrayList<String>();
        assertEquals(output, ListUtil.withSameStartEnd(xs));

        xs.add(null);
        assertEquals(output, ListUtil.withSameStartEnd(xs));

        xs.add(" ");
        output.add(" ");
        assertEquals(output, ListUtil.withSameStartEnd(xs));

        xs.add("x");
        output.add("x");
        assertEquals(output, ListUtil.withSameStartEnd(xs));

        xs.add("");
        assertEquals(output, ListUtil.withSameStartEnd(xs));

        xs.add("different start and end?");
        assertEquals(output, ListUtil.withSameStartEnd(xs));

        xs.add("ends and starts the same");
        output.add("ends and starts the same");
        assertEquals(output, ListUtil.withSameStartEnd(xs));
    }

    @Test
    public void testMaxToFront() {
        ArrayList<String> xs = new ArrayList<String>();
        ArrayList<String> output = new ArrayList<String>();

        ListUtil.maxToFront(xs);
        assertEquals(output, xs);

        xs.add("astolfo");
        output.add("astolfo");
        ListUtil.maxToFront(xs);
        assertEquals(output, xs);

        xs.clear();
        output.clear();

        xs.add("can");
        xs.add("you");
        xs.add("succeed");
        output.add("you");
        output.add("can");
        output.add("succeed");
        ListUtil.maxToFront(xs);
        assertEquals(output, xs);
    }
}