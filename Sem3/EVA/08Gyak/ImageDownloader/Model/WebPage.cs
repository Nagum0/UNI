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
            throw new NotImplementedException();
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
