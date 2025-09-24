using System.IO;

public class FileManager
{
    /* -- CONSTRUCTOR -- */

    // The name of the file in which the class is working in.
    private string file;

    public FileManager(string fileName)
    {
        this.file = fileName;
    }

    /* -- PRIVATE -- */

    // Procedure struct for the StopProcedure and KillProcedure methods.
    private struct Procedure
    {
        public string name;
        public string pid;
        public string status;
    }

    // Returns all the procedures parsed into a Procedure struct.
    private Procedure[] getProcedures()
    {
        string[] processes = File.ReadAllLines(this.file);
        Procedure[] procedures = new Procedure[processes.Length];

        for (int i = 0; i < processes.Length; i++)
        {
            string line = processes[i];
            procedures[i].name = line.Split(" ")[0];
            procedures[i].pid = line.Split(" ")[1];
            procedures[i].status = line.Split(" ")[2];
        }
           
        return procedures;
    }

    // Checks whether the input PID exists or not.
    private bool pidExists(string pid)
    {
        Procedure[] procedures = getProcedures();

        foreach (Procedure procedure in procedures)
        {
            if (procedure.pid == pid)
            {
                return true;
            }
        }

        return false;
    }

    /* -- STATIC -- */

    // Generates a PID for a procedure.
    static string generatePID()
    {
        string pidString = string.Empty;

        Random rnd = new Random();

        int pidLength = rnd.Next(4, 8);

        for (int i = 0; i < pidLength; i++)
        {
            pidString += rnd.Next(1, 9).ToString();
        }

        return pidString;
    }

    /* -- PUBLIC -- */

    // Appends new procedure to the aktualis.dat file.
    // If it doesn't exist it creates it.
    public void AppendProcedure(string procedureName)
    {
        string pid = generatePID();
        string status = "S";
        string append = $"{procedureName} {pid} {status}";

        using (StreamWriter sw = File.AppendText(this.file))
        {
            sw.WriteLine(append);
        }
    }

    // Stops a procedure.
    // Changes the status from S to T in the `aktualis.dat` file.
    public void StopProcedure(string pid)
    {
        Procedure[] procedures = getProcedures();
        string changedProcedures = string.Empty;
        
        if (!pidExists(pid))
        {
            Console.WriteLine($"PID {pid} was not found.");
            Environment.Exit(1);
        }

        for (int i = 0; i < procedures.Length; i++)
        {
            string currentLine = string.Empty;

            if (procedures[i].pid == pid)
            {
                currentLine = $"{procedures[i].name} {procedures[i].pid} T\n";
            }
            else
            {
                currentLine = $"{procedures[i].name} {procedures[i].pid} {procedures[i].status}\n";
            }

            changedProcedures += currentLine;
        }

        File.WriteAllText(this.file, changedProcedures);
    }

    // Kill the procedure.
    // Deletes the specific line from the file.
    public void KillProcedure(string pid)
    {
        Procedure[] procedures = getProcedures();
        string changedProcedures = string.Empty;

        if (!pidExists(pid))
        {
            Console.WriteLine($"PID {pid} was not found.");
            Environment.Exit(1);
        }

        for (int i = 0; i < procedures.Length; i++)
        {
            string currentLine = string.Empty;

            if (procedures[i].pid != pid)
            {
                currentLine = $"{procedures[i].name} {procedures[i].pid} {procedures[i].status}\n";
            }

            changedProcedures += currentLine;
        }

        File.WriteAllText(this.file, changedProcedures);
    }

    // Prints out all of the active procedures.
    public void ListProcedures()
    {
        Procedure[] procedures = getProcedures();

        foreach (Procedure procedure in procedures)
        {
            Console.WriteLine($"{procedure.name}\t{procedure.pid}\t{procedure.status}");
        }
    }
}