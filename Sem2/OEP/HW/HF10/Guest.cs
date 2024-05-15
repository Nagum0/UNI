namespace HF10;

public class Guest {
    private string name;
    private List<Gift> prizes;

    public Guest(string name) {
        this.name = name;
        prizes = new List<Gift>();
    }

    public string getName() {
        return name;
    }

    public void Wins(Gift g) {

    }

    public int Result(TargetShot t) {
        return prizes.Sum((e) => {
            if (e.targetShot == t)
                return e.Value();
            else
                return 0;
        });
    }
}
