import java.util.ArrayList;

public class Main {
    // Sum numbers up to 1_000_000_000
    static long sum = 0;
    final static int THREAD_COUNT = 10;
    final static long partition = 100_000_000;

    public static void main(String[] args) {
        ArrayList<Thread> counters = new ArrayList<>();
        ArrayList<Long> partitions = new ArrayList<>();
        
        for (int i = 0; i < THREAD_COUNT; i++) {
            final int c = i;

            counters.add(new Thread(() -> {
                long part = 0;
                long start = c * partition + 1;
                long end = (c + 1) * partition;

                System.out.printf("%d: %d -> %d\n", c, start, end);
                
                for (long j = start; j < end; j++) {
                    part += j;
                }
                
                synchronized (partitions) {
                    partitions.add(part);
                }
            }));

            counters.getLast().start();
        }

        for (Thread t : counters) {
            try {
                t.join();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }

        for (long part : partitions) {
            sum += part;
        }

        System.out.println(sum);
    }
}


