import socket
import select

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_addr = ("127.0.0.1", 42069)
server.bind(server_addr)
server.listen(3)

sockets = [server]

try: 
    while True:
        r, _, e = select.select(sockets, [], sockets, None)
        for s in r:
            if s is server:
                conn, addr = server.accept()
                print(f"New connection at from {addr}")
                sockets.append(conn)
            else:
                data = s.recv(1024)
                if data:
                    print(f"Received from client: {data.decode()}")
                    s.sendall(b"Echo from server: " + data)
                else:
                    sockets.remove(s)
                    s.close()
except KeyboardInterrupt:
    print("Closing server...")
    for s in sockets:
        s.close()
