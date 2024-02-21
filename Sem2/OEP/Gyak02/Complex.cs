namespace Gyak02
{
    public class Complex
    {
        private double x;
        private double y;

        public Complex(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        public static Complex Add(Complex a, Complex b)
        {
            return new Complex(a.x + b.x, a.y + b.y);
        }

        public static Complex Sub(Complex a, Complex b)
        {
            return new Complex(a.x - b.x, a.y - b.y);
        }

        public static Complex Mult(Complex a, Complex b)
        {
            return new Complex(
                (a.x * b.x - a.y * b.y),
                (a.x * b.y + a.y * b.x)
            );
        }

        public static Complex Div(Complex a, Complex b)
        {
            if (b.x == 0 && b.y == 0)
            {
                throw new Exception();
            }
            return new Complex(
                ((a.x * b.x) + (a.y * b.y)) / (b.x * b.x + b.y * b.y),
                ((a.y * b.y) - (a.x * b.y)) / (b.x * b.x + b.y * b.y)
            );
        }

        // Operator overloading:
        public static Complex operator +(Complex a, Complex b) => Add(a, b);
        public static Complex operator -(Complex a, Complex b) => Sub(a, b);
        public static Complex operator *(Complex a, Complex b) => Mult(a, b);
        public static Complex operator /(Complex a, Complex b) => Div(a, b);
        public static Complex operator -(Complex a)            => new Complex(-a.x, -a.y);
        
        // Overriding the ToString fucntion:
        public override string ToString()
        {
            if (y < 0)
            {
                return $"{Math.Round(x)} - {Math.Abs(Math.Round(y))}i";
            }
            return $"{Math.Round(x)} + {Math.Round(y)}i";
        }
    }
}
