import javax.swing.*;
import java.awt.*;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;

public class FractalTree extends Canvas {
    public static class FractalTreeData {
        private int x;
        private int y;
        private int x2;
        private int y2;
        private Color color;

        public FractalTreeData(int x, int y, int x2, int y2, Color color) {
            this.x = x;
            this.y = y;
            this.x2 = x2;
            this.y2 = y2;
            this.color = color;
        }
    }

    /* Variables with class-wide visibility */
    private static boolean slowMode;
    private static ArrayBlockingQueue<FractalTreeData> dataQue = new ArrayBlockingQueue<FractalTreeData>(128);
    private static ExecutorService exec = Executors.newFixedThreadPool(128);
    private static Object lock = new Object();
    private static AtomicInteger counter = new AtomicInteger(0);

    /* Recursive function for calculating all drawcalls for the fractal tree */
    private void makeFractalTree(int x, int y, int angle, int height) {
        if (slowMode) {
            try {Thread.sleep(100);}
            catch (InterruptedException ie) {ie.printStackTrace();}
        }

        if (height == 0) {
            counter.decrementAndGet();
            synchronized (lock) {
                lock.notifyAll();
            }
            return;
        }

        int x2 = x + (int)(Math.cos(Math.toRadians(angle)) * height * 8);
        int y2 = y + (int)(Math.sin(Math.toRadians(angle)) * height * 8);
        Color color = Color.BLACK;
        if (height < 5) color = Color.GREEN;
        
        try {
            FractalTreeData data = new FractalTreeData(x, y, x2, y2, color);
            dataQue.put(data);
        } catch (InterruptedException e) {
            System.err.println("Error while calculating fractal tree data...");
            System.exit(1);
        }
        
        counter.incrementAndGet();
        exec.submit(() -> {
            makeFractalTree(x2, y2, angle-20, height-1);
        });

        counter.incrementAndGet();
        exec.submit(() -> {
            makeFractalTree(x2, y2, angle+20, height-1);
        });

        counter.decrementAndGet();
        synchronized (lock) {
            lock.notifyAll();
        }
    }

    /* Code for EDT */
    /* Must only contain swing code (draw things on the screen) */
    /* Must not contain calculations (do not use math and compute libraries here) */
    /* No need to understand swing, a simple endless loop that draws lines is enough */
    @Override
    public void paint(Graphics g) {
        while(true) {
            try {
                FractalTreeData data = dataQue.take();
                g.setColor(data.color);
                g.drawLine(data.x, data.y, data.x2, data.y2);
            } catch (InterruptedException e) {
                System.err.println("Error while drawing fractal tree data...");
                System.exit(1);
            }
        }
    }

    /* Code for main thread */
    public static void main(String args[]) {
        /* Parse args */
        slowMode = args.length != 0 && Boolean.parseBoolean(args[0]);

        /* Initialize graphical elements and EDT */
        FractalTree tree = new FractalTree();
        JFrame frame = new JFrame();
        frame.setSize(800,600);
        frame.setVisible(true);
        frame.add(tree);

        counter.incrementAndGet();
        exec.submit(() -> { 
            tree.makeFractalTree(390, 480, -90, 10);
        });

        synchronized (lock) {
            while (counter.get() != 0) {
                try {
                    lock.wait();
                } catch (InterruptedException e) {
                    System.err.println("Error while waiting for calculations...");
                    System.exit(1);
                }
            }
        }
        
        exec.shutdown();

        /* Log success as last step */
        System.out.println("Main has finished");
    }
}
