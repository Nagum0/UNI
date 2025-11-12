import socket

IP = "localhost"
PORT = 42069
ADDR = (IP, PORT)

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(ADDR)

with open("udp_img/makima_copy.png", "wb") as img_file:
    while True:
        chunk, address = server.recvfrom(200)
        if chunk == b'\x00':
            break

        img_file.write(chunk)
        server.sendto(b"OK", address)

server.close()
