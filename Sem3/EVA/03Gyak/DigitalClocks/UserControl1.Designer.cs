namespace DigitalClocks
{
    partial class Clock
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            cityLabel = new Label();
            timeLabel = new Label();
            SuspendLayout();
            // 
            // cityLabel
            // 
            cityLabel.AutoSize = true;
            cityLabel.Location = new Point(40, 41);
            cityLabel.Name = "cityLabel";
            cityLabel.Size = new Size(75, 20);
            cityLabel.TabIndex = 0;
            cityLabel.Text = "City name";
            // 
            // timeLabel
            // 
            timeLabel.AutoSize = true;
            timeLabel.Location = new Point(40, 86);
            timeLabel.Name = "timeLabel";
            timeLabel.Size = new Size(60, 20);
            timeLabel.TabIndex = 1;
            timeLabel.Text = "HH:MM";
            // 
            // Clock
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            Controls.Add(timeLabel);
            Controls.Add(cityLabel);
            Name = "Clock";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label cityLabel;
        private Label timeLabel;
    }
}
