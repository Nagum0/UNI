namespace NagyBea;

public class Deltafa : Plant {
    public Deltafa(string name, int sustenance) : base(name, sustenance) { }

    public override void Requests(Planet p) {
        if (sustenance < 5)
            p.EditDelta(4);
        else if (5 <= sustenance && sustenance < 10)
            p.EditAlpha(1);
        
        p.GetRadiation().Effect(this);
    }
}
