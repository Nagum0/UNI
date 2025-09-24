package race.car;

import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;

public class WrongSectorTimer1Test {
    @Test
    public void setArrayElemsBreaksEncapsulation() {
        WrongSectorTimer1 seemsGood = new WrongSectorTimer1(new int[3]);
        seemsGood.sectorTimes[0] = 10;
        seemsGood.sectorTimes[1] = 10;
        seemsGood.sectorTimes[2] = 10;
        assertEquals(seemsGood.sectorTimes[2], 10);
    }
}
