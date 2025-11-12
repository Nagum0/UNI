import socket
import select
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
server.bind(("localhost", 42069))
server.listen(5)
print("Server listening on localhost:42069...")

sockets = [server]
clients = {}

try:
    while True:
        r, w, _ = select.select(sockets, sockets, sockets, 1)
        
        for s in r:
            if s is server:
                conn, conn_addr = server.accept()
                print(f"New connection from: {conn_addr}")
                clients[conn.fileno()] = None
                sockets.append(conn)
            else:
                data = s.recv(1024)
                if data:
                    unpacker = struct.Struct("i 1s i")
                    a, op, b = unpacker.unpack(data)
                    print(f"Client {s.fileno()} operation: {a} {op} {b}")
                    clients[s.fileno()] = (a, op.decode(), b)
                else:
                    print(f"Client {s.fileno()} disconnected")
                    del clients[s.fileno()]
                    sockets.remove(s)
                    r.remove(s)
                    w.remove(s)
                    s.close()
        
        for s in w:
            if s is server:
                pass
            else:
                if clients[s.fileno()] is None:
                    continue
                result = calc(*clients[s.fileno()])
                packer = struct.Struct("i")
                data = packer.pack(result)
                s.sendall(data)
                clients[s.fileno()] = None
except KeyboardInterrupt:
    for s in sockets:
        s.close()
    print("Closing server...")
