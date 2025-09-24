namespace Gyak04
{
    public struct Item
    {
        public int k;
        public string v;

        public Item(int k, string v) 
        { 
            this.k = k; 
            this.v = v;
        }
    }

    public class Map
    {
        private List<Item> seq = new List<Item>();

        private (bool, int) LogSearch(int key)
        {
            bool l = false;
            int ah = 1;
            int fh = seq.Count;
            int ind = 0;

            while (!l && ah <= fh)
            {
                ind = (ah + fh) / 2;
                if (seq[ind - 1].k > key)
                    fh = ind - 1;
                else if (seq[ind - 1].k == key)
                    l = true;
                else if (seq[ind - 1].k < key)
                    ah = ind + 1;
            }

            if (!l)
                ind = ah;

            return (l, ind - 1);
        }

        public void SetEmpty()
        {
            seq = new List<Item>();
        }

        public int Count()
        {
            return seq.Count;
        }

        public void Insert(Item e)
        {
            (bool l, int ind) = LogSearch(e.k);
            if (l) throw new Exception();
            seq.Insert(ind, e);
        }

        public void Remove(int key)
        {
            (bool l, int ind) = LogSearch(key);
            if (!l) throw new Exception();
            seq.RemoveAt(ind);
        }

        public bool In(int key)
        {
            (bool l, int ind) = LogSearch(key);
            return l;
        }

        public string this[int key]
        {
            get
            {
                (bool l, int ind) = LogSearch(key);
                if (!l) throw new Exception();
                return seq[ind].v;
            }
        }
    }
}
