/* ITT SAJAT TESZTEKET IROK */

package famous.sequence;

import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;

public class FibonacciTest {
    @Test
    public void baseRecursionCasesTest() {
        assertEquals(1, Fibonacci.fib(1));
        assertEquals(1, Fibonacci.fib(2));
    }

    @Test
    public void firstFiveCasesTest() {
        assertEquals(1, Fibonacci.fib(1));
        assertEquals(1, Fibonacci.fib(2));
        assertEquals(2, Fibonacci.fib(3));
        assertEquals(3, Fibonacci.fib(4));
        assertEquals(5, Fibonacci.fib(5));
    }

    @Test
    public void firstFiveCasesLoopTest() {
        int expectedArray[] = {1,1,2,3,5};
        for (int i = 1; i < expectedArray.length + 1; i++) {
            assertEquals(expectedArray[i - 1], Fibonacci.fib(i));
        }
    } 
}