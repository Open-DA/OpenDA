"""
这是SDK内置的代码，主要是与driver进行通信的逻辑。
正常情况下，你应该也不需要阅读本文件的代码，只要读api文件，然后完成outgoing文件就好。
此文件通常不用改动。但如果你有确切的理由，也可以自行改动，但请务必确保你清楚自己在做什么！
助教评阅时，会使用你上传的版本。
"""
import os
import sys
import time
from socket import socket, SOCK_DGRAM, AF_UNIX
from traceback import print_exc

import bson

from api_type import ConnectionIdentifier

unix_sock: socket


def sdk_event(conn: ConnectionIdentifier, data: bytes, flags: int):
    event = {"conn": conn, "bytes": data, "flags": flags}
    try:
        unix_socket_send(event)
    except Exception as e:
        print("unix_socket_send FAILED", e, file=sys.stderr)


def unix_socket_send(event: dict):
    data = bson.dumps(event)
    unix_sock.send(data)


def unix_socket_recv():
    max_size = 500000
    data = unix_sock.recv(max_size)
    if len(data) == 1:  # 是保活报文
        outgoing.tick()
        return
    if len(data) >= max_size:
        raise AssertionError(
            f"WARNING: 收到了超过接收buffer大小({max_size})的unix domain socket报文！该报文并未被完整接收！")
    event = bson.loads(data)
    flags = event["flags"]
    try:
        if flags == 0x0:
            outgoing.app_send(event["conn"], event["bytes"])
        elif flags == 0x1:
            outgoing.app_fin(event["conn"])
        elif flags == 0x2:
            outgoing.app_connect(event["conn"])
        elif flags == 0x4:
            outgoing.app_rst(event["conn"])
        elif flags == 0x40:
            outgoing.tcp_rx(event["conn"], event["bytes"])
    except Exception:
        print("调用outgoing函数时发生异常！以下是异常栈：")
        print_exc()

if __name__ == '__main__':
    try:
        os.unlink("/tmp/network-exp4-sdk.socket")
    except:
        pass
    unix_sock = socket(AF_UNIX, SOCK_DGRAM)
    unix_sock.bind("/tmp/network-exp4-sdk.socket")
    while True:
        try:
            unix_sock.connect("/tmp/network-exp4-driver.socket")
            break
        except OSError as e:
            if e.errno == 1:  # Operation not permitted
                print("等待服务端UnixSocket资源释放(约500ms)...(若持续出现此信息，请检查自己是否开着另一个SDK进程)")
                time.sleep(0.5)
                continue
            else:
                raise e
    import outgoing

    # 向服务器发送初次连接的通告
    sdk_event({"src": {"ip": "127.84.0.1", "port": 8484}, "dst": {"ip": "", "port": 0}}, b'network_exp4', 0xa0)
    print("已启动！")
    while True:
        try:
            unix_socket_recv()
        except Exception as e:
            print("unix_socket_recv FAILED", e, file=sys.stderr)
