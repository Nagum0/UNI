package walking.game.player;

public class MadlyRotatingBuccaneer extends Player {
    private int turnCount;

    @Override
    public void turn() {
        for (int i = 0; i < turnCount; i++)
            super.turn();

        turnCount++;
    }
}