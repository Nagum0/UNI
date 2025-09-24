namespace NagyBea;

public class Parabokor : Plant {
    public Parabokor(string name, int sustenance) : base(name, sustenance) { }

    public override void Requests(Planet p) {
        p.GetRadiation().Effect(this);
    }
}
