namespace BFS;

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
