namespace HF3
{
    public class Diag
    {
        private double[] x;

        public Diag(int n)
        {
            x = new double[n];
        }

        public double Get(int i, int j)
        {
            if (!((0 <= i && i < x.Length) && (0 <= j && j < x.Length)))
                throw new Exception();

            if (i == j)
                return x[i];
            else
                return 0.0;
        }

        public void Set(int i, int j, double e)
        {
            if (!((0 <= i && i < x.Length) && (0 <= j && j < x.Length)))
                throw new Exception();
            if (j == i)
                x[i] = e;
            else
                throw new Exception();
        }

        public static Diag Add(Diag a, Diag b)
        {
            if (a.x.Length != b.x.Length)
                throw new Exception();

            Diag c = new Diag(a.x.Length);
            for (int i = 0; i < c.x.Length; i++)
                c.x[i] = a.x[i] + b.x[i];

            return c;
        }

        public static Diag Multiply(Diag a, Diag b)
        {
            if (a.x.Length != b.x.Length)
                throw new Exception();

            Diag c = new Diag(a.x.Length);
            for (int i = 0; i < c.x.Length; i++)
                c.x[i] = a.x[i] * b.x[i];

            return c;
        }

        public static Diag operator +(Diag a, Diag b) => Add(a, b);
        public static Diag operator *(Diag a, Diag b) => Multiply(a, b);
    }
}
