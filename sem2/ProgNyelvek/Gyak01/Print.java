public class Print {
    public static void main(String[] args) {
        // Feladat 5:
        for(float i = 1; i <= 4; i++) {
            System.out.println(i/2);
        }
        int i = 4;
        System.out.println("Kiirtam " + i + " szamot");

        // Feladat 6:
        String n_str = System.console().readLine();
        int n = Integer.parseInt(n_str);
        String k_str = System.console().readLine();
        int k = Integer.parseInt(k_str);

        for (float j = n; j < k; j++) {
            System.out.println(j / 2);
        }
    }
}