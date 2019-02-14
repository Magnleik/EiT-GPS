import socket
import datetime

port = 9001
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Accept UDP datagrams, on the given port, from any sender
s.bind(("", port))
print("waiting on port: ", port)
while True:
    # Receive up to 1,024 bytes in a datagram
    data, addr = s.recvfrom(1024)
    now = datetime.datetime.now()
    with open("out2.txt", "a") as f:
        f.writelines("{0:%Y-%b-%d %H:%M:%S}: {1}\n".format(now, data.decode("utf-8")))
    print("Received:", data, " from ", addr)
