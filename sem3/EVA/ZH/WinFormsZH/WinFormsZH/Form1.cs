// System.IndexOutOfRangeException: Index was outside the bounds of the array.
//    at WinFormsZH.Model.CheckShapeFit(Int32 x, Int32 y) in C:\Users\xptee\Documents\UNI\Sem3\EVA\ZH\WinFormsZH\WinFormsZH\Model.cs:line 45
//    at WinFormsZH.Form1.FieldSelected(Field field) in C:\Users\xptee\Documents\UNI\Sem3\EVA\ZH\WinFormsZH\WinFormsZH\Form1.cs:line 118
//    at WinFormsZH.Form1.<>c__DisplayClass6_0.<InitTable>b__0(Object _, EventArgs _) in C:\Users\xptee\Documents\UNI\Sem3\EVA\ZH\WinFormsZH\WinFormsZH\Form1.cs:line 104
//    at System.Windows.Forms.Button.OnClick(EventArgs e)
//    at System.Windows.Forms.Button.OnMouseUp(MouseEventArgs mevent)
//    at System.Windows.Forms.Control.WmMouseUp(Message& m, MouseButtons button, Int32 clicks)
//    at System.Windows.Forms.Control.WndProc(Message& m)
//    at System.Windows.Forms.ButtonBase.WndProc(Message& m)
//    at System.Windows.Forms.NativeWindow.Callback(HWND hWnd, MessageId msg, WPARAM wparam, LPARAM lparam)
//

namespace WinFormsZH
{
    public partial class Shape : Form 
    {
        public Shape(bool[,] s)
        {
            Width = 215;
            Height = 240;

            int rowX = 0;
            int colOffset = 0;

            for (int i = 0; i < 2; i++) 
            {
                for (int j = 0; j < 2; j++)
                {
                    Button btn = new Button();
                    btn.Width = 100;
                    btn.Height = 100;
                    btn.Location = new Point(rowX, colOffset);
                    btn.BackColor = s[i,j] ? Color.Blue : Color.White;
                    rowX += 100;
                    Controls.Add(btn);
                }
                
                rowX = 0;
                colOffset += 100;
            }
        }
    }

    public class Field : Button
    {
        public int X { get; private set; }
        public int Y { get; private set; }

        public Field(int x, int y) 
        {
            X = x;
            Y = y;
        }
    }

    public partial class Form1 : Form
    {
        private Model _model;
        private List<List<Field>> _table;

        public Form1()
        {
            InitializeComponent();
            Width = 415;
            Height = 440;

            _model = new Model();
            _model.UpdateFields += Model_UpdateFields;
            _model.IncorrectPlacement += Model_IncorrectPlacement;
            _table = [];

            InitTable();
            GenNewShape();
        }

        private void Model_UpdateFields(object? sender, EventArgs args)
        {
            for (int i = 0; i < _model.N; i++) 
            {
                for (int j = 0; j < _model.N; j++) 
                {
                    _table[i][j].BackColor = _model.Table[i][j] ? Color.Blue : Color.White;       
                }
            }

            GenNewShape();
        }

        private void Model_IncorrectPlacement(object? sender, EventArgs args)
        {
            MessageBox.Show("INCORRECT PLACEMENT");
        }

        private void GenNewShape()
        {
            bool[,] shape = _model.GenerateShape();
            Form shapeForm = new Shape(shape);
            shapeForm.Show();
        }

        private void InitTable() 
        {
            _model.InitTable();
            int rowX = 0;
            int colOffset = 0;

            for (int i = 0; i < _model.N; i++) {
                List<Field> row = [];

                for (int j = 0; j < _model.N; j++) {
                    Field field = new Field(j, i);
                    field.Width = 100;
                    field.Height = 100;
                    field.BackColor = Color.White;
                    field.Location = new Point(rowX, colOffset);
                    field.Click += (_, _) => FieldSelected(field);
                    row.Add(field);
                    Controls.Add(field);
                    rowX += 100;
                }
                
                rowX = 0;
                colOffset += 100;
                _table.Add(row);
            }
        }

        private void FieldSelected(Field field)
        {
            _model.CheckShapeFit(field.X, field.Y);
        }
    }
}
