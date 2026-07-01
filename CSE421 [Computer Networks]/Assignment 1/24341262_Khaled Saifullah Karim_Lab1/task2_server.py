import socket
port = 5050
hostname = socket.gethostname()
host_ip = socket.gethostbyname(hostname)

server_socket_address = (host_ip, port)
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(server_socket_address)
server.listen()

buffer = 16
disconnected = "End"
format = "utf-8"

print("Listened by the server")



while (True):
    conn, addr = server.accept()
    print("Connected to", addr)
    connected = True
    while (connected):
        msg_length = conn.recv(buffer).decode(format)

        if (msg_length):
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(format)

            if (msg == disconnected):
                conn.send("Served!".encode(format))
                print("Connection detached with", addr)
                connected = False

            else:
                vowels = "aeiouAEIOU"
                ttl = 0
                for i in msg:
                    if (i in vowels):
                        ttl += 1
                
                if (ttl == 0):
                    conn.send("Not suffiecient vowels".encode(format))
                elif (ttl <= 2):
                    conn.send("Maybe enough vowels".encode(format))
                else:
                    conn.send("Lot's of vowels".encode(format))
    conn.close()