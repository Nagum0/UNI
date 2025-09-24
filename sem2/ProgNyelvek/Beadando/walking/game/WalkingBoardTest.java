package walking.game;

import static check.CheckThat.*;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import org.junit.jupiter.api.condition.*;
import org.junit.jupiter.api.extension.*;
import org.junit.jupiter.params.*;
import org.junit.jupiter.params.provider.*;
import check.*;

import java.util.*;
import walking.game.util.*;

public class WalkingBoardTest {
    @ParameterizedTest
    @CsvSource({
        "3",
        "4",
        "5"
    })
    public void testSimpleInit(int size) {
        WalkingBoard board = new WalkingBoard(size);
        int[][] board_copy = board.getTiles();
        assertEquals(size, board_copy.length);
        assertEquals(size, board_copy[0].length);
        assertEquals(WalkingBoard.BASE_TILE_SCORE, board.getTile(0,0));
        assertEquals(WalkingBoard.BASE_TILE_SCORE, board.getTile(board_copy[0].length - 1, board_copy.length - 1));
        assertEquals(WalkingBoard.BASE_TILE_SCORE, board.getTile(board_copy[0].length - 1, 0));
        assertEquals(WalkingBoard.BASE_TILE_SCORE, board.getTile(0, board_copy.length - 1));
    }

    @ParameterizedTest
    @CsvSource({
        "4, 4, 69",
        "2, 2, 420",
        "10, 10, 4",
        "1, 1, 1"
    })
    public void  testCustomInit(int x, int y, int expected) {
        int[][] boardSchema = new int[y][x];
        
        for (int[] i : boardSchema)
            Arrays.fill(i, expected);
        
        WalkingBoard board = new WalkingBoard(boardSchema);

        int xCorTest = 0;
        int yCorTest = 0;

        boardSchema[yCorTest][xCorTest] = 100;
        if (expected > WalkingBoard.BASE_TILE_SCORE)
            assertEquals(expected, board.getTile(xCorTest, yCorTest));
        else
            assertEquals(WalkingBoard.BASE_TILE_SCORE, board.getTile(xCorTest, yCorTest));

        int[][] boardCopy = board.getTiles();
        boardCopy[yCorTest][xCorTest] = 100;
        if (expected > WalkingBoard.BASE_TILE_SCORE)
            assertEquals(expected, board.getTile(xCorTest, yCorTest));
        else
            assertEquals(WalkingBoard.BASE_TILE_SCORE, board.getTile(xCorTest, yCorTest));
    }

    @Test
    public void testMoves() {
        WalkingBoard board = new WalkingBoard(3);
        assertEquals(3, board.moveAndSet(Direction.RIGHT, 69));
        assertEquals(3, board.moveAndSet(Direction.DOWN, 420));
        assertEquals(69, board.moveAndSet(Direction.UP, 99));
        assertEquals(3, board.moveAndSet(Direction.LEFT, 69));

        assertEquals(0, board.moveAndSet(Direction.UP, 100));
        int[] currPos = board.getPosition();
        assertEquals(0, currPos[0]);
        assertEquals(0, currPos[1]);

        assertEquals(3, board.moveAndSet(Direction.DOWN, 78));
    }
}