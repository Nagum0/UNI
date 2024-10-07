namespace Persistance
{
    public class FileManagerException : IOException
    {
        public FileManagerException(string message, Exception ex) : base(message, ex) { } 
    }
}
