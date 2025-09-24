package famous.sequence;

import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;


public class TriangularNumbersTest {
    @Test
    public void dummyTest() {

    }

    @Test
    public void triangularNumsTestBaseCase() {
        assertEquals(1, TriangularNumbers.getTriangularNumber(1));
        assertEquals(3, TriangularNumbers.getTriangularNumber(2));
        assertEquals(6, TriangularNumbers.getTriangularNumber(3));
    }

    /* Ez egy csomoszor lefog futni a CsvSource miatt! */
    @ParameterizedTest
    @CsvSource({
        "1, 1",
        "3, 2",
        "6, 3",
        "10, 4"
    })
    public void triangularNumsParamTestBaseCase(int expected, int triagIndex) {
        assertEquals(expected, TriangularNumbers.getTriangularNumber(triagIndex));
    }

    /* Itt a hibas esetet kezeljuk az assertThrows-val! */
    @Test
    public void testInvalidInput() {
        Exception ex = assertThrows(IllegalArgumentException.class, () -> 
            TriangularNumbers.getTriangularNumber(0)
        );
    }
}