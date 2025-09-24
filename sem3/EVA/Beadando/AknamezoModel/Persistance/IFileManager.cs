using AknamezoModel.Model;

namespace AknamezoModel.Persistance
{
    public interface IFileManager
    {
        void Save(GameState gameState, string filePath);
        GameState Load(string filePath);
    }
}
