import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_addr = ("127.0.0.1", 42069)
server.bind(server_addr)

server.listen(1)

conn, conn_addr = server.accept()
print(f"New connection: {conn_addr}")

conn.close()
server.close()
