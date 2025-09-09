import java.util.ArrayList;

public class Company {
    private ArrayList<SalariedEntity> emps;

    public Company() {
        emps = new ArrayList<>();
    }

    public void addEmp(SalariedEntity emp) {
        emps.add(emp);
    }

    public void removeEmp(SalariedEntity emp) {
        emps.remove(emp);
    }

    public void raiseSalaries(double percent) {
        for (SalariedEntity emp : emps) {
            if (emp instanceof Emp) {
                ((Emp) emp).raiseSalary(percent);
            }
        }
    }
}
