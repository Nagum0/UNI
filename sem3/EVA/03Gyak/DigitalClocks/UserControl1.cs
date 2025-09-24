using System.ComponentModel;

namespace DigitalClocks
{
    public partial class Clock : UserControl
    {
        private int timeZone;

        public Clock()
        {
            InitializeComponent();
        }

        public string City
        {
            get => cityLabel.Text;
            set => cityLabel.Text = value;
        }

        [Category("Appearance")]
        [Description("The hour offset of the timezone.")]
        public int TimeZone
        {
            get => timeZone;
            set
            {
                timeZone = value;
                RefreshTime(this, EventArgs.Empty);
            }
        }

        private void RefreshTime(object sender, EventArgs e)
        {
            DateTime time = DateTime.Now;
            timeLabel.Text = time
                .AddHours(TimeZone)
                .ToString(time.Second % 2 == 0 ? "HH:mm" : "HH mm");
        }
    }
}
