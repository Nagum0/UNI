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
            shipBody3 = new PictureBox();
            shipBody2 = new PictureBox();
            shipBody1 = new PictureBox();
            player = new PictureBox();
            startButton = new Button();
            stopButton = new Button();
            saveButton = new Button();
            loadButton = new Button();
            gameTimer = new System.Windows.Forms.Timer(components);
            gameTimeLabel = new Label();
            gameLoopTimer = new System.Windows.Forms.Timer(components);
            backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            ship1MineTimer = new System.Windows.Forms.Timer(components);
            ship2MineTimer = new System.Windows.Forms.Timer(components);
            ship3MineTimer = new System.Windows.Forms.Timer(components);
            gamePanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)shipBody3).BeginInit();
            ((System.ComponentModel.ISupportInitialize)shipBody2).BeginInit();
            ((System.ComponentModel.ISupportInitialize)shipBody1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)player).BeginInit();
            SuspendLayout();
            // 
            // gamePanel
            // 
            gamePanel.BackColor = Color.RoyalBlue;
            gamePanel.Controls.Add(shipBody3);
            gamePanel.Controls.Add(shipBody2);
            gamePanel.Controls.Add(shipBody1);
            gamePanel.Controls.Add(player);
            gamePanel.Location = new Point(70, 65);
            gamePanel.Name = "gamePanel";
            gamePanel.Size = new Size(1141, 713);
            gamePanel.TabIndex = 1;
            // 
            // shipBody3
            // 
            shipBody3.BackColor = Color.Maroon;
            shipBody3.Location = new Point(377, 179);
            shipBody3.Margin = new Padding(3, 4, 3, 4);
            shipBody3.Name = "shipBody3";
            shipBody3.Size = new Size(208, 67);
            shipBody3.TabIndex = 3;
            shipBody3.TabStop = false;
            // 
            // shipBody2
            // 
            shipBody2.BackColor = Color.Maroon;
            shipBody2.Location = new Point(609, 99);
            shipBody2.Margin = new Padding(3, 4, 3, 4);
            shipBody2.Name = "shipBody2";
            shipBody2.Size = new Size(208, 67);
            shipBody2.TabIndex = 2;
            shipBody2.TabStop = false;
            // 
            // shipBody1
            // 
            shipBody1.BackColor = Color.Maroon;
            shipBody1.Location = new Point(859, 25);
            shipBody1.Margin = new Padding(3, 4, 3, 4);
            shipBody1.Name = "shipBody1";
            shipBody1.Size = new Size(208, 67);
            shipBody1.TabIndex = 1;
            shipBody1.TabStop = false;
            // 
            // player
            // 
            player.BackColor = Color.FromArgb(64, 64, 64);
            player.Location = new Point(504, 580);
            player.Name = "player";
            player.Size = new Size(65, 61);
            player.TabIndex = 0;
            player.TabStop = false;
            // 
            // startButton
            // 
            startButton.Location = new Point(266, 800);
            startButton.Name = "startButton";
            startButton.Size = new Size(147, 68);
            startButton.TabIndex = 2;
            startButton.Text = "START";
            startButton.UseVisualStyleBackColor = true;
            startButton.Click += StartButton_Click;
            // 
            // stopButton
            // 
            stopButton.Location = new Point(459, 800);
            stopButton.Name = "stopButton";
            stopButton.Size = new Size(147, 68);
            stopButton.TabIndex = 3;
            stopButton.Text = "STOP";
            stopButton.UseVisualStyleBackColor = true;
            stopButton.Click += StopButton_Click;
            // 
            // saveButton
            // 
            saveButton.Enabled = false;
            saveButton.Location = new Point(658, 800);
            saveButton.Name = "saveButton";
            saveButton.Size = new Size(147, 68);
            saveButton.TabIndex = 4;
            saveButton.Text = "SAVE";
            saveButton.UseVisualStyleBackColor = true;
            saveButton.Click += SaveButton_Click;
            // 
            // loadButton
            // 
            loadButton.Location = new Point(859, 800);
            loadButton.Name = "loadButton";
            loadButton.Size = new Size(147, 68);
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
            gameTimeLabel.Location = new Point(557, 9);
            gameTimeLabel.Name = "gameTimeLabel";
            gameTimeLabel.Size = new Size(208, 50);
            gameTimeLabel.TabIndex = 6;
            gameTimeLabel.Text = "Game time:";
            // 
            // GameForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(64, 64, 64);
            ClientSize = new Size(1282, 913);
            Controls.Add(gameTimeLabel);
            Controls.Add(loadButton);
            Controls.Add(saveButton);
            Controls.Add(stopButton);
            Controls.Add(startButton);
            Controls.Add(gamePanel);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Name = "GameForm";
            Text = "Aknamező";
            gamePanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)shipBody3).EndInit();
            ((System.ComponentModel.ISupportInitialize)shipBody2).EndInit();
            ((System.ComponentModel.ISupportInitialize)shipBody1).EndInit();
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
        private PictureBox shipBody1;
        private PictureBox shipBody2;
        private PictureBox shipBody3;
        private System.Windows.Forms.Timer ship1MineTimer;
        private System.Windows.Forms.Timer ship2MineTimer;
        private System.Windows.Forms.Timer ship3MineTimer;
    }
}
