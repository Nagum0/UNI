namespace Hashing;

public class HashDirect<T> {
    private int m;
    private Record<T>[] t;

    public HashDirect(int m) {
        this.m = m;
        t = new Record<T>[m];
    }

    public bool Insert(Record<T> rec) {
        int index = HashFunction(rec.key);

        if (t[index] != null)
            return false;

        t[index] = rec;

        return true;
    }

    public override string ToString() {
        return string.Join("\n", t
            .Where(e => e != null)
            .Select(e => e.ToString())
        );
    }

    private int HashFunction(int key) {
        return key % m;
    }
}
