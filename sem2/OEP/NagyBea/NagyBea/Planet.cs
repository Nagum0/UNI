namespace NagyBea;

public class Planet {
    private List<Plant> plants;
    private Radiation radiation;
    private int alpha;
    private int delta;

    public Planet(List<Plant> plants) {
        this.plants = plants.Select(p => p).ToList();
        radiation = new None();
    }

    public int Alpha {
        get => alpha;
    }

    public int Delta {
        get => delta;
    }

    public void Day() {
        foreach (Plant plant in plants) {
            Console.WriteLine($"{plant}; [{radiation}] alpha: {alpha} delta: {delta}");

            if (plant.IsAlive())
                plant.Requests(this);
        }

        ChangeRadiation();
    }

    public List<Plant> GetPlants() {
        return plants.Select(p => p).ToList();
    }

    public Radiation GetRadiation() {
        return radiation;
    }

    public void EditAlpha(int n) {
        alpha += n;
    }

    public void EditDelta(int n) {
        delta += n;
    }

    public void ChangeRadiation() {
        if (alpha - delta >= 3)
            radiation = new Alpha();
        else if (delta - alpha >= 3)
            radiation = new Delta();
        else
            radiation = new None();
    }

    public Plant StrongestPlant() {
        return plants.MaxBy(p => p.IsAlive());
    }
}
