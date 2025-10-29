import socket
import select

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_addr = ("127.0.0.1", 42069)
server.bind(server_addr)
server.listen(3)

sockets = [server]
clients = {}
messages = {}

try: 
    while True:
        r, w, _ = select.select(sockets, sockets, sockets, None)

        # Read messages
        for s in r:
            if s is server:
                conn, addr = server.accept()
                print(f"New connection from {addr}")
                sockets.append(conn)
                clients[conn] = addr
                messages[conn] = None
            else:
                data = s.recv(1024)

                if data:
                    text = data.decode().strip()
                    client = clients[s]
                    msg = f"[{client} {text}]"
                    messages[s] = msg
                    print(msg)
                else:
                    sockets.remove(s)
                    del clients[s]
                    del messages[s]
                    s.close()

        # Write messages
        for s in w:
            if s is server:
                continue

            for client, msg in messages.items():
                if client is not s and msg:
                    s.sendall(msg.encode())

        # Clear messages
        for key in messages.keys():
            messages[key] = None
        
except KeyboardInterrupt:
    print("Closing server...")
    for s in sockets:
        s.close()
