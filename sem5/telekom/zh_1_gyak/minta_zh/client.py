import socket
import struct
import random
import time

SERVER_ADDR = ("localhost", 42069)
PACKER = struct.Struct("4s i")
OPS = ["IN", "INCR", "DECR"]

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(SERVER_ADDR)

for i in range(0, 5):
    op = random.choice(OPS)
    k = random.randint(1, 11)
    data = PACKER.pack(op.encode(), k)
    sock.sendall(data)

    resp = sock.recv(1024)
    print(f"({i}) [{op} {k}] response from server: {resp.decode()}")

    time.sleep(1)

sock.close()
