namespace DigitalClocks
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            flowLayoutPanel = new FlowLayoutPanel();
            clock1 = new Clock();
            clock2 = new Clock();
            clock3 = new Clock();
            clock4 = new Clock();
            flowLayoutPanel.SuspendLayout();
            SuspendLayout();
            // 
            // flowLayoutPanel
            // 
            flowLayoutPanel.Controls.Add(clock1);
            flowLayoutPanel.Controls.Add(clock2);
            flowLayoutPanel.Controls.Add(clock3);
            flowLayoutPanel.Controls.Add(clock4);
            flowLayoutPanel.Dock = DockStyle.Fill;
            flowLayoutPanel.Location = new Point(0, 0);
            flowLayoutPanel.Name = "flowLayoutPanel";
            flowLayoutPanel.Size = new Size(397, 363);
            flowLayoutPanel.TabIndex = 0;
            // 
            // clock1
            // 
            clock1.City = "City name";
            clock1.Location = new Point(3, 3);
            clock1.Name = "clock1";
            clock1.Size = new Size(188, 188);
            clock1.TabIndex = 0;
            clock1.TimeZone = 0;
            // 
            // clock2
            // 
            clock2.City = "City name";
            clock2.Location = new Point(197, 3);
            clock2.Name = "clock2";
            clock2.Size = new Size(188, 188);
            clock2.TabIndex = 1;
            clock2.TimeZone = 0;
            // 
            // clock3
            // 
            clock3.City = "City name";
            clock3.Location = new Point(3, 197);
            clock3.Name = "clock3";
            clock3.Size = new Size(188, 188);
            clock3.TabIndex = 2;
            clock3.TimeZone = 0;
            // 
            // clock4
            // 
            clock4.City = "City name";
            clock4.Location = new Point(197, 197);
            clock4.Name = "clock4";
            clock4.Size = new Size(188, 188);
            clock4.TabIndex = 3;
            clock4.TimeZone = 0;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(397, 363);
            Controls.Add(flowLayoutPanel);
            Name = "Form1";
            Text = "Form1";
            flowLayoutPanel.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private FlowLayoutPanel flowLayoutPanel;
        private Clock clock1;
        private Clock clock2;
        private Clock clock3;
        private Clock clock4;
    }
}
