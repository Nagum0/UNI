public class Main {
    public static void main(String[] args) {
        // POINT:
        /* Point p1 = new Point(6.9, 4.2);
        p1.print();

        Point[] ps = {
            new Point(1.5, 78.5),
            new Point(4.8, 7.8)
        };

        for (Point p : ps) {
            p.print();
        }

        ps[0].move(4, 2);
        ps[0].print();

        System.out.println(p1.distance(ps[1]));
        p1.print(); */

        // COMPLEX:
        /* Complex c1 = new Complex(3, 2);
        c1.print();
        System.out.println(c1.abs());
        Complex c2 = new Complex(1, 2);
        c1.mul(c2);
        c1.print(); */

        // CIRCLE:
        Circle cir1 = new Circle(2, 3, 2);
        System.out.println(cir1.getArea());
        cir1.enlarge(2);
        System.out.println(cir1.radius);
    }
}