import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ("localhost", 42069)
sock.connect(server_address)

sock.sendall("Hello, Server!".encode())

data = sock.recv(16).decode()
print("Received from server: " + data)

sock.close()
