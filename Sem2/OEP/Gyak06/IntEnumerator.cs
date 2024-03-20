using System;
using System.Collections;

namespace Gyak06
{

    public class IntEnumerator : IEnumerator
    {
        private StreamReader inFile;
        private string path;
        private Receipt curr;
        
        public IntEnumerator(string path)
        {
            this.path = path;
            inFile = new StreamReader(path);
        }

        public bool MoveNext()
        {
            string[] input;
            Item item;    

            if (!inFile.EndOfStream)
            {
                input = Console.ReadLine().Split();
                curr.cName = input[0];

                for (int i = 1; i < input.Length; i+=2)
                {
                    item = new Item();
                    item.id = int.Parse(input[i]);
                    item.price = int.Parse(input[i + 1]);
                    curr.items.Add(item);
                }

                return true;
            }
            else
                return false; 
        }

        public void Reset()
        {
            inFile.Close();
            inFile = new StreamReader(path);
        }

        object IEnumerator.Current
        {
            get { return curr; }
        }

        public Receipt Current
        {
            get
            {
                try
                {
                    return curr;
                }
                catch (IndexOutOfRangeException)
                {
                    throw new InvalidOperationException();
                }
            }
        }
    }

    public class IntEnum : IEnumerable
    {
        private string path;

        public IntEnum(string path)
        {
            this.path = path;
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return (IEnumerator) GetEnumerator();
        }

        public IntEnumerator GetEnumerator()
        {
            return new IntEnumerator(path);
        }
    }
}
