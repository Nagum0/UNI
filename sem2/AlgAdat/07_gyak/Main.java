import util.*;

public class Main {
    public static void main(String[] args) {
        Node<Integer> root = new Node<>(69);
        root.left = new Node<Integer>(420);
        root.right = new Node<Integer>(87);

        root.left.left = new Node<Integer>(45);
        root.left.right = new Node<Integer>(90);

        root.right.right = new Node<Integer>(100);
        root.right.left = new Node<Integer>(3453);

        /* root.left.left.left = new Node<Integer>(42); */

        root.preOrder();
        System.out.println();
        root.inOrder();
        System.out.println();
        root.postOrder();
        System.out.println();

        System.out.println(root.height());
        System.out.println(root.leafCount());
        
        root.queTraversal();
        System.out.println();
        System.out.println(root.leafCountQue());
    }
}
