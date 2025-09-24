using System.Collections;

namespace HF6 {
    public class Receipts : IEnumerable {
        private string path;

        public Receipts(string path) {
            this.path = path;
        }

        IEnumerator IEnumerable.GetEnumerator() {
            return (IEnumerator) GetEnumerator();
        }

        public StoreEnum GetEnumerator() {
            return new StoreEnum(path);
        }
    }

    public class StoreEnum : IEnumerator {
        private string path;
        private StreamReader inFile;
        private Receipt currentReceipt;

        public StoreEnum(string path) {
            this.path = path;
            currentReceipt.items = new List<Item>();
            inFile = new StreamReader(path);
        }

        public bool MoveNext() {
            currentReceipt.items = new List<Item>();
            string[] input;
            Item item;

            if (!inFile.EndOfStream) {
                input = inFile.ReadLine().Split();
                currentReceipt.name = input[0];

                for (int i = 1; i < input.Length; i += 2) {
                    item = new Item();
                    item.id = input[i];
                    item.price = uint.Parse(input[i + 1]);
                    currentReceipt.AddItem(item);
                }

                return true;
            }
            else
                return false;
        }

        public void Reset() {
            inFile.Close();
            inFile = new StreamReader(path);
        }

        object IEnumerator.Current {
            get {
                return currentReceipt;
            }
        }

        public Receipt Current {
            get {
                try {
                    return currentReceipt;
                }
                catch (IndexOutOfRangeException) {
                    throw new InvalidOperationException();
                }
            }
        }
    }
}
