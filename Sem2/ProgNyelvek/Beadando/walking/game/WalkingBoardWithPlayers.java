package walking.game;

import walking.game.player.*;

public class WalkingBoardWithPlayers extends WalkingBoard {
    private Player[] players;
    private int round;
    public static final int SCORE_EACH_STEP = 13;

    public WalkingBoardWithPlayers(int[][] board, int playerCount) {
        super(board);
        initPlayers(playerCount);
    }

    public WalkingBoardWithPlayers(int size, int playerCount) {
        super(size);
        initPlayers(playerCount);
    }

    private void initPlayers(int playerCount) {
        if (playerCount < 2)
            throw new IllegalArgumentException("Not enough players!");
        
        players = new Player[playerCount];
        players[0] = new MadlyRotatingBuccaneer();

        for (int i = 1; i < playerCount; i++)
            players[i] = new Player();
    }

    /* ITT TARTASZ */
    public int[] walk(int... stepCounts) {
        int i = 0;
        int playerIndex = 0;

        while (i < stepCounts.length) {        
            if (playerIndex == players.length)
                playerIndex = 0;

            System.out.println("step: " + i + " playerIndex: " + playerIndex + " stepsToTake: " + stepCounts[i]);

            players[playerIndex].turn();

            playerIndex++;
            i++;
        }

        return new int[0];
    }
}