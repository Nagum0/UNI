namespace NagyBea;

public class Puffancs : Plant {
    public Puffancs(string name, int sustenance) : base(name, sustenance) { }

    public override void Requests(Planet p) {
        p.EditAlpha(10);
        p.GetRadiation().Effect(this);
    }

    public override bool IsAlive() {
        if (sustenance > 10 || sustenance <= 0)
            return false;
        
        return true;
    }
}
