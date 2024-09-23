namespace Quit
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            quitButton.Click += new EventHandler(quitButton_Clicked);
        }

        private void quitButton_Clicked(object sender, EventArgs e)
        {
            Close();
        }
    }
}
