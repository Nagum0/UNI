package plane;

public class PublicCircle {
    public double x;
    public double y;
    public double radius;

    public PublicCircle() {
        this.x = 0.0;
        this.y = 0.0;
        this.radius = 0.0;
    }

    public double getArea() {
        return Math.PI * this.radius * this.radius;
    }
}