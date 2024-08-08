from socket import *
from threading import Thread
import os,sys
import time

class Node():
    def __init__(self):
        self.Name = None
        self.Ip = None
        self.Thr = None
        self.Port = None

class tcpServer():
    user_name = {}
    jobs = {}
    def __init__(self,post):
        self.ServerPort = post
        self.IP =gethostbyname(gethostname())
        self.tcp_socket = socket()  # tcp套接字
        self.tcp_socket.setsockopt(SOL_SOCKET,SO_REUSEADDR,1)    # 端口重用
        self.tcp_socket.bind(self.ServerPort) # 绑定port

    def start(self):
        self.tcp_socket.listen(5) # 监听并定义请求连接的最大数
        print(self.getTime(),'Server：等待连接')
        while True:
            try:
                conn,addr = self.tcp_socket.accept() # accept 属于阻塞式，没有收到连接请求就不会继续向下运行；conn为专有连接
            except KeyboardInterrupt:
                self.tcp_socket.close()
                sys.exit('\n'+self.getTime()+'Server：Server Quit!')
            except Exception as e:
                print(e)
                continue

            t = Thread(target=self.do_request,args=(conn,)) # 新建一个线程
            t.start()

            self.jobs[conn] = t
            for c in self.jobs:
                if c._closed is True:
                    self.jobs[c].join()

    def do_request(self, conn):

        connNode = Node()
        while True:
            recv_data = conn.recv(1024).decode().strip()
            client_ip = conn.getpeername()

            # delete
            if recv_data == 'exit':
                print(self.getTime(),'Server: User ' + connNode.Name + 'Quit!')
                conn.send('exit'.encode())
                self.user_name.pop(connNode.Name)
                conn.close()
                break

            if connNode.Name == None:
                print(self.getTime() + ' Server：' + recv_data + ' Connected Successfully!')
                connNode.Name = recv_data
                connNode.Ip = client_ip
                connNode.Thr = conn
                self.user_name[recv_data] = connNode
                data_info = self.getTime() +  ' Server：' + f'{self.ServerPort}' + recv_data + ' Connected'
                conn.send('OK'.encode())
                self.server_send_msg(data_info)

            else:
                data_info = self.getTime() + ' %s：' % connNode.Name + f'{connNode.Ip}' + recv_data
                self.client_send_msg(connNode.Name, data_info)


    def getTime(self):
        return '['+time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())+']'

    def client_send_msg(self,name,data_info):
        if len(self.user_name)==1:
            print(self.getTime() + ' Server：Send Message to nobody')
            return
        # send message to all users except self
        print(self.getTime()+' Server：Send Message to ',end = '')
        for i in self.user_name.values():
            if i.Name!=name:
                print(i.Name+',', end='')
                i.Thr.send(data_info.encode())
        print()

    def server_send_msg(self,data_info):
        # Server广播信息
        # ip port
        print(self.getTime() + ' Server：Send Message to ', end='')
        for i in self.user_name.values():
            print(i.Name + ',', end='')
            i.Thr.send(data_info.encode())
        print()



if __name__=='__main__':
    Host = '127.0.0.1'
    Post = 12000
    server1 = tcpServer((Host, Post))
    server1.start()