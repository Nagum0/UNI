package walking.game.player;

import walking.game.util.*;

public class Player {
    private int score;
    protected Direction direction = Direction.UP;
    
    public void addToScore(int score) {
        this.score += score;
    }

    public void turn() {
        try {
            direction = direction.values()[direction.ordinal() + 1];
        }
        catch (java.lang.ArrayIndexOutOfBoundsException e) {
            direction = direction.values()[0];
        }
    }

    public int getScore() {
        return score;
    }

    public Direction getDirection() {
        return direction;
    }
}