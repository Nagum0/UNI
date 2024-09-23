namespace Gombvadászat
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
            components = new System.ComponentModel.Container();
            pushButton = new Button();
            statusStrip = new StatusStrip();
            statusLabel = new ToolStripStatusLabel();
            timer1 = new System.Windows.Forms.Timer(components);
            statusStrip.SuspendLayout();
            SuspendLayout();
            // 
            // pushButton
            // 
            pushButton.Location = new Point(338, 194);
            pushButton.Name = "pushButton";
            pushButton.Size = new Size(142, 61);
            pushButton.TabIndex = 0;
            pushButton.Text = "PUSH ME";
            pushButton.UseVisualStyleBackColor = true;
            pushButton.Click += pushMe_ButtonClicked;
            // 
            // statusStrip
            // 
            statusStrip.ImageScalingSize = new Size(20, 20);
            statusStrip.Items.AddRange(new ToolStripItem[] { statusLabel });
            statusStrip.Location = new Point(0, 424);
            statusStrip.Name = "statusStrip";
            statusStrip.Size = new Size(800, 26);
            statusStrip.TabIndex = 1;
            statusStrip.Text = "statusStrip1";
            // 
            // statusLabel
            // 
            statusLabel.Name = "statusLabel";
            statusLabel.Size = new Size(235, 20);
            statusLabel.Text = "Click the button to start the game!";
            // 
            // timer1
            // 
            timer1.Tick += UpdateStatusBar;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(statusStrip);
            Controls.Add(pushButton);
            MinimumSize = new Size(450, 450);
            Name = "Form1";
            Text = "Button Hunter";
            FormClosing += GameClosing;
            statusStrip.ResumeLayout(false);
            statusStrip.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button pushButton;
        private StatusStrip statusStrip;
        private ToolStripStatusLabel statusLabel;
        private System.Windows.Forms.Timer timer1;
    }
}
