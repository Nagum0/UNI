namespace BFS
{
    enum Color
    {
        WHITE,
        GREY,
        BLACK
    }

    class Edge<T>
    {
        public T u;
        public T v;

        public Edge(T u, T v)
        {
            this.u = u;
            this.v = v;
        }
    }

    class Graph<T> where T: IEquatable<T>
    {
        public List<T> V;
        public List<Edge<T>> E;
        
        public Graph(List<T> v, List<Edge<T>> e)
        {
            V = v;
            E = e;
        }

        public List<T> A(T u)
        {
            List<T> vs = new List<T>();
            
            foreach (Edge<T> e in E)
            {
                // NOTE (for self):
                // If T implements IEquatable then it uses the basic equality implementation
                // else if uses hashcodes for the objects.
                if (EqualityComparer<T>.Default.Equals(u, e.u))
                    vs.Add(e.v);
            }

            return vs;
        }
    }

    internal class Program
    {
        // NOTE (for self):
        // The method needs the `where T: IEquatable` clause beacuse Graph uses EqualityComparer<T>.Default.
        static void BFS<T>(Graph<T> G, T s) where T: IEquatable<T>
        {
            Dictionary<T, int> ds = new Dictionary<T, int>(); // Distances
            Dictionary<T, T> ps = new Dictionary<T, T>(); // Parents
            Dictionary<T, Color> colors = new Dictionary<T, Color>();
                
            foreach (T u in G.V)
            {
                // In the notes we use infinity but I have no idea how to represent that here so I used -1.
                ds.Add(u, -1);
                // The edges that aren't reached by BFS will have themselves as their parent.
                ps.Add(u, u);
                colors.Add(u, Color.WHITE);
            }

            ds[s] = 0;
            colors[s] = Color.GREY;

            Queue<T> Q = new Queue<T>();
            Q.Enqueue(s);

            while (Q.Count > 0)
            {
                T u = Q.Dequeue();

                foreach (T v in G.A(u))
                {
                    if (ds[v] == -1)
                    {
                        ds[v] = ds[u] + 1;
                        ps[v] = u;
                        colors[v] = Color.GREY;
                        Q.Enqueue(v);
                    }
                }

                colors[u] = Color.BLACK;
            }

            Console.WriteLine($"Distances: {string.Join(", ", ds)}");
            Console.WriteLine($"Parents: {string.Join(", ", ps)}");
            Console.WriteLine($"Colors: {string.Join(", ", colors)}");
        }

        static void Main(string[] args)
        {
            // Ez a példa a gyakorlatos honlapról: https://people.inf.elte.hu/pgm6rw/algo/Algo2/ElementaryGraphAlgorithms/bfs/index.html
            List<char> vs = ['a', 'b', 'c', 'd', 'e', 'f'];
            List<Edge<char>> es = [
                new Edge<char>('a', 'b'),
                new Edge<char>('b', 'c'),
                new Edge<char>('b', 'e'),
                new Edge<char>('c', 'e'),
                new Edge<char>('c', 'e'),
                new Edge<char>('e', 'd'),
                new Edge<char>('d', 'a'),
                new Edge<char>('f', 'e'),
                new Edge<char>('f', 'c'),
            ];
            Graph<char> g = new Graph<char>(vs, es);
            BFS(g, 'a');
        }
    }
}
