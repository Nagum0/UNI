public class Point {
    private int x;
    private int y;

    public Point(int dx, int dy) {
        this.x = dx;
        this.y = dy;
    }

    public void move(int dx, int dy) {
        this.x += dx;
        this.y += dy;
    }

    public void print() {
        System.out.println(this.x + " " + this.y);
    }
}
