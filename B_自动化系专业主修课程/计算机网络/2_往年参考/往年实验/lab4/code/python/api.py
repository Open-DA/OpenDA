"""
这是SDK内置的代码，本文件中是提供给你、供你在outgoing自由调用的函数。
你需要仔细阅读此文件，了解五个提供给你的函数。重点阅读函数上方的注释。还要阅读api_type.py文件，了解ConnectionIdentifier数据类。
你可能不用改动此文件，但如果你确实需要的话（比如想加几个方法，或重载运算符之类），当然也可以改动。只要你清楚自己在做什么！
助教评阅时，会使用你上传的版本。
"""
from api_type import ConnectionIdentifier
from __main__ import sdk_event


# ConnectionIdentifier的定义在api_type.py中
def app_connected(conn: ConnectionIdentifier):
    """
    当连接建立好时，请调用此函数，以通知应用层。
    只有你调用此函数后，应用层才会开始调用app_send函数发送数据。
    :param conn: 连接对象
    :return: 
    """
    sdk_event(conn, b'', 0x2)


def release_connection(conn: ConnectionIdentifier):
    """
    当完成了正常的双向四次挥手过程，想要释放连接时，请调用此函数。
    调用此函数会让上层（你可以理解成是操作系统，本实验中实际上是driver）释放占用的端口资源（在本实验中总数共4000个），
    同时不再将该连接四元组上收到的包（如果之后还有的话）转发给你实现的tcp_rx函数。
    如果一直不调用此函数，占用的端口就无法被回收，就将无法再发起新的连接。而且tcp_rx也会一直收到关于此连接的包。
    注意：RST的情况（包括app_rst和app_peer_rst）不需要调用此函数释放连接（当然，调了也没有关系，不会报错）
    :param conn: 连接对象
    :return: 
    """
    sdk_event(conn, b'', 0x80)


def app_recv(conn: ConnectionIdentifier, data: bytes):
    """
    当对端发来数据时，请调用此函数，将数据传给应用层。
    :param conn: 连接对象
    :param data:
    :return: 数据内容，是字节数组
    """
    sdk_event(conn, data, 0x0)


def app_peer_fin(conn: ConnectionIdentifier):
    """
    当对端要求半关闭连接(FIN)时，请调用此函数以通知应用层。
    :param conn: 连接对象
    :return:
    """
    sdk_event(conn, b'', 0x1)


def app_peer_rst(conn: ConnectionIdentifier):
    """
    当对端要求重置连接(RES)时，请调用此函数以通知应用层。
    :param conn: 连接对象
    :return:
    """
    sdk_event(conn, b'', 0x4)


def tcp_tx(conn: ConnectionIdentifier, data: bytes):
    """
    当你想向外发送TCP报文时，请调用此函数。
    一些提示：
    1. 请确保你的报文中包含了报头。
    2. 请注意报头中的所有大于1字节的数字（端口号、seq、ack等），都是遵守的网络字节序（又称大端序）。
       如果你手动组装报头，请记得要将主机字节序(host byte order)转为网络字节序(net byte order)（大多数编程语言都提供了这种东西，可自行查阅）。
       或者，很多语言都有一些库，可以用对人友好的API帮你生成报头甚至是报文。
       一些可供参考的资料： https://zh.wikipedia.org/wiki/%E5%AD%97%E8%8A%82%E5%BA%8F https://www.gta.ufrj.br/ensino/eel878/sockets/htonsman.html
    3. 请记得正确计算TCP检验和。（也可考虑使用库计算）
    :param conn: 连接对象
    :param data: TCP报文内容，是字节数组。注意要包含TCP报头，不要包含IP报头。
    :return:
    """
    sdk_event(conn, data, 0x40)
