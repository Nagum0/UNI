package Fel1.point2d;

public class Point {
    double x;
    double y;

    public Point(double x, double y) {
        if (x < 0.0) {
            throw new IllegalArgumentException("SZAR VAGY XD");
        }

        this.x = x;
        this.y = y;
    }

    public void move(double dx, double dy) {
        this.x += dx;
        this.y += dy;
    }
    
    public void mirror(double cx, double cy) {
        double dx = cx - this.x;
        double dy = cy - this.y;
        this.move(2 * dx, 2 * dy);
    }

    public double distance(Point p) {
        double dx = (p.x - this.x) * (p.x - this.x);
        double dy = (p.y - this.y) * (p.y - this.y);
        return Math.sqrt(dx + dy);
    }

    public void print() {
        System.out.println("[" + this.x + ";" + this.y + "]");
    }
}