public class Complex {
    double r;
    double q;

    public Complex(double r, double q) {
        this.r = r;
        this.q = q;
    }

    public double abs() {
        return Math.sqrt((this.r * this.r) + (this.q * this.q));
    }

    public void add(Complex c) {
        this.r += c.r;
        this.q += c.q;
    }

    public void sub(Complex c) {
        this.r -= c.r;
        this.q -= c.q;
    }

    public void mul(Complex c) {
        this.r = this.r * c.r - this.q * c.q;
        this.q = this.r * c.q + this.q * c.r;
    }

    publicx void print() {
        System.out.println(this.r + " + " + this.q + "i");
    }
}