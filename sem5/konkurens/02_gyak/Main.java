import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

class Main {
    static final long MAX_NUM = 1_000_000_000;
    static final long CHUNK = 100_000_000;
    static long n = 0;

    static long singleThreaded() {
        long start = System.nanoTime();
        long sum = 0;

        for (int i = 1; i <= MAX_NUM; i++) {
            sum += i;
        }
        
        System.out.println(sum);

        return System.nanoTime() - start;
    }

    static long multiThreaded() {
        long start = System.nanoTime();
        ArrayList<Thread> ts = new ArrayList<>();
        ArrayList<Long> chunks = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            final int j = i;

            Thread t = new Thread(() -> {
                long chunk = 0;
                long begin = CHUNK * j + 1;
                long end = CHUNK * (j + 1);

                System.out.printf("(%d) %d -> %d\n", j, begin, end);

                for (long k = begin; k <= end; k++) {
                    chunk += k;
                }

                chunks.add(chunk);
            });

            ts.add(t);
            t.start();
        }

        for (Thread t : ts) {
            try {
                t.join();
            } catch (Exception e) {
                System.exit(1);
            }
        }

        for (long m : chunks) n += m;
        
        System.out.println(n);

        return System.nanoTime() - start;
    }

    public static void main(String[] args) {
        long t1 = singleThreaded();
        long t1Ms = TimeUnit.NANOSECONDS.toMillis(t1);
        System.out.println(t1Ms + " ms");

        long t2 = multiThreaded();
        long t2Ms = TimeUnit.NANOSECONDS.toMillis(t2);
        System.out.println(t2Ms + " ms");
    }
}
