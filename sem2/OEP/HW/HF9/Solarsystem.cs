namespace HF9;

public class Solarsystem {
    public List<Planet> planets;

    public Solarsystem() {
        planets = new List<Planet>();
    }

    public (bool, Starship) MaxFireP() {
        if (planets.Count == 0 || planets.Sum(p => p.ShipCount()) == 0)
            return (false, null);
        
        Starship s = planets.MaxBy(p => p.MaxFireP().Item2).MaxFireP().Item3;

        return (true, s);
    }

    public List<Planet> Defenseless() {
        return (List<Planet>) planets.Where(p => p.ShipCount() == 0);
    }
}