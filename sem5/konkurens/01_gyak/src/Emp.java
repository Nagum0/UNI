public abstract class Emp implements SalariedEntity {
    private String name;
    protected double salary;

    public String getName() {
        return name;
    }

    public abstract double getSalary();

    public void setName(String name) {
        this.name = name;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public void raiseSalary(double percent) {
        this.salary += this.salary * percent;
    }
}
