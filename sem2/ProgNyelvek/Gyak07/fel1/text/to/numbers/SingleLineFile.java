package text.to.numbers;

import java.io.*;

public class SingleLineFile {
    public static int addNumbers(String path) throws IOException {
        int sum = 0;

        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String firstLine = br.readLine();
            String words[] = firstLine.split(" ");

            for (String s : words) {
                try {
                    int n = Integer.parseInt(s);
                    sum += n;
                }
                catch (Exception e) {
                    System.err.println(s);
                }
            }
        }

        System.out.println("dada");

        return sum;
    }
}