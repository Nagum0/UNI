namespace HF10;

public class AmPark {
    private List<TargetShot> targetShots;
    private List<Guest> guests;

    public AmPark(List<TargetShot> targetShots) {
        if (targetShots.Count < 2)
            throw new Exception("Not enough targets!");

        this.targetShots = targetShots.Select((t) => t).ToList();
        guests = new List<Guest>();
    }

    public string Best(TargetShot t) {
        if (guests.Count == 0)
            throw new Exception("No guests!");

        return guests.MaxBy((g) => g.Result(t)).getName();
    }

    public void Receives(Guest g) {
        if (guests.Contains(g))
            throw new Exception("Guest already in park!");

        guests.Add(g);
    }
}
