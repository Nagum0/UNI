package util;

import java.util.LinkedList;
import java.util.Queue;

public class Node<T> {
    public T key;
    public Node<T> left;
    public Node<T> right;

    public Node() {
        left = null;
        right = null;
    }

    public Node(T key) {
        this();
        this.key = key;
    }

    public void preOrder() {
        if (this != null) {
            Process();

            if (left != null)
                left.preOrder();
            if (right != null)
                right.preOrder();
        }
    }

    public void inOrder() {
        if (this != null) {
            if (left != null)
                left.inOrder();

            Process();

            if (right != null)
                right.inOrder();
        }
    }

    public void postOrder() {
        if (this != null) {
            if (left != null)
                left.postOrder();
            if (right != null)
                right.postOrder();
            
            Process();
        }
    }

    public void Process() {
        System.out.print(key + " ");
    }

    public int height() {
        int x = 0;
        int y = 0;

        if (left != null)
            x = left.height();
        if (right != null)
            y = right.height();

        return 1 + Integer.max(x, y);
    }

    public int leafCount() {
        if (left == null && right == null)
            return 1;
        
        int x = 0;
        int y = 0;

        if (left != null)
            x = left.leafCount();
        if (right != null)
            y = right.leafCount();

        return x + y;
    }

    public void queTraversal() {
        Queue<Node> q = new LinkedList<>();
        q.add(this);

        while (!q.isEmpty()) {
            Node rem = q.remove();
            rem.Process();

            if (rem.left != null)
                q.add(rem.left);
            if (rem.right != null)
                q.add(rem.right);
        }
    }
    
    public int leafCountQue() {
        int leaves = 0;

        Queue<Node> q = new LinkedList<>();
        q.add(this);

        while (!q.isEmpty()) {
            Node rem = q.remove();

            if (rem.left == null && rem.right == null)
                leaves++;
            
            if (rem.left != null)
                q.add(rem.left);
            if (rem.right != null)
                q.add(rem.right);
        }

        return leaves;
    }

    public void Print() {
        System.out.println(this.toString());
    }

    @Override
    public String toString() {
        if (left == null && right == null)
            return "\t" + key + "\nnull\t\tnull";
        else if (left == null)
            return "\t" + key + "\nnull" + "\t\t" + right.key;
        else if (right == null)
            return "\t" + key + "\n" + left.key + "\t\tnull";

        return "\t" + key + "\n" + left.key + "\t\t" + right.key;
    }
}
