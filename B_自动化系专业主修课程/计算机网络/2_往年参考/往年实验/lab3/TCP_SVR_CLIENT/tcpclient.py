from socket import *
from threading import Thread

serverName = '127.0.0.1'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))


# 循环阻塞式地从socket中读取数据，必须放在一个独立的线程中，
# 否则，就没办法实现用户能够同时输入消息和程序实时打印接收到的消息
class ReceivingThread(Thread):
    def __init__(self):
        super().__init__()

    def run(self):
        while True:
            modifiedSentence = clientSocket.recv(1024)
            if len(modifiedSentence) == 0:
                # 返回的句子长度为0，说明对端已close
                clientSocket.close()
                return
            print('From Server:', modifiedSentence.decode())


# 开启上面定义的线程
receivingThread = ReceivingThread()
receivingThread.start()

sentence = input('Input lowercase sentence:')
clientSocket.send(sentence.encode())
