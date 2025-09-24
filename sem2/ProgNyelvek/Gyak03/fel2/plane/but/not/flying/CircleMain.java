package plane.but.not.flying;

import plane.*;

public class CircleMain {
    public static void main(String[] args) {
        PublicCircle pc = new PublicCircle();
        System.out.println(pc.getArea());
        pc.x = 5;
        pc.y = 2;
        pc.radius = 10;
        System.out.println(pc.getArea());

        Circle c1 = new Circle(4, 5, 9);
        System.out.println(c1.getX());
    }
}