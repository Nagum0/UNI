public class Program {
    public static void foo(String arg) {
        if (arg == null) {
            throw new IllegalArgumentException("Null arg!");
        }
    }

    public static void main(String args[]) {
        foo(null);
    }   
}
