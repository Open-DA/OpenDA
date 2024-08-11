"""
这是SDK内置的代码，本文件中是提供给你、在outgoing和api中使用的数据结构。
你需要仔细阅读此文件，了解ConnectionIdentifier数据类。然后，还应该去阅读api.py，了解五个提供给你的函数。
你可能不用改动此文件，但如果你确实需要的话（比如想加几个方法，或重载运算符之类），当然也可以改动。只要你清楚自己在做什么！
助教评阅时，会使用你上传的版本。
"""
from typing import TypedDict


class IpAndPort(TypedDict):
    """
    表示IPV4地址和端口号的结构体
    """
    ip: str
    port: int


class ConnectionIdentifier(TypedDict):
    """
    表示一个TCP连接的结构体，包含源IP和端口、目的IP和端口，即平时所说的四元组
    """
    src: IpAndPort
    dst: IpAndPort
