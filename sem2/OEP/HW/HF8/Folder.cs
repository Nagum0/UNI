namespace HF8;

public class Folder : Registration {
    private List<Registration> items;

    public Folder() {
        items = new List<Registration>();
    }

    public override int GetSize() {
        return items.Sum(item => item.GetSize());    
    }

    public void Add(Registration r) {
        items.Add(r);
    }

    public void Remove(Registration r) {
        items.Remove(r);
    }
}
