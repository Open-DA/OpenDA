from socket import *
from threading import Thread

class tcpClient():
    server_addr = ('127.0.0.1',12000)
    def __init__(self):
        self.clientSocket = socket()  # 创建套接字

    def msg_recv(self):
        while True:
            data = self.clientSocket.recv(1024)
            if data.decode() == 'exit':
                print('Client Exit!')
                break
            print(data.decode())
    def msg_send(self):
        while True:
            data_info = input()
            self.clientSocket.send(data_info.encode())
            if data_info == 'exit':
                break
    def start(self):
        try:
            self.clientSocket.connect(self.server_addr)
        except Exception:
            print("Failed!")
            self.clientSocket.close()
            return

        while True:
            name = input("Please Enter Your Name:")
            self.clientSocket.send((name).encode())
            data = self.clientSocket.recv(128)
            print(data.decode(),type(data.decode() ))
            if data.decode() == 'OK':
                print("You have entered the chat room!")
                break
            else:
                print(data.decode())

        t = Thread(target=self.msg_recv)  # 新建一个线程
        t.start()
        self.msg_send()


if __name__=='__main__':
    server1 = tcpClient()
    server1.start()