import socket
import threading

def recv_loop(client: socket.socket):
    while True:
        try:
            data = client.recv(1024)
            if not data:
                print("Server closed connection.")
                break
            print("\n" + data.decode() + "\n", end="")
        except:
            break

def main():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("127.0.0.1", 42069))

    threading.Thread(target=recv_loop, args=(client,), daemon=True).start()

    try:
        while True:
            data = input("$ ")

            if not data:
                continue

            client.sendall(data.encode())

    except KeyboardInterrupt:
        print("Exiting...")
    finally:
        client.close()

if __name__ == "__main__":
    main()
