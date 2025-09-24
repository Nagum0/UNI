namespace HF1
{
    public class Rational
    {
        private int n;
        private int d;

        public Rational(int n, int d)
        {
            if (d == 0) throw new Exception();
            this.n = n;
            this.d = d;
        }

        public static Rational Add(Rational a, Rational b)
        {
            return new Rational(a.n * b.d + a.d * b.n, a.d * b.d);
        }

        public static Rational Substract(Rational a, Rational b)
        {
            return new Rational(a.n * b.d - a.d * b.n, a.d * b.d);
        }

        public static Rational Multiply(Rational a, Rational b)
        {
            return new Rational(a.n * b.n, a.d * b.d);
        }

        public static Rational Divide(Rational a, Rational b)
        {
            if (b.n == 0) throw new Exception();
            return new Rational(a.n * b.d, a.d * b.n);
        }

        public static Rational operator +(Rational a, Rational b) => Add(a, b);
        public static Rational operator -(Rational a, Rational b) => Substract(a, b);
        public static Rational operator *(Rational a, Rational b) => Multiply(a, b);
        public static Rational operator /(Rational a, Rational b) => Divide(a, b);

        public override string ToString()
        {
            return $"{n}/{d}";  
        }
    }
}
