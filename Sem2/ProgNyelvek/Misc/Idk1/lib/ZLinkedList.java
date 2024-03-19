package lib;

import lib.Node;

public class ZLinkedList {
    private Node head;

    public ZLinkedList(int key) {
        this.head = new Node();
        this.head.key = key;
        this.head.next = null;
    }

    public void insertNode(int key) {
        Node q = new Node();
        q.key = key;
        q.next = null;

        Node p = this.head;
        Node pe = null;

        while (p != null) {
            pe = p;
            p = p.next;
        }

        p.next = q;
    }
}
