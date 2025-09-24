public class Node {
    public int key;
    public Node next;

    public Node(int key, Node next) {
        this.key = key;
        this.next = next;
    }

    @Override
    public String toString() {
        StringBuilder sbr = new StringBuilder();
        
        Node p = this;

        while (p != null) {
            sbr.append(p.key + ",");
            p = p.next;
        }
        sbr.append("null");

        return sbr.toString();
    }
}