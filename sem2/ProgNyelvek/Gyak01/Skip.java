public class Skip {
    public static void main(String[] args) {
        // Feladat 3:
        String name = System.console().readLine();
        System.console().printf("Hello, " + name + "!\n");

        // Feladat 4:
        System.out.println("Hello, " + args[0] + "!");

        String n = System.console().readLine();
        int k = Integer.parseInt(n);
        for (int i = 1; i <= 10; i++) {
            System.out.println((k * i));
        }
    }
}