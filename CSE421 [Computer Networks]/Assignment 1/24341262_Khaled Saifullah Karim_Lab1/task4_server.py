import socket
port = 5050

buffer = 16
disconnected = "End"
format = "utf-8"

hostname = socket.gethostname()
host_ip = socket.gethostbyname(hostname)

server_socket_address = (host_ip, port)
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(server_socket_address)
server.listen()
print("Listened by the server")

def calculate_sal(hour):
    if (hour <= 40):
        sal = hour * 200
    else:
        sal = 8000 + (hour - 40) * 300

    return sal

while (True):
    conn, addr = server.accept()
    print("Connected to", addr)
    connected = True


    
    while connected:
        msg_length = conn.recv(buffer).decode(format)

        if (msg_length):
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(format)

            if (msg == disconnected):
                conn.send("Bye Tada".encode(format))
                print("Connection terminated with", addr)
                connected = False

            else:
                hour = float(msg)
                sal = calculate_sal(hour)
                rep = f"hour worked: {hour}, sal: Tk {sal}"
                conn.send(rep.encode(format))

    conn.close()