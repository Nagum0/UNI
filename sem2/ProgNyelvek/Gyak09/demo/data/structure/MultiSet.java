package data.structure;

import java.util.*;

public class MultiSet<E> {
    private HashMap<E, Integer> elemToCount;

    public MultiSet(E[] array) {
        elemToCount = new HashMap<>();

        for (E elem : array) {
            if (elemToCount.containsKey(elem)) {
                elemToCount.replace(elem, elemToCount.get(elem) + 1);
            }
            elemToCount.put(elem, 1);
        }
    }

    /* SAJAT OVERLOAD A FELADAT MIATT */
    private MultiSet() {
        elemToCount = new HashMap<>();
    }

    /* SAJAT GETTER A FELADAT MIATT */
    public boolean containsElem(E elem) {
        return elemToCount.containsKey(elem);
    }

    public int add(E elem) {
        if (elemToCount.containsKey(elem)) {
            elemToCount.replace(elem, elemToCount.get(elem) + 1);
            return elemToCount.get(elem);
        }

        elemToCount.put(elem, 1);
        return 1;
    }

    public int getCount(E elem) {
        if (elemToCount.containsKey(elem))
            return elemToCount.get(elem);
        return 0;
    }

    public MultiSet<E> intersect(MultiSet<E> ms) {
        MultiSet<E> resultMs = new MultiSet<E>();

        for (Map.Entry<E, Integer> entry : ms.elemToCount.entrySet()) {
            E elem = entry.getKey();

            if (this.elemToCount.containsKey(elem)) {
                if (this.elemToCount.get(elem) > entry.getValue())
                    resultMs.elemToCount.put(elem, entry.getValue());    
                else
                    resultMs.elemToCount.put(elem, this.elemToCount.get(elem));
            }
        }

        return resultMs;
    }

    public int size() {
        return elemToCount.size();
    }
}