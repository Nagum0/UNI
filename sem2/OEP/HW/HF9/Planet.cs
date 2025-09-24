namespace HF9;

public class Planet {
    private List<Starship> ships;
    public string name;

    public Planet(string name) {
        this.name = name;
        ships = new List<Starship>();
    }

    public void Defends(Starship s) {
        if (ships.Contains(s))
            throw new Exception();
        
        ships.Add(s);
    }

    public void Leaves(Starship s) {
        if (!ships.Contains(s))
            throw new Exception();
        
        ships.Remove(s);
    }

    public int ShipCount() {
        return ships.Count;
    }

    public int ShieldSum() {
        return ships.Sum(
            (ship) => ship.GetShield()
        );
    }

    public (bool, double, Starship) MaxFireP() {
        if (ships.Count == 0)
            return (false, 0.0, null);
        
        Starship s = ships.MaxBy(ship => ship.FireP());

        return (true, s.FireP(), s);
    }
}
