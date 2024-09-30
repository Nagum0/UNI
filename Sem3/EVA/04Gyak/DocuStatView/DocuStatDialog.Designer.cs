namespace DocuStatView
{
    partial class DocuStatDialog
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
            menuStrip1 = new MenuStrip();
            fileMenu = new ToolStripMenuItem();
            openFileDialogMenuItem = new ToolStripMenuItem();
            countWordsMenuItem = new ToolStripMenuItem();
            textBox = new TextBox();
            listBoxCounter = new ListBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            label7 = new Label();
            label8 = new Label();
            label9 = new Label();
            spinBoxMinLength = new NumericUpDown();
            spinBoxMinOccurrence = new NumericUpDown();
            textBoxIgnoredWords = new TextBox();
            menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)spinBoxMinLength).BeginInit();
            ((System.ComponentModel.ISupportInitialize)spinBoxMinOccurrence).BeginInit();
            SuspendLayout();
            // 
            // menuStrip1
            // 
            menuStrip1.ImageScalingSize = new Size(20, 20);
            menuStrip1.Items.AddRange(new ToolStripItem[] { fileMenu, countWordsMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(882, 28);
            menuStrip1.TabIndex = 0;
            menuStrip1.Text = "menuStrip1";
            // 
            // fileMenu
            // 
            fileMenu.DropDownItems.AddRange(new ToolStripItem[] { openFileDialogMenuItem });
            fileMenu.Name = "fileMenu";
            fileMenu.Size = new Size(46, 24);
            fileMenu.Text = "File";
            // 
            // openFileDialogMenuItem
            // 
            openFileDialogMenuItem.Name = "openFileDialogMenuItem";
            openFileDialogMenuItem.Size = new Size(200, 26);
            openFileDialogMenuItem.Text = "Open file dialog";
            openFileDialogMenuItem.Click += OpenDialog;
            // 
            // countWordsMenuItem
            // 
            countWordsMenuItem.Name = "countWordsMenuItem";
            countWordsMenuItem.Size = new Size(106, 24);
            countWordsMenuItem.Text = "Count words";
            // 
            // textBox
            // 
            textBox.Location = new Point(0, 31);
            textBox.Multiline = true;
            textBox.Name = "textBox";
            textBox.ReadOnly = true;
            textBox.ScrollBars = ScrollBars.Vertical;
            textBox.Size = new Size(450, 325);
            textBox.TabIndex = 1;
            // 
            // listBoxCounter
            // 
            listBoxCounter.FormattingEnabled = true;
            listBoxCounter.Location = new Point(454, 32);
            listBoxCounter.Name = "listBoxCounter";
            listBoxCounter.Size = new Size(428, 324);
            listBoxCounter.TabIndex = 2;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(544, 393);
            label1.Name = "label1";
            label1.Size = new Size(154, 20);
            label1.TabIndex = 3;
            label1.Text = "Minimum word count:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(544, 428);
            label2.Name = "label2";
            label2.Size = new Size(184, 20);
            label2.TabIndex = 4;
            label2.Text = "Minimum word occurance:";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(544, 465);
            label3.Name = "label3";
            label3.Size = new Size(108, 20);
            label3.TabIndex = 5;
            label3.Text = "Ignored words:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(40, 393);
            label4.Name = "label4";
            label4.Size = new Size(116, 20);
            label4.TabIndex = 6;
            label4.Text = "Character count:";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(40, 428);
            label5.Name = "label5";
            label5.Size = new Size(191, 20);
            label5.TabIndex = 7;
            label5.Text = "Non-whitespace characters:";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(40, 465);
            label6.Name = "label6";
            label6.Size = new Size(113, 20);
            label6.TabIndex = 8;
            label6.Text = "Sentence count:";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(306, 393);
            label7.Name = "label7";
            label7.Size = new Size(134, 20);
            label7.TabIndex = 9;
            label7.Text = "Proper noun count:";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(306, 428);
            label8.Name = "label8";
            label8.Size = new Size(142, 20);
            label8.TabIndex = 10;
            label8.Text = "Coleman Lieu index:";
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(306, 465);
            label9.Name = "label9";
            label9.Size = new Size(141, 20);
            label9.TabIndex = 11;
            label9.Text = "Flesch reading ease:";
            // 
            // spinBoxMinLength
            // 
            spinBoxMinLength.Location = new Point(705, 392);
            spinBoxMinLength.Maximum = new decimal(new int[] { 500, 0, 0, 0 });
            spinBoxMinLength.Minimum = new decimal(new int[] { 1, 0, 0, 0 });
            spinBoxMinLength.Name = "spinBoxMinLength";
            spinBoxMinLength.Size = new Size(165, 27);
            spinBoxMinLength.TabIndex = 12;
            spinBoxMinLength.Value = new decimal(new int[] { 1, 0, 0, 0 });
            // 
            // spinBoxMinOccurrence
            // 
            spinBoxMinOccurrence.Location = new Point(732, 425);
            spinBoxMinOccurrence.Maximum = new decimal(new int[] { 500, 0, 0, 0 });
            spinBoxMinOccurrence.Minimum = new decimal(new int[] { 1, 0, 0, 0 });
            spinBoxMinOccurrence.Name = "spinBoxMinOccurrence";
            spinBoxMinOccurrence.Size = new Size(138, 27);
            spinBoxMinOccurrence.TabIndex = 13;
            spinBoxMinOccurrence.Value = new decimal(new int[] { 1, 0, 0, 0 });
            // 
            // textBoxIgnoredWords
            // 
            textBoxIgnoredWords.Location = new Point(654, 466);
            textBoxIgnoredWords.Name = "textBoxIgnoredWords";
            textBoxIgnoredWords.Size = new Size(216, 27);
            textBoxIgnoredWords.TabIndex = 14;
            // 
            // DocuStatDialog
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(882, 553);
            Controls.Add(textBoxIgnoredWords);
            Controls.Add(spinBoxMinOccurrence);
            Controls.Add(spinBoxMinLength);
            Controls.Add(label9);
            Controls.Add(label8);
            Controls.Add(label7);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(listBoxCounter);
            Controls.Add(textBox);
            Controls.Add(menuStrip1);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            MainMenuStrip = menuStrip1;
            MaximizeBox = false;
            Name = "DocuStatDialog";
            Text = "Document statistics";
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)spinBoxMinLength).EndInit();
            ((System.ComponentModel.ISupportInitialize)spinBoxMinOccurrence).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private MenuStrip menuStrip1;
        private ToolStripMenuItem fileMenu;
        private ToolStripMenuItem openFileDialogMenuItem;
        private ToolStripMenuItem countWordsMenuItem;
        private TextBox textBox;
        private ListBox listBoxCounter;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Label label6;
        private Label label7;
        private Label label8;
        private Label label9;
        private NumericUpDown spinBoxMinLength;
        private NumericUpDown spinBoxMinOccurrence;
        private TextBox textBoxIgnoredWords;
    }
}
