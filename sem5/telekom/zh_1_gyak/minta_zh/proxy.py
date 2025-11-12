import socket
import select
import struct

def client_new(server, sockets, clients):
    conn, addr = server.accept()
    print(f"New connection from {addr}")

    sockets.append(conn)
    clients[conn.fileno()] = None

def client_disconnect(s, sockets, clients):
    del clients[s.fileno()]
    sockets.remove(s)
    s.close()

def transform_op(op) -> str:
    match op:
        case "IN":
            return "PUSH"
        case "INCR":
            return "PLUS"
        case "DECR":
            return "MINUS"

    return ""

SERVER_ADDR = ("localhost", 42069)
UDP_SERVER_ADDR = ("localhost", 42070)
UNPACKER = struct.Struct("4s i")
UDP_PACKER = struct.Struct("5s i")

tcp_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp_server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
tcp_server.bind(SERVER_ADDR)
tcp_server.listen(5)
print("TCP proxy running...")

udp_conn = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
print("Connected to UDP server")

sockets = [tcp_server]
clients = {}

try:
    while True:
        r, w, _ = select.select(sockets, sockets, [], None)

        for s in r:
            if s is tcp_server:
                client_new(tcp_server, sockets, clients)
            else:
                data = s.recv(UNPACKER.size)
                if not data:
                    client_disconnect(s, sockets, clients)
                else:
                    # Reading from TCP client
                    op, k = UNPACKER.unpack(data)
                    op = op.decode().strip("\x00")
                    print(f"Received operation from {s.fileno()}: {op} {k}")
                    op = transform_op(op)
                    print(f"Transformed operation for UDP server: {op} {k}")
                    
                    # Sending to UDP server
                    data = UDP_PACKER.pack(op.encode(), k)
                    udp_conn.sendto(data, UDP_SERVER_ADDR)
                    udp_resp, _ = udp_conn.recvfrom(1024)
                    clients[s.fileno()] = (True, udp_resp)
        for s in w:
            if (s is tcp_server) or (s.fileno() not in clients.keys()):
                pass
            elif clients[s.fileno()][0]:
                s.sendall(clients[s.fileno()][1])
                clients[s.fileno()] = (False, b"")
except KeyboardInterrupt:
    for s in sockets:
        s.close()
