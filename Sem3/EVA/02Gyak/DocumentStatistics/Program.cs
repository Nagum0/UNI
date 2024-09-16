namespace DocumentStatistics
{
	internal class Program
	{
		static int ReadPositive(string message)
		{
			return int.Parse(message);
		}

		static List<string> ReadIgnoredWords()
		{
			return Console.ReadLine().Split(',').ToList();
		}

		static int Main(string[] args)
		{
			// Getting the file path:
			string? filePath;
			do
			{
				Console.Write("Path: ");
				filePath = Console.ReadLine();
			} while (Path.GetExtension(filePath) != ".txt" || !File.Exists(filePath));

			int minOccurrence = 0;
			do
			{
				try
				{
					Console.Write("Min occurance: ");
					string? message = Console.ReadLine();
					minOccurrence = ReadPositive(message);
					break;
				}
				catch (Exception ex)
				{
					Console.WriteLine(ex.Message);
					continue;
				}
			} while (true);

			int minLength = 0;
			do
			{
				try
				{
					Console.Write("Min length: ");
					string? message = Console.ReadLine();
					minLength = ReadPositive(message);
					break;
				}
				catch (Exception ex)
				{
					Console.WriteLine(ex.Message);
					continue;
				}
			} while (true);

			var ignoredWords = ReadIgnoredWords();

			DocumentStatistics statistics = new(filePath);

			try
			{
				statistics.Load();
				// statistics.ComputeDistinctWords();
				Console.WriteLine($"Character count: {statistics.CharacterCount}");
				Console.WriteLine($"Non whitespace character count: {statistics.NonWhiteSpaceCharacterCount}");
				Console.WriteLine($"Sentence count: {statistics.SentenceCount}");
				Console.WriteLine($"Proper noun count: {statistics.ProperNounCount}");
				Console.WriteLine($"Coleman Lieu index: {statistics.ColemanLieuIndex}");
				Console.WriteLine($"Flesch Reading Ease: {statistics.FleschReadingEase}");
			}
			catch (IOException ie)
			{
				Console.WriteLine(ie.Message);
				return -1;
			}

			var pairs = statistics.DistinctWordCount
				.Where(p => p.Value >= minOccurrence)
				.Where(p => p.Key.Length >= minLength)
				.Where(p => !ignoredWords.Contains(p.Key))
				.OrderByDescending(p => p.Value);
			foreach (var pair in pairs)
			{
				Console.WriteLine($"{pair.Key} : {pair.Value}");
			}

			return 0;
		}
	}
}
