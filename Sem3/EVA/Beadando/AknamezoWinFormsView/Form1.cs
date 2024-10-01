namespace AknamezoWinFormsView
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
			KeyPreview = true;
			KeyDown += new KeyEventHandler(MoveSubmarine);
		}

		private void MoveSubmarine(object? sender, KeyEventArgs e) {
			Point submarineLocation = submarine.Location;

			if (e.KeyCode == Keys.A) {
				submarine.Location = new Point(submarineLocation.X - 10, submarineLocation.Y);
			}
			else if (e.KeyCode == Keys.D) {
				submarine.Location = new Point(submarineLocation.X + 10, submarineLocation.Y);
			}
		}
    }
}
