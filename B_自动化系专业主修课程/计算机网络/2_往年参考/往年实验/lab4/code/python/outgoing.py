"""
这是等待你完成的代码。正常情况下，本文件是你唯一需要改动的文件。
你可以任意地改动此文件，改动的范围当然不限于已有的五个函数里。（只要已有函数的签名别改，要是签名改了main里面就调用不到了）
在开始写代码之前，请先仔细阅读此文件和api文件。这个文件里的五个函数是等你去完成的，而api里的函数是供你调用的。
提示：TCP是有状态的协议，因此你大概率，会需要一个什么样的数据结构来记录和维护所有连接的状态
"""
from api import ConnectionIdentifier
from typing import TypedDict
from api import *
from tcp_packet import TCPPacket
import struct
state_machine = {}

def app_connect(conn: ConnectionIdentifier):
    """
    当有应用想要发起一个新的连接时，会调用此函数。想要连接的对象在conn里提供了。
    你应该向想要连接的对象发送SYN报文，执行三次握手的逻辑。
    当连接建立好后，你需要调用app_connected函数，通知应用层连接已经被建立好了。
    :param conn: 连接对象
    :return: 
    """
    # TODO 请实现此函数
    #print("app_connect", conn)
    global state_machine
    key = hash_conn(conn)
    if key not in state_machine: # state machine中不存在当前连接，于是新建当前连接记录
        state_machine[key] = State(connect_state=0,
                                   client_isn = 0,
                                   server_ack=0,
                                   current_ack=0,
                                   seq_tmp=0,
                                   tmp_conn=conn,
                                   tmp_save={})
    if state_machine[key]['connect_state'] == 0: # 状态为初始状态0, 发送syn1进行握手，进入状态1
        print('now send the syn1 to shake hand')
        state_machine[key]['connect_state'] = 1
        flags = 0b000010 # syn报文
        state_machine[key]['client_isn'] = 0x1111
        seq_num = state_machine[key]['client_isn']
        ack_num = state_machine[key]['connect_state']
        packet = TCPPacket(conn['src']['ip'],
                           conn['src']['port'],
                           conn['dst']['ip'],
                           conn['dst']['port'],
                           seq_num,
                           ack_num,
                           flags)
        data = packet.build()
        tcp_tx(conn, data)  # 发送syn1
    elif state_machine[key]['connect_state'] == 1: # 状态为1,收到syn，ack，触发此处，进行第三次握手,状态变为2
        print('now send ack to shake hand')
        state_machine[key]['connect_state'] = 2
        flags = 0b010000
        seq_num = state_machine[key]['client_isn']+1
        state_machine[key]['current_ack'] += 1
        ack_num = state_machine[key]['current_ack']
        packet = TCPPacket(conn['src']['ip'],
                           conn['src']['port'],
                           conn['dst']['ip'],
                           conn['dst']['port'],
                           seq_num,
                           ack_num,
                           flags)
        data = packet.build()
        tcp_tx(conn, data)  # 发送ack

        app_connected(conn)  # 告知app已连接


def app_send(conn: ConnectionIdentifier, data: bytes):
    """
    当应用层想要在一个已经建立好的连接上发送数据时，会调用此函数。
    :param conn: 连接对象
    :param data: 数据内容，是字节数组
    :return:
    """
    # TODO 请实现此函数
    # print("app_send", conn, data.decode(errors='replace'))
    global state_machine
    key = hash_conn(conn)
    print('now send data on established tcp')
    if len(data) == 0:
        flags = 0b010000
    else:
        flags = 0b011000
    seq_num = state_machine[key]['server_ack']
    ack_num = state_machine[key]['current_ack']
    packet = TCPPacket(conn['src']['ip'],
                       conn['src']['port'],
                       conn['dst']['ip'],
                       conn['dst']['port'],
                       seq_num,
                       ack_num,
                       flags,
                       data)
    tcp_data = packet.build()
    tcp_tx(conn, tcp_data)
    state_machine[key]['server_ack'] += len(data)


def app_fin(conn: ConnectionIdentifier):
    """
    当应用层想要半关闭连接(FIN)时，会调用此函数。
    :param conn: 连接对象
    :return: 
    """
    # TODO 请实现此函数
    # print("app_fin", conn)
    global state_machine
    key = hash_conn(conn)
    print('now send message to fin tcp')
    if state_machine[key]['connect_state'] == 2:
        state_machine[key]['connect_state'] = 3
    flags = 0b010001  # ack and fin
    seq_num = state_machine[key]['server_ack']
    ack_num = state_machine[key]['current_ack']
    packet = TCPPacket(conn['src']['ip'],
                       conn['src']['port'],
                       conn['dst']['ip'],
                       conn['dst']['port'],
                       seq_num,
                       ack_num,
                       flags)
    tcp_data = packet.build()
    tcp_tx(conn, tcp_data)


def app_rst(conn: ConnectionIdentifier):
    """
    当应用层想要重置连接(RES)时，会调用此函数
    :param conn: 连接对象
    :return: 
    """
    # TODO 请实现此函数
    # print("app_rst", conn)
    global state_machine
    key = hash_conn(conn)
    print('now send message to rst tcp')
    flags = 0b010100 # rst
    seq_num = state_machine[key]['server_ack']
    ack_num = state_machine[key]['current_ack']
    packet = TCPPacket(conn['src']['ip'],
                       conn['src']['port'],
                       conn['dst']['ip'],
                       conn['dst']['port'],
                       seq_num,
                       ack_num,
                       flags)
    tcp_data = packet.build()
    tcp_tx(conn, tcp_data)
    # 重置
    release_connection(conn)
    state_machine[key]['connect_state'] = 0
    state_machine[key]['client_isn'] = 0
    state_machine[key]['server_ack'] = 0
    state_machine[key]['current_ack'] = 0
    state_machine[key]['seq_tmp'] = 0
    state_machine[key]['tmp_save'] = {}


def tcp_rx(conn: ConnectionIdentifier, data: bytes):
    """
    当收到TCP报文时，会调用此函数。
    正常情况下，你会对TCP报文，根据报文内容和连接的当前状态加以处理，然后调用0个~多个api文件中的函数
    :param conn: 连接对象
    :param data: TCP报文内容，是字节数组。（含TCP报头，不含IP报头）
    :return: 
    """
    # TODO 请实现此函数
    # print("tcp_rx", conn, data.decode(errors='replace'))
    global state_machine
    key = hash_conn(conn)
    state_machine[key]['tmp_conn'] = conn
    scr_port, dst_port, seq_num, ack_num, mix, win, chksum, urpointer = struct.unpack('!HHIIHHHH', data[:20])
    offset = mix >> 12
    fin = (mix & 0b0000000000000001)
    syn = (mix & 0b0000000000000010) >> 1
    rst = (mix & 0b0000000000000100) >> 2
    ack = (mix & 0b0000000000010000) >> 4
    real_data = data[4 * offset:]

    if state_machine[key]['current_ack'] == 0:
        state_machine[key]['current_ack'] = seq_num

    if state_machine[key]['current_ack'] == seq_num:  # 收到的满足请求，才操作
        state_machine[key]['server_ack'] = ack_num
        state_machine[key]['current_ack'] = seq_num + len(real_data)
        if syn == 1 and state_machine[key]['connect_state'] == 1:
            print('rcv syn=1, now send ack back')
            app_connect(conn)
        elif state_machine[key]['connect_state'] == 2 and not fin: # 对面发来信息，我传给应用层
            print('rcv message, now send to app')
            app_recv(conn, real_data)
            # 如果有信息，回复ack
            if len(data[4 * offset:]) > 0:
                send_ack(conn)
        elif state_machine[key]['connect_state'] == 2 and fin: # 对面主动发来fin
            print('rcv fin, now send to app')
            state_machine[key]['connect_state'] = 5
            state_machine[key]['current_ack'] += 1
            app_peer_fin(conn)
            send_ack(conn)
        elif state_machine[key]['connect_state'] == 3 and ack: # 收到第二次挥手：收到对面回应的ack
            print('rcv ack, server ready to finish')
            state_machine[key]['connect_state'] = 4
        elif state_machine[key]['connect_state'] == 4 and fin == 1: # 收到第三次挥手，进行第四次挥手：收到对面回应的fin，回一个ack
            print('rcv fin, now send to app')
            state_machine[key]['connect_state'] = 5
            app_peer_fin(conn)
            send_ack(conn)
            print('now release resource')
            release_connection(conn)
            state_machine[key]['connect_state'] = 0
            state_machine[key]['client_isn'] = 0
            state_machine[key]['server_ack'] = 0
            state_machine[key]['current_ack'] = 0
            state_machine[key]['seq_tmp'] = 0
            state_machine[key]['tmp_save'] = {}
        elif state_machine[key]['connect_state'] == 5 and ack: # 等待结束释放资源
            print('now release resource')
        else: # 以上都不满足，说明有些错误
            pass
            # print('there\'s something wrong')
            # print('conn', state_machine[key]['connect_state'])
            # print('syn', syn)
            # print('fin', fin)
            # print('ack', ack)
        if rst == 1: # 收到rst进行rst
            print('rcv rst, now send to app')
            app_peer_rst(conn)
            release_connection(conn)
            state_machine[key]['connect_state'] = 0
            state_machine[key]['client_isn'] = 0
            state_machine[key]['server_ack'] = 0
            state_machine[key]['current_ack'] = 0
            state_machine[key]['seq_tmp'] = 0
            state_machine[key]['tmp_save'] = {}

        if state_machine[key]['current_ack'] in state_machine[key]['tmp_save']:
            # print('use tmp')
            tcp_rx(conn, state_machine[key]['tmp_save'][state_machine[key]['current_ack']])
    else:
        # print('seq_num wrong')
        if seq_num > state_machine[key]['current_ack']:
            state_machine[key]['tmp_save'][seq_num] = data

def tick():
    """
    这个函数会每至少100ms调用一次，以保证控制权可以定期的回到你实现的函数中，而不是一直阻塞在main文件里面。
    它可以被用来在不开启多线程的情况下实现超时重传等功能，详见主仓库的README.md
    """
    # TODO 可实现此函数，也可不实现
    global state_machine
    for key in state_machine:
        if state_machine[key]['connect_state'] == 2:
            if state_machine[key]['seq_tmp']==state_machine[key]['current_ack'] and state_machine[key]['seq_tmp']!=0 :
                # print("timeout resend")
                send_ack(state_machine[key]['tmp_conn'])
            else:
                state_machine[key]['seq_tmp'] = state_machine[key]['current_ack']



def send_ack(conn: ConnectionIdentifier):
    """
    当收到对端的信息后，会调用此函数回复ack
    :param conn: 连接对象
    :return:
    """
    # TODO 请实现此函数
    global state_machine
    key = hash_conn(conn)
    flags = 0b010000
    seq_num = state_machine[key]['server_ack']
    ack_num = state_machine[key]['current_ack']
    packet = TCPPacket(conn['src']['ip'],
                       conn['src']['port'],
                       conn['dst']['ip'],
                       conn['dst']['port'],
                       seq_num,
                       ack_num,
                       flags)
    tcp_data = packet.build()
    tcp_tx(conn, tcp_data)

def hash_conn(conn: ConnectionIdentifier):
    """
    该函数 hash conn
    """
    return str(conn['src']['ip'])+str(conn['src']['port'])+str(conn['dst']['ip'])+str(conn['dst']['port'])



class State(TypedDict):
    connect_state: int # 状态0,1,2,3,4,5
    client_isn: int
    server_ack: int  # 最新server发来报文的ack
    current_ack: int  # 当前想发送报文的ack
    seq_tmp: int  # seq缓存，用于验证重传
    tmp_conn: ConnectionIdentifier
    tmp_save: dict
