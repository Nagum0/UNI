public class Subordinate extends Emp {
    public Subordinate(String name, double salary) {
        setName(name);
        setSalary(salary);
    }

    @Override
    public double getSalary() {
        return salary;
    }
}
