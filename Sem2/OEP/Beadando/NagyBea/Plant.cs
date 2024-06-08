namespace NagyBea;

public class Plant {
    protected string name;
    protected int sustenance;

    protected Plant(string name, int sustenance) {
        this.name = name;
        this.sustenance = sustenance;
    }
    
    public int Sustenance {
        get => sustenance;
    }

    public virtual void Requests(Planet p) { }

    public virtual bool IsAlive() {
        return sustenance > 0;
    }

    public void EditSustenance(int n) {
        sustenance += n;
    }

    public override string ToString() {
        return $"[{name}] {sustenance}";
    }
}
