package walking.game;

/* 
    TEMPORARY!!!
    DELETE EVERYTHING AFTER REACHING THIS POINT!!!
*/

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

public class WalkingBoardWithPlayersTest {
    @Test
    public void walk1() {
        int[][] boardEndState = {
            {3, 1, 1, 1},
            {3, 3, 3, 4},
            {3, 3, 3, 5},
            {6, 6, 6, 5}
        };

        int[] finalScores = {9, 12, 6};

        WalkingBoardWithPlayers wbs = new WalkingBoardWithPlayers(4, 3);
        int[] scores = wbs.walk(2, 3, 2, 4, 1, 2, 5, 2, 4);
        int[][] wbsTiles = wbs.getTiles();

        assertArrayEquals(boardEndState, wbsTiles);
        assertArrayEquals(finalScores, scores);
    }

    @Test
    public void walk2() {

    }
}