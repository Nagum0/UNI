package walking.game;

import java.util.*;
import walking.game.util.*;

public class WalkingBoard {
    private int[][] tiles;
    private int x;
    private int y;
    public static final int BASE_TILE_SCORE = 3;

    public WalkingBoard(int size) {
        this.tiles = new int[size][size];

        for (int[] i : this.tiles) {
            Arrays.fill(i, this.BASE_TILE_SCORE);
        }
    }

    public WalkingBoard(int[][] tiles) {
        this.tiles = new int[tiles.length][];

        for (int i = 0; i < tiles.length; i++) {
            this.tiles[i] = Arrays.copyOf(tiles[i], tiles[i].length);
        }
    }

    public int[] getPosition() {
        return new int[]{this.x, this.y};
    }

    public boolean isValidPosition(int x, int y) {
        return (0 <= y && y < this.tiles.length) &&
               (0 <= x && x < this.tiles[y].length);
    }

    public int getTile(int x, int y) {
        if (!isValidPosition(x, y)) {
            throw new IllegalArgumentException("Invalid position!");
        }

        return this.tiles[y][x];
    }

    public int[][] getTiles() {
        int[][] copyOfTiles = new int[this.tiles.length][];

        for (int i = 0; i < this.tiles.length; i++) {
            copyOfTiles[i] = Arrays.copyOf(this.tiles[i], this.tiles[i].length);
        }

        return copyOfTiles;
    }

    public static int getXStep(Direction direction) {
        switch (direction) {
            case RIGHT:
                return 1;
            case LEFT:
                return -1;
            default:
                return 0;
        }
    }

    public static int getYStep(Direction direction) {
        switch (direction) {
            case UP:
                return -1;
            case DOWN:
                return 1;
            default:
                return 0;
        }
    }

    public int moveAndSet(Direction dir, int value) {
        int result = 0;
        int newXCor = this.x + getXStep(dir);
        int newYCor = this.y + getYStep(dir);

        if (isValidPosition(newXCor, newYCor)) {
            this.x = newXCor;
            this.y = newYCor;
            result = this.getTile(this.x, this.y);
            this.tiles[this.y][this.x] = value;
        }

        return result;
    }
}