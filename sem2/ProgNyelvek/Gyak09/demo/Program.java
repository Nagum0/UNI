import java.util.HashSet;

class Program {

    private static String readLine() {
        return System.console().readLine();
    }

    public static void main(String[] args) {
    
        HashSet<String> osztaly = new HashSet<String>();

        osztaly.add(readLine());
        osztaly.add(readLine());
        osztaly.add(readLine());

        if (osztaly.contains("Zeki")) {
            System.out.println("My class!");
        }

    }
}