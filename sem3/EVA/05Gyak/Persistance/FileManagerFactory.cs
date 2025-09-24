namespace Persistance
{
    public static class FileManagerFactory
    {
        public static IFileManager? CreateForPath(string path)
        {
            string extenstion = Path.GetExtension(path);

            switch (extenstion)
            {
                case ".txt":
                    return new TextFileManager(path);
                case ".pdf":
                    return new PdfFileManager(path);
                default:
                    return null;
            }
        }
    }
}
