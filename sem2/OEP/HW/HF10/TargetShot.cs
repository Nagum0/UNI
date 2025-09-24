namespace HF10;

public class TargetShot {
    private string site;
    private List<Gift> gifts;

    public TargetShot(string site) {
        this.site = site;
        gifts = new List<Gift>();
    }

    public List<Gift> GetGifts() {
        return gifts;
    }

    public void Shows(Gift g) {
        if (g.targetShot != null || gifts.Contains(g))
            throw new Exception("...");

        g.targetShot = this;
        gifts.Add(g);
    }
}
