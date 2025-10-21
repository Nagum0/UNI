from socket import socket,AF_INET, SOCK_STREAM, timeout, SOL_SOCKET, SO_REUSEADDR
import struct
import select

server_addr = ('localhost', 11000)
unpacker = struct.Struct('I I 1s')  #int, int, char[1]

with socket(AF_INET, SOCK_STREAM) as server:
    server.bind(server_addr)
    server.listen(1)
    server.settimeout(1.0)
    server.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)

    inputs = [server]
    conn_timeout = 1.0

    while True:
        try:
            r, _, _ = select.select(inputs, [], [], conn_timeout)

            for s in r:
                if s is server:
                    conn, info = server.accept()
                    print(f"conn: {info[0]}")
                    inputs.append(conn)
                else:
                    data = s.recv(unpacker.size)
                    print("Kaptam:",data)

                    if not data:
                        s.close()
                        inputs.remove(s)
                        continue

                    unp_data = unpacker.unpack(data)
                    print("Unpack:",unp_data)

                    x = eval(str(unp_data[0]) + unp_data[2].decode() + str(unp_data[1]))

                    print("Kiertekeltem es visszakuldtem", x)
                    s.sendall(str(x).encode())

        except timeout:
            pass
