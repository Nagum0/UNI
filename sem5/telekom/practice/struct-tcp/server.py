import socket
import logging

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ("127.0.0.1", 42069)
server.bind(server_address)

connections = []

try:
    while True:
        conn, conn_address = server.accept()
        connections.append(conn)
        logging.info(f"New connection: {conn_address}")

        for c in connections:
            pass
except KeyboardInterrupt:
    print("Closing server...")
    exit(0)
