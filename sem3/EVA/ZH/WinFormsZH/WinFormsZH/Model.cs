namespace WinFormsZH {
    public class Model 
    {
        public bool[][] Table { get; private set; }
        public int N { get; private set; } = 4;
        public bool[,] CurrentShape { get; private set; }
        public int CurrentShapeNum { get; private set; }

        public event EventHandler? UpdateFields;
        public event EventHandler? IncorrectPlacement;

        public Model() 
        {
            Table = new bool[4][];
            CurrentShape = new bool[2, 2];
        }

        public void CheckShapeFit(int x, int y) 
        {
            int endX = 0;
            int endY = 0;

            switch (CurrentShapeNum) 
            {
                case 0:
                    endX = x;
                    endY = y + 1;
                    break;
                case 1:
                    endX = x + 1;
                    endY = y;
                    break;
                default:
                    endX = x + 1;
                    endY = y + 1;
                    break;
            }

            if (endX >= N || endY >= N)
            {
                IncorrectPlacement?.Invoke(this, EventArgs.Empty);
                return;
            }

            bool[][] newTable = (bool[][])Table.Clone();

            for (int i = y; i <= endY; i++)
            {
                for (int j = x; j <= endX; j++)
                {
                    if (CurrentShape[i - y, j - x] && Table[i][j])
                    {
                        IncorrectPlacement?.Invoke(this, EventArgs.Empty);
                        return;
                    }
                    else 
                    {
                        int selectX = CurrentShapeNum switch 
                        {
                            0 => 0,
                            _ => j - x,
                        };
                        int selectY = CurrentShapeNum switch 
                        {
                            1 => 1,
                            _ => i - y,
                        };
                        newTable[i][j] = !Table[i][j] ? CurrentShape[selectY, selectX] : Table[i][j];
                    }
                }
            }

            for (int i = 0; i < N; i++) 
            {
                int j = 0;

                for (j = 0; j < N; j++) 
                {
                    if (!newTable[j][i])
                        break;
                }

                if (j == N)
                {
                    for (j = 0; j < N; j++) 
                        newTable[j][i] = false;
                }
            }
            
            Table = newTable;
            UpdateFields?.Invoke(this, EventArgs.Empty);
        }


        public bool[,] GenerateShape() {
            Random r = new Random();
            int shape = r.Next(0, 4);
            CurrentShapeNum = shape;
            CurrentShape = shape switch
            {
                0 => new bool[,] {{true, false}, {true, false}},
                1 => new bool[,] {{false, false}, {true, true}},
                2 => new bool[,] {{true, false}, {true, true}},
                _ => new bool[,] {{true, true}, {false, true}},
            };

            return CurrentShape;
        }

        public void InitTable() {
            for (int i = 0; i < N; i++) {
                Table[i] = [false, false, false, false];
            }
        }
    }
}
