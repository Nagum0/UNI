namespace HF10;

public class L : Size {
    private static L? instance = null;

    public static L Instance() {
        if (instance == null)
            instance = new L();

        return instance;
    }

    public int Multi() {
        return 3;
    }
}