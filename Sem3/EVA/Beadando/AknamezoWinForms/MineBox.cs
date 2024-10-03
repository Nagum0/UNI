using AknamezoModel;
using Timer = System.Windows.Forms.Timer;

namespace AknamezoWinForms
{
    public class MineBox : PictureBox
    {
        public Timer timer;
        public Mine model;

        public MineBox(int weight)
        {
            timer = new Timer();
            model = new Mine(weight);
        }
    }
}
