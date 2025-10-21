import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ("localhost", 42069)
sock.bind(server_address)

sock.listen(1)

connection, client_address = sock.accept()
print(f"New connection: {client_address}")

connection.sendall("Hello, Client!".encode())

data = connection.recv(16).decode()
print("Received from client: " + data)

connection.close()
sock.close()
