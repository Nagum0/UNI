package lib;

import lib.Node;

public class ZLinkedList {
    private Node head;

    public ZLinkedList(int key) {
        this.head = new Node();
        this.head.key = key;
        this.head.next = null;
    }

    public ZLinkedList() {
        this.head = null;
    }

    public void insertNode(int key) {
        Node q = new Node();
        q.key = key;
        q.next = null;
        
        if (this.head == null) {
            this.head = q;
            return;
        }

        Node p = this.head;

        while (p.next != null) {
            p = p.next;
        }

        p.next = q;
    }
    
    public boolean deleteNode(int key) {
        Node p = this.head;
        Node pe = null;

        while (p != null) {
            if (p.key == key) {
                pe.next = p.next;
                return true;
            }
            
            pe = p;
            p = p.next;
        }

        return false;
    }

    public void printList() {
        Node p = this.head;

        while (p != null) {
            System.out.print(p.key + " -> ");
            p = p.next;
        }

        System.out.println("NULL");
    }

    public boolean checkItem(int x) {
        Node p = this.head;

        while (p != null) {
            if (p.key == x) {
                return true;
            }

            p = p.next;
        }

        return false;
    }
}
