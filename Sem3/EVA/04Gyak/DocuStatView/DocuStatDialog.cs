using DocumentStatistics;

namespace DocuStatView
{
    public partial class DocuStatDialog : Form
    {
        private DocuStats? _documentStatistics;

        public DocuStatDialog()
        {
            InitializeComponent();
        }

        private void OpenDialog(object? sender, EventArgs e)
        {
            using (OpenFileDialog dialog = new OpenFileDialog())
            {
                dialog.InitialDirectory = "C:\\";
                dialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
                dialog.RestoreDirectory = true;

                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        _documentStatistics = new DocuStats(dialog.FileName);
                        _documentStatistics.FileContentReady += UpdateFileContent;
                        _documentStatistics.TextStatisticsReady += UpdateTextStatistics;
                        _documentStatistics.Load();
                    }
                    catch (IOException ex)
                    {
                        MessageBox.Show("File reading is unsuccessful!\n" + ex.Message,
                                        "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                 }
            }
        }

        private void UpdateFileContent(object? sender, EventArgs e)
        {
            if (_documentStatistics?.FileContent == textBox.Text)
                return;

            textBox.Text = _documentStatistics?.FileContent;
            listBoxCounter.Items.Clear();
        }

        private void UpdateTextStatistics(object? sender, EventArgs e)
        {
            label4.Text = $"{label4.Text} {_documentStatistics?.CharacterCount}";
            label5.Text = $"{label5.Text} {_documentStatistics?.NonWhiteSpaceCharacterCount}";
            label6.Text = $"{label6.Text} {_documentStatistics?.SentenceCount}";
            label7.Text = $"{label7.Text} {_documentStatistics?.ProperNounCount}";
            label8.Text = $"{label8.Text} {_documentStatistics?.ColemanLieuIndex}";
            label9.Text = $"{label9.Text} {_documentStatistics?.FleschReadingEase}";
        }

        private void CountWords(object? sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(_documentStatistics?.FileContent)) {
                MessageBox.Show("No file was read!");
            }

            int minLength = Convert.ToInt32(spinBoxMinLength.Value);
            int minOccurance = Convert.ToInt32(spinBoxMinOccurrence.Value);
            List<string> bannedWords = textBoxIgnoredWords.Text.Split(',').Select(s => s.Trim()).ToList();
            var pairs = _documentStatistics?.DistinctWordCount
                .Where(p => p.Value >= minOccurance)
                .Where(p => p.Key.Length >= minLength)
                .Where(p => !bannedWords.Contains(p.Key))
                .OrderByDescending(p => p.Value);

            listBoxCounter.Items.Clear();
            listBoxCounter.BeginUpdate();
            
            foreach (var pair in pairs)
            {
                listBoxCounter.Items.Add(pair.Key + ": " + pair.Value);
            }

            listBoxCounter.EndUpdate();
        }
    }
}
