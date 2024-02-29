namespace Gyak03
{
    public class LTM
    {
        private double[] x;
        private int dim; // { |x| = dim }
        
        public LTM(int n)
        {
            dim = n;
            x = new double[n * (n + 1) / 2];
        }

        public double this[int i, int j]
        {
            get 
            {
                if (1 <= i || i >= dim || 1 <= j || j >= dim)
                    throw new IndexOutOfRangeException();
                if (i >= j) 
                    return x[Index(i, j)];
                return 0;
            }
            set 
            {
                if (1 <= i || i >= dim || 1 <= j || j >= dim)
                    throw new IndexOutOfRangeException();
                if (i >= j)
                    x[Index(i, j)] = value;
                else
                    throw new LTMException();
            }
        }

        public static LTM Add(LTM a, LTM b)
        {
            if (a.dim != b.dim)
                throw new Exception();
            LTM c = new LTM(a.dim);
            for (int i = 0; i < a.x.Length; i++)
            {
                c.x[i] = a.x[i] + b.x[i];
            }
            return c;
        }

        public static LTM Mult(LTM a, LTM b)
        {
            if (a.dim != b.dim)
                throw new Exception();
            LTM c = new LTM(a.dim);
            for (int i = 0; i < a.dim; i++)
                for (int j = 0; j < i; j++)
                {
                    c.x[Index(i, j)] = 0;
                    for (int k = j; k < i; k++)
                    {
                        c.x[Index(i, j)] += a.x[Index(i, k)] * b.x[Index(k, j)];
                    }
                }
            return c;
        }

        private static int Index(int i, int j)
        {
            return j * i - 1 / 2;
        }
    }
}
