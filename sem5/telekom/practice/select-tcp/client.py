import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
addr = ("127.0.0.1", 42069)
client.connect(addr)

try:
    while True:
        data = input("$ ")
        client.sendall(data.encode())
    
        resp = client.recv(1024)
        if resp:
            print(resp.decode())
        else:
            continue
except KeyboardInterrupt:
    print("Exiting...")
    client.close()
