namespace DocumentStatistics
{
	public class DocuStats
	{
        public event EventHandler? FileContentReady;
        public event EventHandler? TextStatisticsReady;

        private string _filePath;
		public string FileContent { get; private set; }
		public Dictionary<string, int> DistinctWordCount { get; private set; }
		public int CharacterCount { get; private set; }
		public int NonWhiteSpaceCharacterCount { get; private set; }
		public int SentenceCount { get; private set; }
		public int ProperNounCount { get; private set; }
		public int ColemanLieuIndex { get; private set; }
		public int FleschReadingEase { get; private set; }

		public DocuStats(string _filePath)
		{
			this._filePath = _filePath;
		}

		// Throws System.IO.IOException
		public void Load()
		{
			FileContent = File.ReadAllText(_filePath);
			// Reading complete event:
			OnFileContentReady();

			ComputeDistinctWords();
			CharacterCount = FileContent.Length;
			int wsChars = FileContent.Count(c => char.IsWhiteSpace(c));
			NonWhiteSpaceCharacterCount = CharacterCount - wsChars;
			SentenceCount = ComputeSentenceCount();
			ProperNounCount = ComputeProperNounCount();
			ColemanLieuIndex = ComputeColemanLieuIndex();
			FleschReadingEase = ComputeFleschReadingEase();

			// Text statistics ready:
			OnTextStatisticsReady();
		}

		public void ComputeDistinctWords()
		{
			DistinctWordCount = new Dictionary<string, int>();
			string[] words = FileContent.Split();
			words = words.Where(s => s.Length > 0).ToArray();

			// Remove the non letter characters from the beginning and
			// end of the words:
			for (int i = 0; i < words.Length; i++)
			{
				words[i] = string.Concat(
					words[i]
						.SkipWhile(c => !char.IsLetter(c))
						.Reverse()
						.SkipWhile(c => !char.IsLetter(c))
						.Reverse()
					);

				if (string.IsNullOrEmpty(words[i]))
				{
					continue;
				}

				words[i] = words[i].ToLower();

				if (DistinctWordCount.ContainsKey(words[i]))
				{
					DistinctWordCount[words[i]]++;
				}
				else
				{
					DistinctWordCount.Add(words[i], 1);
				}
			}
		}

		private int ComputeSentenceCount()
		{
			return FileContent.Count(c => c == '!' || c == '.' || c == '?');
		}

		private int ComputeProperNounCount()
		{
			int count = 0;

			for (int i = 1; i < FileContent.Length; i++)
			{
				char c = FileContent[i];
				char prevC = FileContent[i - 1];

				if (char.IsUpper(c) && prevC != '!' && prevC != '.' && prevC != '?')
				{
					count++;
				}
			}

			return count;
		}

		private int ComputeColemanLieuIndex()
		{
			int totalWordCount = DistinctWordCount.Sum(p => p.Value);
			int l = NonWhiteSpaceCharacterCount / totalWordCount * 100;
			int s = SentenceCount / totalWordCount * 100;
			return (int)((0.0588 * l) - (0.296 * s) - 15.8);
		}

		private int ComputeFleschReadingEase()
		{
			int syllableCount = FileContent.Split().Sum(word => CountSyllables(word));
			int totalWordCount = FileContent.Split().Sum(word => word.Length);
			return (int)(206.835 - 1.015 * (totalWordCount / SentenceCount) - 84.6 * (syllableCount / totalWordCount));
		}

		private int CountSyllables(string word)
		{
			int count = 0;

			for (int i = 0; i < word.Length; i++)
			{
				if (IsVowel(word[i]) && i + 1 < word.Length && IsVowel(word[i + 1]))
				{
					count++;
				}
			}

			return count;
		}

		private bool IsVowel(char c)
		{
			return "aeiouyAEIOUY".IndexOf(c) != -1;
		}

		private void OnFileContentReady()
		{
			FileContentReady?.Invoke(this, EventArgs.Empty);
		}

		private void OnTextStatisticsReady()
		{
			TextStatisticsReady?.Invoke(this, EventArgs.Empty);
		}
	}
}