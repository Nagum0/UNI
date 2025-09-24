package data.organiser;

import java.util.*;

public class Organiser<T> {
    private ArrayList<T> elems;
    private ArrayList<T> swaps;

    @SafeVarargs
    public Organiser(T... elems) {
        this.elems = new ArrayList<T>();
        this.swaps = new ArrayList<T>();

        for (T elem : elems)
            this.elems.add(elem);
    }

    public ArrayList<T> get() {
        ArrayList<T> result = new ArrayList<T>();
        
        for (T elem : elems)
            result.add(elem);

        return result;
    }

    public T get(int index) {
        return elems.get(index);
    }

    public void addSwap(int x, int y) {
        
    }
}