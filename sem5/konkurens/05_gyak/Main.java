import java.util.ArrayList;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.TimeUnit;

class Main {
    static final int LIMIT = 10_000;
    static final int CUSTOMER_COUNT = 5;

    static int getCustomersLoanSum(ArrayList<Customer> customers) {
        int sum = 0;

        for (Customer c : customers) {
            sum += c.getLoan();
        }

        return sum;
    }

    static void v1() {
        Bank bank = new Bank();
        ArrayList<Customer> customers = new ArrayList<>();

        ExecutorService exec;
        exec = Executors.newFixedThreadPool(CUSTOMER_COUNT);

        for (int i = 0; i < CUSTOMER_COUNT; i++) {
            customers.add(i, new Customer(bank));
            final int k = i;

            exec.submit(() -> {
                for (int j = 0; j < LIMIT; j++) {
                    int loan = ThreadLocalRandom.current().nextInt(100, 1000);
                    customers.get(k).addLoan(loan);
                }
            });
        }

        exec.shutdown();

        try {
            exec.awaitTermination(5, TimeUnit.SECONDS);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            System.exit(1);
        }

        int sum = getCustomersLoanSum(customers);
        assert bank.getLoan() == sum : "Expected " + bank.getLoan();
        System.out.println(bank.getLoan() + ", " + sum);
    }

    static void v2() {
        Bank bank = new Bank();
        ArrayList<Future<Integer>> results = new ArrayList<>();
        ExecutorService exec = Executors.newFixedThreadPool(CUSTOMER_COUNT);

        Callable<Integer> func = () -> {
            int sum = 0;

            for (int j = 0; j < LIMIT; j++) {
                int loan = ThreadLocalRandom.current().nextInt(100, 1000);
                sum += loan;
                bank.addLoan(loan);
            }

            return sum;
        };

        for (int i = 0; i < CUSTOMER_COUNT; i++) {
            Future<Integer> result = exec.submit(func);
            results.add(result);
        }

        int sum = 0;
        for (Future<Integer> result : results) {
            try {
                sum += result.get();
            } catch (Exception e) {
                System.out.println(e.getMessage());
                System.exit(1);
            }
        }

        exec.shutdown();

        assert bank.getLoan() == sum : "Expected " + bank.getLoan();
        System.out.println(bank.getLoan() + ", " + sum);
    }

    public static void main(String[] args) {
        v2();
    }
}
