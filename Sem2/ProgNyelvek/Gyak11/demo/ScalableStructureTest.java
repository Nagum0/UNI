import static check.CheckThat.*;
import static check.CheckThat.Condition.*;
import org.junit.jupiter.api.*;
import check.CheckThat;

/* 
import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;
*/

public class ScalableStructureTest {
    @BeforeAll
    public static void init() {
        CheckThat.theInterface("action.Scalable")
            .thatIs(VISIBLE_TO_ALL);
    }

    @Test
    public void methodScale() {
        it.hasMethod("scale", withParams("int"))
            .thatIs(NOT_IMPLEMENTED, INSTANCE_LEVEL, VISIBLE_TO_ALL)
            .thatReturnsNothing();
    }
}

