import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;

import java.io.*;

import text.to.numbers.*;

public class SingleLineFileTest {
    @Test
    public void testAddNumbers() {
        try {
            assertEquals(69, SingleLineFile.addNumbers("test.txt"));
        }
        catch (IOException e) {
            System.err.println(e);
        }

        assertThrows(IOException.class, () -> SingleLineFile.addNumbers("t.txt"));
    }
}