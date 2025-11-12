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

def do_calc(op, n, k):
    match op:
        case "IN":
            return k
        case "INCR":
            return n + k
        case "DECR":
            return n - k

SERVER_ADDR = ("localhost", 42069)
UNPACKER = struct.Struct("4s i")
n = 0

tcp_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp_server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
tcp_server.bind(SERVER_ADDR)
tcp_server.listen(5)

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
                    op, k = UNPACKER.unpack(data)
                    clients[s.fileno()] = True
                    print(f"Received operation from {s.fileno()}: {op.decode()} {k}")
                    n = do_calc(op.decode().strip("\x00"), n, k)

        for s in w:
            if (s is tcp_server) or (s.fileno() not in clients.keys()):
                pass
            elif clients[s.fileno()]:
                s.sendall(str(n).encode())
                clients[s.fileno()] = False
except KeyboardInterrupt:
    for s in sockets:
        s.close()
