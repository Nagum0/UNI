namespace Prim;

public class GraphW<T> where T: IEquatable<T>
{
    public List<T> V;
    public List<EdgeW<T>> E;

    public GraphW(List<T> v, List<EdgeW<T>> e)
    {
        V = v;
        E = e;
    }

    public List<T> A(T u)
    {
        List<T> vs = new List<T>();

        foreach (EdgeW<T> e in E)
        {
            if (EqualityComparer<T>.Default.Equals(u, e.u))
                vs.Add(e.v);
        }

        return vs;
    }

    public int W(T u, T v)
    {
        EdgeW<T>? edge = E.Find(e => e.u.Equals(u) && e.v.Equals(v));

        if (edge != null)
            return edge.weight;

        throw new Exception("Edge not found.");
    }
}

public class EdgeW<T>
{
    public T u;
    public T v;
    public int weight;

    public EdgeW(T u, T v, int weight)
    {
        this.u = u;
        this.v = v;
        this.weight = weight;
    }
}


public class Program
{
    static void Prim<T>(GraphW<T> G, T r) where T: IEquatable<T>
    {
        Dictionary<T, int> cs = new Dictionary<T, int>();
        Dictionary<T, T> ps = new Dictionary<T, T>();

        foreach (T v in G.V)
        {
            cs.Add(v, int.MaxValue);
            ps.Add(v, v);
        }

        cs[r] = 0;
        PriorityQueue<T, int> Q = new PriorityQueue<T, int>();
        Q.EnqueueRange(G.V
            .Aggregate(new List<(T, int)>(), (acc, i) => {
                if (!i.Equals(r))
                    acc.Add((i, int.MaxValue));
                return acc;
            })
        );
        T u = r;

        while (Q.Count != 0)
        {
            foreach (T v in G.A(u))
            {
                int edgeWeight = G.W(u, v);

                if (Contains(Q, v) && cs[v] > edgeWeight)
                {
                    ps[v] = u;
                    cs[v] = edgeWeight;
                    Adjust(ref Q, v, edgeWeight);
                }
            }

            u = Q.Dequeue();
        }

        Console.WriteLine($"CS: {string.Join(", ", cs)}");
        Console.WriteLine($"PS: {string.Join(", ", ps)}");
    }
    
    /// <summary>
    /// Check whether a PriorityQueue<T, int> contains a value of type T.
    /// </summary>
    static bool Contains<T>(PriorityQueue<T, int> q, T v) where T: IEquatable<T>
    {
        return q.UnorderedItems.Any(item => item.Item1 != null ? item.Item1.Equals(v) : false);
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
            new EdgeW<char>('a', 'b', 2),
            new EdgeW<char>('a', 'd', 4),
            new EdgeW<char>('b', 'a', 2),
            new EdgeW<char>('b', 'c', 4),
            new EdgeW<char>('b', 'd', 5),
            new EdgeW<char>('b', 'e', 3),
            new EdgeW<char>('c', 'b', 4),
            new EdgeW<char>('c', 'e', 1),
            new EdgeW<char>('c', 'f', 5),
            new EdgeW<char>('d', 'a', 4),
            new EdgeW<char>('d', 'b', 5),
            new EdgeW<char>('d', 'e', 1),
            new EdgeW<char>('e', 'b', 3),
            new EdgeW<char>('e', 'd', 1),
            new EdgeW<char>('e', 'c', 1),
            new EdgeW<char>('e', 'f', 2),
            new EdgeW<char>('f', 'c', 5),
            new EdgeW<char>('f', 'e', 2),
        ];
        GraphW<char> g = new GraphW<char>(vs, es);
        Prim(g, 'a');
    }
}
