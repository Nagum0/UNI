namespace Quit
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
            quitButton = new Button();
            SuspendLayout();
            // 
            // quitButton
            // 
            quitButton.Font = new Font("Segoe UI", 16F, FontStyle.Bold);
            quitButton.Location = new Point(226, 116);
            quitButton.Name = "quitButton";
            quitButton.Size = new Size(122, 53);
            quitButton.TabIndex = 0;
            quitButton.Text = "QUIT";
            quitButton.UseVisualStyleBackColor = true;
            quitButton.Click += quitButton_Clicked;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(569, 316);
            Controls.Add(quitButton);
            Name = "Form1";
            Text = "My First WinForms Application";
            ResumeLayout(false);
        }

        #endregion

        private Button quitButton;
    }
}
