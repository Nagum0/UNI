namespace HF6 {
    public struct Receipt {
        public string name;
        public List<Item> items;
        
        public void AddItem(Item e) {
            items.Add(e);
        }

        public uint Sum() {
            uint sum = 0;

            foreach (Item e in items)
                sum += e.price;

            return sum;
        }
    }
}
