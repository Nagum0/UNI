import java.util.ArrayList;

class Main {
    static final int N = 1_000_000;

    public static void main(String[] args) {
        ArrayList<Integer> xs = new ArrayList<>();

        Thread t1 = new Thread(() -> {
            for (int i = 1; i <= N; i++) {
                if (i % 2 == 0) {
                    synchronized (xs) {
                        xs.add(i);
                    }
                }
            }
        });
        t1.start();

        Thread t2 = new Thread(() -> {
            for (int i = 1; i <= N; i++) {
                if (i % 2 != 0) {
                    synchronized (xs) {
                        xs.add(i);
                    }
                }
            }
        });
        t2.start();
        
        try {
            t1.join();
            t2.join();
        } catch (Exception e) {
            System.exit(1);
        }
        
        assert xs.size() == N : "Size must be " + N;
    }
}
