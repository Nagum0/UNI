/*
   Készítsen shell szkriptet folyamatok.sh néven, amely egy számítógép képzelt futó folyamatait kezeli. A számítógép bekapcsolásakor néhány folyamat automatikusan elindul 
   (ezeket egy indulo.dat fájlban tároljuk). A szkriptünkkel az aktuálisan futó folyamatokat tudjuk kezelni különböző kapcsolókkal.
   Az –start kapcsolóval indítsunk egy új folyamatot megadva az indítandó alkalmazás nevét - a szkript rendeljen hozzá egy PID számot is egy „S” státusszal együtt 
   és az így keletkezett új folyamattal bővítse az aktuálisan futó folyamatokat tartalmazó fájlt (aktualis.dat).
   A –stop kapcsolóval a PID számot megadva terminálja a folyamatot (a státusz a fájlban változzon S-ről T-re).
   A –kill kapcsolóra és a PID számra töröljük a fájlből a folyamatot!
   A –lista kapcsolóval listázzuk ki a folyamatokat.
 */
using System;
using static FileManager;

namespace ProcedureManager
{
    class Program
    {
        // Copy data from indulo.dat
        static void OnStartUp()
        {
            string[] startUpProcedures = File.ReadAllLines("indulo.dat");
            File.WriteAllText("aktualis.dat", string.Join("\n", startUpProcedures) + "\n");
        }

        // MAIN
        static void Main(string[] args)
        {
            // If aktualis.dat doesn't exist it means that the PC was just turned on.
            // So we copy the indulo.dat dprocedures to aktualis.dat.
            if (!File.Exists("aktualis.dat"))
            {
                OnStartUp();
            }

            if (args.Length <= 0)
            {
                Console.WriteLine("Incorrect usage of the application!");
                Console.WriteLine("Correct usage: -start, -stop, -kill, -lista");
                Environment.Exit(1);
            }

            FileManager fileManager = new FileManager("aktualis.dat");

            // -start
            if (args[0] == "-start" && args.Length == 2)
            {
                fileManager.AppendProcedure(args[1]);
            }
            // -stop
            else if (args[0] == "-stop" && args.Length == 2)
            {
                fileManager.StopProcedure(args[1]);
            }
            // -kill
            else if (args[0] == "-kill" && args.Length == 2)
            {
                fileManager.KillProcedure(args[1]);
            }
            // -lista
            else if (args[0] == "-lista" && args.Length == 1)
            {
                fileManager.ListProcedures();
            }
            else
            {
                Console.WriteLine($"Unknown flag: {args[0]}");
                Environment.Exit(1);
            }
        }
    }
}