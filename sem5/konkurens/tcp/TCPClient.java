import java.io.*;
import java.net.*;

public class TCPClient {
    public static void main(String[] args) {
        String hostname = "127.0.0.1";
        int port = 8080;

        try (Socket socket = new Socket(hostname, port)) {
            InputStream input = socket.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));

            OutputStream out = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(out, true);
            writer.println("Hello, Server!");

            String message = reader.readLine();
            System.out.println("Received: " + message);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
