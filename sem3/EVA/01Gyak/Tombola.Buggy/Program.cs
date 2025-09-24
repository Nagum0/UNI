using System;

namespace ELTE.Tombola
{
	class Program
	{
		// Initalized model to null
		private static TombolaModel? model = null;

		static void Main(string[] args)
		{
			Console.WriteLine("TOMBOLA GENERATOR");

			Console.WriteLine("Commands:");
			Console.WriteLine("\tnew:\tSet up a new Tombola Game");
			Console.WriteLine("\treset:\tReset the current Game");
			Console.WriteLine("\tdraw:\tDraw a ticket in the current Game");
			Console.WriteLine("\tcheck:\tCheck the status of a ticket in the current Game");
			Console.WriteLine("\tquit:\tAbort the application");

			// Now the game exits if I try to quit right away
			Console.Write("Command: ");
			string? command = Console.ReadLine();
			do
			{
				if (command == "new")
					NewGame();
				else if (command == "reset")
					ResetGame();
				else if (command == "draw")
					DrawTicket();
				else if (command == "check")
					CheckTicket();
				else if (command == "quit")
					break;

				Console.Write("Command: ");
				command = Console.ReadLine();
			}
			while (true);
		}

		private static void NewGame()
		{
			int ticketCount = ReadInt("Ticket count");

			try
			{
				model = new TombolaModel(ticketCount);
			}
			catch (ArgumentOutOfRangeException ex)
			{
				Console.WriteLine(ex.Message);
				Console.WriteLine("Game not created!");
			}
		}

		private static void ResetGame()
		{
			// Added null checking
			if (model == null)
			{
				Console.WriteLine("Start a game before resetting it!");
				return;
			}

			model.Reset();
			Console.WriteLine($"Game reset, ticket count: {model.TicketCount}");
		}

		private static void DrawTicket()
		{
			// Added null checking
			if (model == null)
			{
				Console.WriteLine("Start a game before drawing a ticket!");
				return;
			}

			// Added InvalidOperationException checking
			int nextTicket;
			try
			{
				nextTicket = model.Next();
			}
			catch (InvalidOperationException ex)
			{
				Console.WriteLine(ex.Message);
				return;
			}

			Console.WriteLine($"Next ticket: {nextTicket}");
		}

		private static void CheckTicket()
		{
			int ticket = ReadInt("Ticket");

			// Added null checking
			if (model == null)
			{
				Console.WriteLine("Start a game before checking a ticket!");
				return;
			}

			// Checks whether the ticket is valid
			try
			{
				if (model.IsTaken(ticket))
					Console.WriteLine("Already taken!");
				else
					Console.WriteLine("Not drawn yet!");
			}
			catch (ArgumentOutOfRangeException ex)
			{
				Console.WriteLine(ex.Message);
			}
		}

		private static int ReadInt(string message)
		{
			int number;
			bool readSuccess;
			do
			{
				Console.Write($"{message}: ");
				readSuccess = int.TryParse(Console.ReadLine(), out number);
			} while (!readSuccess);

			return number;
		}
	}
}
