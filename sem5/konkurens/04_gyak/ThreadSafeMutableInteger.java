class ThreadSafeMutableInteger {
    private int n;

    public ThreadSafeMutableInteger() {
        n = 0;
    }

    public ThreadSafeMutableInteger(int n) {
        this.n = n;
    }

    synchronized int get() {
        return this.n;
    }

    synchronized void set(int n) {
        this.n = n;
    }

    synchronized int getAndInc() {
        int out = n;
        n++;
        return out;
    }
}
