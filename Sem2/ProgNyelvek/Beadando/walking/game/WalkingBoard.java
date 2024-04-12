package walking.game;

import java.util.*;

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
        return y < this.tiles.length && x < this.tiles[y].length;
    }

    public int getTile(int x, int y) {
        return 0;
    }
}