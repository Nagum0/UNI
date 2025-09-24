using System.Net.Http;

namespace ImageDownloader.Model
{
    public class WebImage
    {
        private byte[] _data;
        private Uri _url;

        protected WebImage(byte[] data, Uri url)
        {
            _data = data;
            _url = url;
        }

        public static async Task<WebImage> DownloadAsync(Uri url) 
        {
            if (url == null)
                throw new Exception("URL must be not be null");

            if (!url.IsAbsoluteUri)
                throw new Exception("URL must be an absolute");

            HttpClient client = new HttpClient();
            byte[] data = await client.GetByteArrayAsync(url);

            return new WebImage(data, url);
        }

        public byte[] Data
        { 
            get => _data;
        }

        public Uri Url 
        { 
            get => _url; 
        }
    }
}
