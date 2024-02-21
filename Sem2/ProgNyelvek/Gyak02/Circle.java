public class Circle {
    double x;
    double y;
    double radius;

    public Circle(double x, double y, double radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    public void enlarge(double f) {
        this.radius *= f;
    }

    public double getArea() {
        return Math.PI * this.radius * this.radius;
    }
}