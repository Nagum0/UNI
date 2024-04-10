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

}