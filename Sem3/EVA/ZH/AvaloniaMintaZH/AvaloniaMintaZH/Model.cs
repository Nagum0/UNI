using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace AvaloniaMintaZH
{
    public enum FieldType
    {
        Soldier,
        Enemy,
        None,
    }

    public class Field : INotifyPropertyChanged
    {
        private int _x;
        private int _y;
        private FieldType _fieldType;
        private string _fieldColor = "White";
        
        public int X
        {
            get => _x;
            set
            {
                _x = value;
                OnPropertyChanged();
            }
        }
        public int Y
        {
            get => _y;
            set
            {
                _y = value;
                OnPropertyChanged();
            }
        }
        public FieldType FieldType
        {
            get => _fieldType;
            set
            {
                _fieldType = value;

                switch (_fieldType)
                {
                    case FieldType.None:
                        FieldColor = "White";
                        break;
                    case FieldType.Soldier:
                        FieldColor = "Blue";
                        break;
                    case FieldType.Enemy:
                        FieldColor = "Red";
                        break;
                }

                OnPropertyChanged();
            }
        }
        public string FieldColor
        {
            get => _fieldColor;
            private set
            {
                _fieldColor = value;
                OnPropertyChanged();
            }
        }

        public event PropertyChangedEventHandler? PropertyChanged;

        public Field(int x, int y, FieldType fieldType)
        {
            X = x;
            Y = y;
            FieldType = fieldType;
        }

        private void OnPropertyChanged([CallerMemberName] string? prop = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
        }
    }

    public class Model : INotifyPropertyChanged
    {
        public event EventHandler? CastleHit;

        private int _castleHealth = 3;
        private int _availableSoldiers = 2;
        private int _money = 2;

        public int Rows { get; private set; } = 5;
        public int Columns { get; private set; } = 10;
        public ObservableCollection<Field> Fields { get; private set; }

        public int CastleHealth
        {
            get => _castleHealth;
            private set
            {
                _castleHealth = value;
                OnPropertyChanged();
            }
        }

        public int AvailableSoldiers
        {
            get => _availableSoldiers;
            private set
            {
                _availableSoldiers = value;
                OnPropertyChanged();
            }
        }

        public int Money
        {
            get => _money;
            set
            {
                _money = value;
                OnPropertyChanged();
            }
        }

        public event PropertyChangedEventHandler? PropertyChanged;

        public Model()
        {
            Fields = new ObservableCollection<Field>();
            InitFields();
        }

        public void BuySoldier()
        {
            if (Money >= 1)
            {
                Money--;
                AvailableSoldiers++;
            }
        }

        public void GenerateRandomEnemies()
        {
            Random r = new Random();
            int n = r.Next(1, 3);

            for (int i = 0; i < n; i++)
            {
                int x = Columns - 1;
                int y = r.Next(0, Rows);
                SpawnEnemy(x, y);
            }
        }

        public void Update()
        {
            for (int i = 0; i < Fields.Count; i++)
            {
                switch (Fields[i].FieldType)
                {
                    case FieldType.Enemy:
                        MoveEnemy(i);
                        break;
                    default:
                        break;
                }
            }
        }

        private void MoveEnemy(int i)
        {
            // Save old field type for soldier check
            FieldType oldField = i > 0 ? Fields[i - 1].FieldType : FieldType.None;

            // Castle hit
            if (Fields[i].X == 0)
            {
                CastleHealth--;
                Fields[i].FieldType = FieldType.None;
                CastleHit?.Invoke(this, EventArgs.Empty);
            }
            // Simple move
            else if (Fields[i].X > 0)
            {
                Fields[i].X -= 1;
                Fields[i].FieldType = FieldType.None;
                Fields[i - 1].FieldType = FieldType.Enemy;
            }

            // Head on soldier collision
            if (oldField == FieldType.Soldier)
            {
                Fields[i - 1].FieldType = FieldType.None;
            }

            // Check if the field above or below the enemy is a soldier
            if (GetFieldType(Fields[i - 1].X, Fields[i - 1].Y + 1) == FieldType.Soldier || GetFieldType(Fields[i - 1].X, Fields[i - 1].Y - 1) == FieldType.Soldier)
            {
                Fields[i - 1].FieldType = FieldType.None;
            }
        }

        private void SpawnEnemy(int x, int y)
        {
            for (int i = 0; i < Fields.Count; i++)
            {
                if (Fields[i].X == x && Fields[i].Y == y)
                {
                    Fields[i].FieldType = FieldType.Enemy;
                }
            }
        }

        private FieldType GetFieldType(int x, int y)
        {
            foreach (Field field in Fields)
            {
                if (field.X == x && field.Y == y)
                    return field.FieldType;
            }

            return FieldType.None;
        }

        private void InitFields()
        {
            for (int i = 0; i < Rows; i++)
            {
                for (int j = 0; j < Columns; j++)
                {
                    Fields.Add(new Field(j, i, FieldType.None));
                }
            }
        }

        private void OnPropertyChanged([CallerMemberName] string? prop = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
        }
    }
}
