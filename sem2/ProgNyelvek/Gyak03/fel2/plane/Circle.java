package plane;

public class Circle {
    private double x;
    private double y;
    private double radius;

    public Circle(double x, double y, double radius) {
        if (radius <= 0) {
            throw new IllegalArgumentException("SZAR VAGY");
        }

        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    public double getArea() {
        return Math.PI * this.radius * this.radius;
    }

    public double getX() {
        return this.x;
    }

    public double getY() {
        return this.y;
    }

    public double getRadius() {
        return this.radius;
    }
}