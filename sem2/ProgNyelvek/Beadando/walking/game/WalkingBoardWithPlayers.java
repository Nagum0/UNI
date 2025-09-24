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

    public int[] walk(int... stepCounts) {
        int i = 0;
        int playerIndex = 0;

        while (i < stepCounts.length) {        
            if (playerIndex == players.length)
                playerIndex = 0;

            players[playerIndex].turn();
            int moveAndSetValue = i > SCORE_EACH_STEP ? SCORE_EACH_STEP : i;

            for (int j = 0; j < stepCounts[i]; j++) {
                int scoreToAdd = super.moveAndSet(players[playerIndex].getDirection(), moveAndSetValue);
                players[playerIndex].addToScore(scoreToAdd);
            }

            playerIndex++;
            i++;
        }

        int[] playerScores = new int[players.length];

        for (int k = 0; k < players.length; k++) {
            playerScores[k] = players[k].getScore();
        }
        
        return playerScores;
    }
}
