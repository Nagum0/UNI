package action.user;

import action.Scalable;
import action.Undoable;
import java.util.Arrays;

public class MultiDimensionalPoint implements Scalable, Comparable<MultiDimensionalPoint>, Undoable {
    private int[] coordinates;
    private int[] lastCoordinates;

    public MultiDimensionalPoint(int... nums) {
        this.coordinates = Arrays.copyOf(nums, nums.length);
    }

    @Override
    public void scale(int factor) {
        for (int i = 0; i < coordinates.length; i++) {
            coordinates[i] *= factor;
        }
    }

    public int get(int index) {
        if (index < 0 || coordinates.length >= index)
            throw new IllegalArgumentException("Index out of bounds...");

        return coordinates[index];
    }

    public void set(int index, int value) {
        if (index < 0 || coordinates.length >= index)
            throw new IllegalArgumentException("Index out of bounds...");

        coordinates[index] = value;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof MultiDimensionalPoint) {
            MultiDimensionalPoint that = (MultiDimensionalPoint) obj;
            return Arrays.equals(this.coordinates, that.coordinates);
        }

        return false;
    }

    @Override
    public int hashCode() {
        return 1;
    }

    @Override
    public int compareTo(MultiDimensionalPoint o) {
        if (this.equals(o))
            return 0;

        int len = Math.min(this.coordinates.length, o.coordinates.length);

        for (int i = 0; i < len; i++) {
            if (this.coordinates[i] != o.coordinates[i]) {
                return this.coordinates[i] - o.coordinates[i];
            }
        }

        return this.coordinates.length - o.coordinates.length;
    }

    private void saveToLast() {
        lastCoordinates = Arrays.copyOf(coordinates, coordinates.length);
    }

    @Override
    public void undoLast() {
        int[] placeHolder = Arrays.copyOf(coordinates, coordinates.length); 
        coordinates = Arrays.copyOf(lastCoordinates, lastCoordinates.length);
        lastCoordinates = Arrays.copyOf(placeHolder, placeHolder.length);
    }
}