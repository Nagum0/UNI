package data.structure;

import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;

public class MultiSetTest {
    @Test
    public void testGetCount() {
        MultiSet<String> msString = new MultiSet<String>(new String[]{"Zeki", "Idk"});
        msString.add("Zeki");
        msString.add("Zeki");

        assertEquals(3, msString.getCount("Zeki"));
        assertEquals(1, msString.getCount("Idk"));
    }

    @Test
    public void testIntersect() {
        MultiSet<String> msString = new MultiSet<String>(new String[]{"Zeki", "Idk"});
        msString.add("LVL 10 GYATT");
        MultiSet<String> msString2 = new MultiSet<String>(new String[]{"Zeki", "Idk", "LOL"});
        MultiSet<String> result = msString.intersect(msString2);

        assertEquals(2, result.size());
        assertEquals(true, result.containsElem("Zeki"));
        assertEquals(true, result.containsElem("Idk"));
        assertEquals(false, result.containsElem("LOL"));
    }
}