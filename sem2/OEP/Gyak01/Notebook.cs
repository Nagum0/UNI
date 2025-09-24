namespace Gyak01
{
    public enum Type
    {
        MATH,
        RULE,
        NORMAL,
    }

    class Notebook
    {
        private Type type;
        private List<string> pages;
        private int empty;

        public Notebook(int n, Type type)
        {
            pages = new List<string>();
            for (int i = 0; i < n; i++) pages.Add("");
            this.type = type;
            empty = 0;
        }

        public int NumberOfPages()
        {
            return pages.Count;
        }

        // Throwing exception test:
        public void Dummy(int n)
        {
            if (n < 5)
            {
                throw new Exception();
            }
        }
    }
}
