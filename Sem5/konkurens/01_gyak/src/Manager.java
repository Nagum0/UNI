import java.util.ArrayList;

public class Manager extends Emp {
    private ArrayList<Emp> emps;

    public Manager() {
        emps = new ArrayList<>();
    }

    public void addEmp(Emp emp) {
        emps.add(emp);
    }

    public void removeEmp(Emp emp) {
        emps.remove(emp);
    }

    @Override
    public double getSalary() {
        double bonus = 0;
        for (Emp emp : emps) {
            bonus += emp.getSalary() * 0.05;
        }

        return salary + bonus;
    }
}
