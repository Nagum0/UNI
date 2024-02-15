public class Calc {
    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println("Expected 3 arguments!");
            return;
        }

        int n = Integer.parseInt(args[0]);
        int k = Integer.parseInt(args[2]);
        String op = args[1];

        if (op == "+") {
            System.out.println(n + k);
        }
    }
}