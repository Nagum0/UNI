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
        static int time;

        static void DFS<T>(Graph<T> G) where T: IEquatable<T>
        {
            Dictionary<T, int> ds = new Dictionary<T, int>(); // Access times
            Dictionary<T, int> fs = new Dictionary<T, int>(); // Final times
            Dictionary<T, T> ps = new Dictionary<T, T>(); // Parents
            Dictionary<T, Color> cs = new Dictionary<T, Color>(); // Colors

            foreach (T u in G.V)
            {
                cs[u] = Color.WHITE;
            }

            time = 0;

            foreach (T r in G.V)
            {
                if (cs[r] == Color.WHITE)
                {
                    // If the vertex has no parent the parent is set to itself.
                    ps[r] = r;
                    DFvisit(G, r, ref ds, ref fs, ref ps, ref cs);
                }
            }

            Console.WriteLine($"Access times: {string.Join(", ", ds)}");
            Console.WriteLine($"Final times:  {string.Join(", ", fs)}");
            Console.WriteLine($"Parents: {string.Join(", ", ps)}");
            Console.WriteLine($"Colors: {string.Join(", ", cs)}");
        }

        /// I don't receive time as a paremeter because it's already defined as a static member inside the class.
        /// <typeparam name="T"></typeparam>
        /// <param name="G">The graph.</param>
        /// <param name="u">DFvisit start vertex.</param>
        /// <param name="ds">A reference to the acces times.</param>
        /// <param name="fs">A reference to the final times.</param>
        /// <param name="ps">A reference to the parents.</param>
        /// <param name="cs">A reference to the colors.</param>
        static void DFvisit<T>(
            Graph<T> G,
            T u,
            ref Dictionary<T, int> ds,
            ref Dictionary<T, int> fs,
            ref Dictionary<T, T> ps,
            ref Dictionary<T, Color> cs
        ) where T: IEquatable<T>
        {
            ds[u] = ++time;
            cs[u] = Color.GREY;

            foreach (T v in G.A(u))
            {
                if (cs[v] == Color.WHITE)
                {
                    ps[v] = u;
                    DFvisit(G, v, ref ds, ref fs, ref ps, ref cs);
                }
                else
                {
                    if (cs[v] == Color.GREY)
                    {
                        // backEdge(u, v)
                    }
                }
            }

            fs[u] = ++time;
            cs[u] = Color.BLACK;
        }

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
            //BFS(g, 'a');

            vs = ['a', 'b', 'c', 'd', 'e', 'f'];
            es = [
                new Edge<char>('a', 'b'),
                new Edge<char>('a', 'e'),
                new Edge<char>('b', 'c'),
                new Edge<char>('b', 'e'),
                new Edge<char>('e', 'c'),
                new Edge<char>('e', 'd'),
                new Edge<char>('d', 'a'),
                new Edge<char>('f', 'c'),
                new Edge<char>('f', 'e'),
            ];
            g = new Graph<char>(vs, es);
            DFS(g);
        }
    }
}
