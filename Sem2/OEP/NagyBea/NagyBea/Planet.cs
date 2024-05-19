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

    public void Day() {
        foreach (Plant plant in plants) {
            Console.WriteLine(plant.ToString());
            plant.Requests(this);
        }
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

    public void ChangeSugar() {
        if (alpha - delta >= 3)
            radiation = new Alpha();
        else if (delta - alpha >= 3)
            radiation = new Delta();
        else
            radiation = new None();
    }
}
