package walking.game;

import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;

public class WalkingBoardTest {
    @Test
    public void testCons01() {
        WalkingBoard board = new WalkingBoard(5);
        assertEquals(true, board.isValidPosition(4, 4));
    }

    @Test
    public void testGetTile() {
        WalkingBoard board = new WalkingBoard(5);
        assertEquals(WalkingBoard.BASE_TILE_SCORE, board.getTile(3,3));
    }
}