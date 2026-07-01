import socket
port = 5050

hostname = socket.gethostname()
host_ip = socket.gethostbyname(hostname)
server_socket_address = (host_ip, port)
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(server_socket_address)
server.listen()

print("Listened by the server")

buffer = 16
disconnected = "End"
format = "utf-8"


while (True):
    conn, addr = server.accept()
    print("Connected to", addr)
    
    connected = True

    while (connected):
        msg_length = conn.recv(buffer).decode(format)
        print("Message length:", msg_length)


        if (msg_length):
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(format)
            
            if (msg == disconnected):
                conn.send("Served!".encode(format))
                print("Connection detached with", addr)

                connected = False
            else:
                print(msg)
                conn.send("Message received!".encode(format))

    conn.close()
