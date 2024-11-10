using System.Net.Http;

namespace ImageDownloader.Model
{
    public class WebPage
    {
        private Uri _baseUrl;
        private List<WebImage> _images;
        public event EventHandler<WebImage>? ImageLoaded;
        public event EventHandler<int>? LoadProgress;

        public WebPage(Uri baseUrl)
        {
            if (baseUrl == null)
                throw new Exception("BaseURL must not be null");

            if (!baseUrl.IsAbsoluteUri)
                throw new Exception("BaseURL must be absolute");

            _baseUrl = baseUrl;
            _images = new List<WebImage>();
        }

        public async Task LoadImageAsync()
        {
            HttpClient client = new HttpClient();
            HttpResponseMessage res = await client.GetAsync(_baseUrl);
            string content = await res.Content.ReadAsStringAsync();

            HtmlAgilityPack.HtmlDocument doc = new HtmlAgilityPack.HtmlDocument();
            doc.LoadHtml(content);

            var imgNodes = doc.DocumentNode.SelectNodes("//img");

            foreach (var img in imgNodes)
            {
                if (!img.Attributes.Contains("src"))
                    continue;

                Uri imgUrl = new Uri(img.Attributes["src"].Value, UriKind.RelativeOrAbsolute);
                if (!imgUrl.IsAbsoluteUri)
                    imgUrl = new Uri(_baseUrl, imgUrl);

                try
                {
                    WebImage image = await WebImage.DownloadAsync(imgUrl);
                    _images.Add(image);
                    ImageLoaded?.Invoke(this, image);
                }
                catch
                {
                    continue;
                }

                LoadProgress?.Invoke(this, (int)((_images.Count / (double)imgNodes.Count) * 100));
            }
        }

        public Uri BaseUrl
        {
            get => _baseUrl;
        }

        public ICollection<WebImage> Images
        {
            get => _images;
        }

        public int ImageCount
        {
            get => _images.Count;
        }
    }
}
