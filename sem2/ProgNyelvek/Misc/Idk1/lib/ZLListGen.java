package lib;

public class ZLListGen<T> {
    private NodeGen<T> head;

    public ZLListGen(T key) {
        this.head = new NodeGen<T>();
        this.head.key = key;
        this.head.next = null;
    }

    public void printList() {
        NodeGen<T> p = this.head;

        while (p != null) {
            System.out.print(p.key + " -> ");
            p = p.next;
        }

        System.out.println("NULL");
    }
}
