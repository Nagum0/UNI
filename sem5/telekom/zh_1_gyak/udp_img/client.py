import socket

SERVER_ADDR = ("localhost", 42069)
IMG_PATH = "udp_img/makima.png"

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

with open(IMG_PATH, "rb") as img_file:
    while True:
        chunk = img_file.read(200)
        if not chunk:
            sock.sendto(b'\x00', SERVER_ADDR)
            break

        sock.sendto(chunk, SERVER_ADDR)

        resp, _ = sock.recvfrom(1024)
        print(f"Server response: {resp.decode()}")

sock.close()
