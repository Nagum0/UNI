import java.util.ArrayList;

class Main {
    public static void main(String[] args) {
        ThreadSafeMutableInteger n = new ThreadSafeMutableInteger();
        ArrayList<Thread> ths = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            Thread t = new Thread(() -> {
                for (int j = 1; j <= 10_000; j++) {
                    n.getAndInc();
                }
            });
            ths.add(t);
            t.start();
        }

        for (Thread t : ths) {
            try {
                t.join();
            } catch (Exception e) {
                System.exit(1);
            }
        }

        assert n.get() == 100_000 : "Should be 100_000_000";
    }
}
