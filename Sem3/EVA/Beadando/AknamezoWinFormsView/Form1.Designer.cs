namespace AknamezoWinFormsView
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
            submarine = new PictureBox();
            ((System.ComponentModel.ISupportInitialize)submarine).BeginInit();
            SuspendLayout();
            // 
            // submarine
            // 
            submarine.BackColor = Color.FromArgb(192, 0, 0);
            submarine.Location = new Point(313, 240);
            submarine.Name = "submarine";
            submarine.Size = new Size(157, 89);
            submarine.TabIndex = 0;
            submarine.TabStop = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(submarine);
            Name = "Form1";
            Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)submarine).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private PictureBox submarine;
    }
}
