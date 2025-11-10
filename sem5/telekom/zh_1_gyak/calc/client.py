import socket
import struct

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(("127.0.0.1", 42069))

a = int(input("a: "))
op = input("op: ")
b = int(input("b: "))

packer = struct.Struct("i 1s i")
data = packer.pack(a, op.encode(), b)
sock.sendall(data)

data = sock.recv(1024)
unpacker = struct.Struct("i")
unpacked_data = unpacker.unpack(data)
print(f"Result: {unpacked_data}")

sock.close()
