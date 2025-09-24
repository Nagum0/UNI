package util;

public class Node3<T> {
    public T key;
    public Node3<T> parent;
    public Node3<T> left;
    public Node3<T> right;

    public Node3(Node3<T> parent) {
        left = right = null;
        this.parent = parent;
    }

    public Node3(T key, Node3<T> parent) {
        this(parent);
        this.key = key;
    }

    public void Process() {
        System.out.println(this.toString());
    }

    @Override
    public String toString() {
        return "\t" + key + "\n" + left.key + "\t\t" + right.key;
    }
}
