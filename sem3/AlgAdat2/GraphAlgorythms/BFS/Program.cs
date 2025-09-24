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
        
        static void Dijkstra<T>(GraphW<T> G, T s) where T: IEquatable<T>
        {
            Dictionary<T, int> ds = new Dictionary<T, int>(); // Costs
            Dictionary<T, T> ps = new Dictionary<T, T>(); // Parents (if the vertex is unreachable the parent is itself)

            foreach (T v in G.V)
            {
                ds[v] = int.MaxValue;
                ps[v] = v;
            }

            ds[s] = 0;

            PriorityQueue<T, int> Q = new PriorityQueue<T, int>();
            Q.EnqueueRange(G.V
                .Aggregate(new List<(T, int)>(), (acc, i) => {
                        if (!i.Equals(s))
                            acc.Add((i, int.MaxValue));
                        return acc;
                })
            );
            
            T u = s;

            while (ds[u] < int.MaxValue && Q.Count > 0)
            {
                foreach (T v in G.A(u))
                {
                    int addedVWeight = ds[u] + G.W(u, v);

                    if (ds[v] > addedVWeight)
                    {
                        ps[v] = u;
                        ds[v] = addedVWeight;
                        Adjust(ref Q, v, addedVWeight);
                    }
                }

                u = Q.Dequeue();
            }

            Console.WriteLine(string.Join(", ", ds));
            Console.WriteLine(string.Join(", ", ps));
        }
        
        /// <summary>
        /// C#'s PriorityQueue doesn't have an adjust priority method so this is my implementation.
        /// </summary>
        /// <param name="q">A reference to the queue that we have to adjust.</param>
        /// <param name="v">The element that needs to be adjusted.</param>
        /// <param name="newPriority">The new priority of the given element.</param>
        static void Adjust<T, V>(ref PriorityQueue<T, V> q, T v, V newPriority) where T: IEquatable<T>
        {
            List<(T, V)> filteredItems = q.UnorderedItems
                .Where(item => !item.Item1.Equals(v))
                .ToList();

            q.Clear();
            q.EnqueueRange(filteredItems);
            q.Enqueue(v, newPriority);
        }

        static void Main(string[] args)
        {
            List<char> vs = ['a', 'b', 'c', 'd', 'e', 'f'];
            List<EdgeW<char>> es = [
                new EdgeW<char>('a', 'b', 5),
                new EdgeW<char>('a', 'd', 4),
                new EdgeW<char>('a', 'e', 2),
                new EdgeW<char>('b', 'd', 1),
                new EdgeW<char>('b', 'e', 2),
                new EdgeW<char>('b', 'c', 1),
                new EdgeW<char>('c', 'e', 1),
                new EdgeW<char>('e', 'd', 2),
                new EdgeW<char>('e', 'f', 1),
                new EdgeW<char>('f', 'c', 3)
            ];
            GraphW<char> g = new GraphW<char>(vs, es);
            Dijkstra(g, 'a');
        }
    }
}
