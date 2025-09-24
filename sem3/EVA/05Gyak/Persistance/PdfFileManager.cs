using iText.Kernel.Pdf;
using iText.Kernel.Pdf.Canvas.Draw;
using iText.Kernel.Pdf.Canvas.Parser;
using System.Text;

namespace Persistance
{
    public class PdfFileManager : IFileManager
    {
        private readonly string _path;

        public PdfFileManager(string path)
        {
            _path = path;
        }

        public string Load()
        {
            try
            {
                using PdfReader reader = new PdfReader(_path);
                using PdfDocument document = new PdfDocument(reader);
                StringBuilder sbr = new StringBuilder();

                for (int i = 0; i < document.GetNumberOfPages(); i++)
                {
                    PdfPage page = document.GetPage(i);
                    sbr.Append(PdfTextExtractor.GetTextFromPage(page));
                }

                return sbr.ToString();
            }
            catch (Exception ex)
            {
                throw new FileManagerException(ex.Message, ex);
            }
        }
    }
}
