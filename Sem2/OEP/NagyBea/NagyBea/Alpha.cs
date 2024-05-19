namespace NagyBea;

public class Alpha : Radiation {
    public void Effect(Puffancs p) {
        p.EditSustenance(2);
    }
    
    public void Effect(Parabokor p) {
        p.EditSustenance(1);
    }

    public void Effect(Deltafa p) {
        p.EditSustenance(-3);
    }
}
