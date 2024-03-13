package math.operation.safe;

import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;

public class IncrementTest {
    @Test
    public void nullIncrementTest() {
        assertEquals(1, Increment.increment(0));
    }

    @Test
    public void minValueIncrementTest() {
        assertEquals(Integer.MIN_VALUE + 1, Increment.increment(Integer.MIN_VALUE));
    }

    @Test
    public void maxValueIncrementTest() {
        assertEquals(Integer.MAX_VALUE, Increment.increment(Integer.MAX_VALUE));
    }

    @Test
    public void midPosValueIncrementTest() {
        assertEquals(Integer.MAX_VALUE / 2 + 1, Increment.increment(Integer.MAX_VALUE / 2));
    }

    @Test
    public void midNegValueIncrementTest() {
        assertEquals(Integer.MIN_VALUE / 2 + 1, Increment.increment(Integer.MIN_VALUE / 2));
    }

    @Test
    public void minusOneIncrementTest() {
        assertEquals(0, Increment.increment(-1));
    }
}