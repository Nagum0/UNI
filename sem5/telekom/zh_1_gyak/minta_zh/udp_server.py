import socket
import struct

def do_calc(n, op, k) -> int:
    match op:
        case "PUSH":
            return k
        case "PLUS":
            return n + k
        case "MINUS":
            return n - k

    return 0

SERVER_ADDR = ("localhost", 42070)
UNPACKER = struct.Struct("5s i")
n: int = 0

udp_server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
udp_server.bind(SERVER_ADDR)
print(f"UDP server listening on {SERVER_ADDR}...")

try:
    while True:
        data, addr = udp_server.recvfrom(UNPACKER.size)
        print(f"Received data from {addr}")
        op, k = UNPACKER.unpack(data)
        print(f"Calculation to be done [{op} {k}]")
        n = do_calc(n, op.decode().strip("\x00"), k)
        udp_server.sendto(str(n).encode(), addr)
        print(n)
except KeyboardInterrupt:
    udp_server.close()
    print("Shutting down UDP server...")
