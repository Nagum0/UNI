package data.organiser;

import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;

import java.util.*;

public class OrganiserTest {
    @Test
    public void testEncapsulation() {
        Organiser<String> org = new Organiser<String>("Zeki", "Balazs", "Roland");
        ArrayList<String> xs = org.get();
        xs.set(0, "Dani");
        assertEquals("Zeki", org.get(0));
    }
}