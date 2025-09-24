import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;

import text.util.*;

public class CharacterStatisticsTest {
    @Test
    public void testGetCount() {
        CharacterStatistics cs = new CharacterStatistics("astolfo");
        assertEquals(2, cs.getCount('o'));
    }

    @Test
    public void testToString() {
        CharacterStatistics cs1 = new CharacterStatistics("aaaaaaaa");
        assertEquals("a(8) ", cs1.toString());
        
        CharacterStatistics cs2 = new CharacterStatistics("HgFeDcBa");
        assertEquals("a(1) B(1) c(1) D(1) e(1) F(1) g(1) H(1) ", cs2.toString());
        
        CharacterStatistics cs3 = new CharacterStatistics("a?!_#@{}");
        assertEquals("@(1) a(1) !(1) #(1) {(1) }(1) ?(1) _(1) ", cs3.toString());

        CharacterStatistics cs4 = new CharacterStatistics(" Hello world!");
        assertEquals(" (2) !(1) r(1) d(1) e(1) w(1) H(1) l(3) o(2) ", cs4.toString());
    }
}