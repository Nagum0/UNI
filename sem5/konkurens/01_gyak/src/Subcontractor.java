public class Subcontractor implements SalariedEntity {
    private double salary;
    private long taxNumber;

    public Subcontractor(double salary, long taxNumber) {
        this.salary = salary;
        this.taxNumber = taxNumber;
    }

    @Override
    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public long getTaxNumber() {
        return taxNumber;
    }

    public void setTaxNumber(long taxNumber) {
        this.taxNumber = taxNumber;
    }
}
