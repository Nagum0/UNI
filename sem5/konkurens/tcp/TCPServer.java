import java.net.*;
import java.io.*;

class TCPServer {
    public final int port;

    public TCPServer(int port) {
        this.port = port;
    }

    public void start() {
        try {
            ServerSocket server = new ServerSocket(port);
            System.out.printf("Server listening on port %d\n", port);
    
            Socket client = server.accept();
            System.out.println("Connection from: " + client.getInetAddress());

            OutputStream output = client.getOutputStream();
            PrintWriter writer = new PrintWriter(output, true);
            writer.println("Hello client!");

            InputStream input = client.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));
            System.out.println(reader.readLine());

            client.close();
            server.close();
        } catch (Exception e) {
            System.out.println(e.getStackTrace());
        }
    }
}
