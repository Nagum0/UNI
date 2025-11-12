import socket
import struct
import random
import time

SERVER_ADDR = ("localhost", 42070)
PACKER = struct.Struct("5s i")
OPS = ["PUSH", "PLUS", "MINUS"]

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

for i in range(0, 5):
    op = random.choice(OPS)
    k = random.randint(1, 11)
    data = PACKER.pack(op.encode(), k)
    sock.sendto(data, SERVER_ADDR)

    resp, _ = sock.recvfrom(1024)
    print(f"({i}) [{op} {k}] response from server: {resp.decode()}")

    time.sleep(1)

sock.close()
