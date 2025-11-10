import socket
import struct

def calc(a, op, b) -> int:
    match op:
        case "+":
            return a + b
        case "-":
            return a - b
        case "*":
            return a * b
        case "/":
            return a // b

    return 0

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("127.0.0.1", 42069))
server.listen(1)

conn, conn_addr = server.accept()
print(f"Connection from {conn_addr}")

data = conn.recv(1024)
unpacker = struct.Struct("i 1s i")
unpacked_data = unpacker.unpack(data)
a, op, b = unpacked_data
print(f"Received operation from client: {a} {op.decode()} {b}")
result = calc(a, op.decode(), b)

packer = struct.Struct("i")
data = packer.pack(result)
conn.sendall(data)

conn.close()
server.close()
