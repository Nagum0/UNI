namespace Dijkstra;

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

internal class Program
{
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

        Console.WriteLine($"Costs: {string.Join(", ", ds)}");
        Console.WriteLine($"Parents: {string.Join(", ", ps)}");
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
