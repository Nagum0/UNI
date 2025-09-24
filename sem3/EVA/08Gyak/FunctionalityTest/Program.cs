using ImageDownloader.Model;

namespace FunctionalityTest
{
    public class Program
    {
        static async Task Main(string[] args)
        {
            WebPage page = new WebPage(new Uri("https://rule34.xxx/index.php?page=post&s=list&tags=furina_%28genshin_impact%29+"));
            page.LoadProgress += HandleLoadProgress;
            page.ImageLoaded += HandleImageLoaded;
            await page.LoadImageAsync();
        }

        static void HandleLoadProgress(object? sender, int progress)
        {
            Console.WriteLine($"Progress: {progress}");
        }

        static void HandleImageLoaded(object? sender, WebImage img)
        {
            Console.WriteLine($"Image loaded: {img.Url}");
        }
    }
}
