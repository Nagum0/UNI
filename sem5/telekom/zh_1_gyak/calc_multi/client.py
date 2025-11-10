import socket
import random
import struct
import time

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(("localhost", 42069))

ops = ["+", "-", "*", "/"]

for i in range(0, 5):
    a = random.randint(1, 20)
    op = random.choice(ops)
    b = random.randint(1, 20)
    
    packer = struct.Struct("i 1s i")
    data = packer.pack(a, op.encode(), b)
    sock.sendall(data)
    print(f"({i}) sent operation: {a} {op} {b}")

    data = sock.recv(1024)
    unpacker = struct.Struct("i")
    result = unpacker.unpack(data)
    print(f"({i}) result: {result[0]}")
    
    time.sleep(2)

sock.close()
