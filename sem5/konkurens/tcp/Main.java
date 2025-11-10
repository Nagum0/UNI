class Main {
    public static void main(String[] args) {
        TCPServer server = new TCPServer(8080);
        server.start();
    }
}
