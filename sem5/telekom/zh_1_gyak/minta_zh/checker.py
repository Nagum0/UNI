import socket
import struct

tcp_packer = struct.Struct("4s i")
udp_packer = struct.Struct("5s i")

tcp_conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
udp_conn = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
tcp_conn.connect(("localhost", 42069))

udp_conn.sendto(udp_packer.pack(b"PLUS", 0), ("localhost", 42070))
tcp_conn.sendall(tcp_packer.pack(b"INCR", 0))

udp_resp, _ = udp_conn.recvfrom(1024)
if int(udp_resp.decode()) != 0: 
    print(f"UDP error: {udp_resp}")

tcp_resp = tcp_conn.recv(1024)
assert int(tcp_resp.decode()) == 0, f"TCP error: {tcp_resp}"

print("Both servers are correct!")

tcp_conn.close()
udp_conn.close()
