class Main {
    static void Miez(Node l) {
        Node pe = l;
        Node p = l.next;

        while (p != null && p.key >= 0) {
            pe = p;
            p = p.next;
        }

        Node pu = pe;

        while (p != null) {
            if (p.key < 0) {
                pe = p;
                p = p.next;
            }
            else {
                pe.next = p.next;
                p.next = pu.next;
                pu.next = p;
                p = pe.next;
                pu = pu.next;
            }
        }
    }

    public static void main(String[] args) {
        Node l1 = new Node(
            9, new Node(
                4, new Node(
                    -1, new Node(
                        -3, null
                    )
                )
            )
        );

        Node l2 = new Node(
            -3, new Node(
                -1, new Node(
                    2, null
                )
            )
        );

        Node l3 = new Node(
            1, new Node(
                -2, new Node(
                    5, new Node(
                        6, new Node(
                            -3, new Node(
                                4, new Node(
                                    0, new Node(
                                        -5, null
                                    )
                                )
                            )
                        )
                    )
                )
            )
        );

        System.out.println(l1.toString());
        Miez(l1);
        System.out.println(l1.toString());

        System.out.println(l2.toString());
        Miez(l2);
        System.out.println(l2.toString());

        System.out.println(l3.toString());
        Miez(l3);
        System.out.println(l3.toString());
    }
}