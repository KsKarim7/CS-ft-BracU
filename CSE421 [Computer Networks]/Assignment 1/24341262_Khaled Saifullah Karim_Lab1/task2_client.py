import socket
port = 5050
hostname = socket.gethostname()
host_ip = socket.gethostbyname(hostname)

server_socket_address = (host_ip, port)

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(server_socket_address)

buffer = 16
disconnected = "End"
format = "utf-8"

def msg_to_be_sent(msg):
    msg = msg.encode(format)
    msg_length = len(msg)
    msg_length = str(msg_length).encode(format)
    msg_length += b" " * (buffer - len(msg_length))
    client.send(msg_length)
    client.send(msg)
    print(client.recv(2048).decode(format))


while (True):
    inp = input("Input something")
    if (inp == "Done"):
        msg_to_be_sent(disconnected)
        break
    
    else:
        msg_to_be_sent(inp)