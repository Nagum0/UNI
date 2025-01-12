using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows.Documents;

namespace WpfMintaZH
{
    public class Field : ViewModelBase
    {
        private string _value { get; set; }
        public int X { get; private set; }
        public int Y { get; private set; }

        public string Value
        {
            get => _value;
            set
            {
                _value = value;
                OnPropertyChanged(nameof(Value));
            }
        }

        public Field(int x, int y, string value)
        {
            X = x;
            Y = y;
            _value = value;
        }
    }

    public class Puppet : ViewModelBase
    {
        public int Count { get; private set; }
        public int X { get; set; }
        public int Y { get; set; }

        public Puppet(int x, int y, int count)
        {
            Count = count;
            X = x; 
            Y = y;
        }
    }

    public class Player : ViewModelBase
    {
        private bool p1 = true;
        public ObservableCollection<Puppet> Puppets { get; private set; }

        public Player(bool p1)
        {
            this.p1 = p1;
            Puppets = new ObservableCollection<Puppet>();
            InitPuppets();
        }

        private void InitPuppets()
        {
            if (p1)
            {
                Puppets.Add(new Puppet(0, 4, 1));
                Puppets.Add(new Puppet(1, 4, 2));
                Puppets.Add(new Puppet(0, 5, 4));
                Puppets.Add(new Puppet(1, 5, 3));
            }
            else
            {
                Puppets.Add(new Puppet(4, 0, 3));
                Puppets.Add(new Puppet(5, 0, 4));
                Puppets.Add(new Puppet(4, 1, 2));
                Puppets.Add(new Puppet(5, 1, 1));
            }
        }
    }

    public class Model : INotifyPropertyChanged
    {
        public string RoundText { get; set; } = "P1: 1";
        public Player P1 { get; set; }
        public Player P2 { get; set; }
        public int N { get; private set; } = 6;
        public ObservableCollection<Field> Fields { get; private set; }
        public event PropertyChangedEventHandler? PropertyChanged;
        public Player _turn;
        public int _puppetTurn;

        public Model()
        {
            P1 = new Player(true);
            P2 = new Player(false);
            _turn = P1;
            _puppetTurn = 0;
            Fields = new ObservableCollection<Field>();
            InitFields();
        }

        public void UpdateFields(Field field)
        {
            for (int i = 0; i < Fields.Count; i++)
            {
                if (Fields[i].X == field.X && Fields[i].Y == field.Y)
                {
                    Fields[i].Value = _turn.Puppets[_puppetTurn].Count.ToString();
                    _turn = P2;
                    _puppetTurn++;
                }
            }
        }

        private void InitFields()
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    string v = (j, i) switch
                    {
                        (0, 4) => P1.Puppets[0].Count.ToString(),
                        (1, 4) => P1.Puppets[1].Count.ToString(),
                        (0, 5) => P1.Puppets[2].Count.ToString(),
                        (1, 5) => P1.Puppets[3].Count.ToString(),
                        (4, 0) => P2.Puppets[0].Count.ToString(),
                        (5, 0) => P2.Puppets[1].Count.ToString(),
                        (4, 1) => P2.Puppets[2].Count.ToString(),
                        (5, 1) => P2.Puppets[3].Count.ToString(),
                        _ => "",
                    };
                    Fields.Add(new Field(j, i, v));
                }
            }
        }

        private void OnPropertyChanged([CallerMemberName] string? param = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(param));
        }
    }
}
