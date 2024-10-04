namespace AknamezoWinForms
{
    partial class GameForm
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
            gamePanel = new Panel();
            player = new PictureBox();
            startButton = new Button();
            stopButton = new Button();
            saveButton = new Button();
            loadButton = new Button();
            gameTimer = new System.Windows.Forms.Timer(components);
            gameTimeLabel = new Label();
            gameLoopTimer = new System.Windows.Forms.Timer(components);
            backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            gamePanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)player).BeginInit();
            SuspendLayout();
            // 
            // gamePanel
            // 
            gamePanel.BackColor = Color.RoyalBlue;
            gamePanel.Controls.Add(player);
            gamePanel.Location = new Point(61, 49);
            gamePanel.Margin = new Padding(3, 2, 3, 2);
            gamePanel.Name = "gamePanel";
            gamePanel.Size = new Size(998, 535);
            gamePanel.TabIndex = 1;
            // 
            // player
            // 
            player.BackColor = Color.FromArgb(64, 64, 64);
            player.Location = new Point(441, 435);
            player.Margin = new Padding(3, 2, 3, 2);
            player.Name = "player";
            player.Size = new Size(109, 46);
            player.TabIndex = 0;
            player.TabStop = false;
            // 
            // startButton
            // 
            startButton.Location = new Point(233, 600);
            startButton.Margin = new Padding(3, 2, 3, 2);
            startButton.Name = "startButton";
            startButton.Size = new Size(129, 51);
            startButton.TabIndex = 2;
            startButton.Text = "START";
            startButton.UseVisualStyleBackColor = true;
            startButton.Click += StartButton_Click;
            // 
            // stopButton
            // 
            stopButton.Location = new Point(402, 600);
            stopButton.Margin = new Padding(3, 2, 3, 2);
            stopButton.Name = "stopButton";
            stopButton.Size = new Size(129, 51);
            stopButton.TabIndex = 3;
            stopButton.Text = "STOP";
            stopButton.UseVisualStyleBackColor = true;
            stopButton.Click += StopButton_Click;
            // 
            // saveButton
            // 
            saveButton.Enabled = false;
            saveButton.Location = new Point(576, 600);
            saveButton.Margin = new Padding(3, 2, 3, 2);
            saveButton.Name = "saveButton";
            saveButton.Size = new Size(129, 51);
            saveButton.TabIndex = 4;
            saveButton.Text = "SAVE";
            saveButton.UseVisualStyleBackColor = true;
            saveButton.Click += SaveButton_Click;
            // 
            // loadButton
            // 
            loadButton.Location = new Point(752, 600);
            loadButton.Margin = new Padding(3, 2, 3, 2);
            loadButton.Name = "loadButton";
            loadButton.Size = new Size(129, 51);
            loadButton.TabIndex = 5;
            loadButton.Text = "LOAD";
            loadButton.UseVisualStyleBackColor = true;
            loadButton.Click += LoadButton_Click;
            // 
            // gameTimeLabel
            // 
            gameTimeLabel.AutoSize = true;
            gameTimeLabel.BackColor = Color.FromArgb(64, 64, 64);
            gameTimeLabel.Font = new Font("Segoe UI", 22.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            gameTimeLabel.ForeColor = SystemColors.ButtonHighlight;
            gameTimeLabel.Location = new Point(487, 7);
            gameTimeLabel.Name = "gameTimeLabel";
            gameTimeLabel.Size = new Size(170, 41);
            gameTimeLabel.TabIndex = 6;
            gameTimeLabel.Text = "Game time:";
            // 
            // GameForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(64, 64, 64);
            ClientSize = new Size(1122, 685);
            Controls.Add(gameTimeLabel);
            Controls.Add(loadButton);
            Controls.Add(saveButton);
            Controls.Add(stopButton);
            Controls.Add(startButton);
            Controls.Add(gamePanel);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Margin = new Padding(3, 2, 3, 2);
            Name = "GameForm";
            Text = "Aknamező";
            gamePanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)player).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Panel gamePanel;
        private Button startButton;
        private Button stopButton;
        private Button saveButton;
        private Button loadButton;
        private PictureBox player;
        private System.Windows.Forms.Timer gameTimer;
        private Label gameTimeLabel;
        private System.Windows.Forms.Timer gameLoopTimer;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
    }
}
