package walking.game.player;

public class MadlyRotatingBuccaneer extends Player {
    private int turnCount;

    @Override
    public void turn() {
        if (turnCount == 0) {
            /* System.out.println("Madman: NO TURN"); */
            turnCount++;
            return;
        }

        for (int i = 0; i < turnCount; i++)
            super.turn();

        /* System.out.println("Madman: " + turnCount + ", " + direction); */
        turnCount++;
    }
}