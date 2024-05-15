namespace Hashing;

public class Record<T> {
    public int key;
    public T data;

    public Record(int key, T data) {
        this.key = key;
        this.data = data;
    }

    public override string ToString() {
        return $"{key}: {data}";
    }
}
