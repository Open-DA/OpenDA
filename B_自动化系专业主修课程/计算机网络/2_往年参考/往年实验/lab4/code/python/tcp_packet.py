"""
该类的构建及校验和的计算参考了以下网站
https://kytta.medium.com/tcp-packets-from-scratch-in-python-3a63f0cd59fe
"""

import struct
import array
import socket


class TCPPacket:
    def __init__(self,
                 src_host,
                 src_port,
                 dst_host,
                 dst_port,
                 seq_num,
                 ack_num,
                 flags=0,data=None):
        self.src_host = src_host
        self.src_port = src_port
        self.dst_host = dst_host
        self.dst_port = dst_port
        self.seq_num = seq_num
        self.ack_num = ack_num
        self.flags = flags
        self.data = data

    def build(self):
        packet = struct.pack(
            '!HHIIBBHHH',
            self.src_port,  # Source Port
            self.dst_port,  # Destination Port
            self.seq_num,  # Sequence Number
            self.ack_num,  # Acknoledgement Number
            5 << 4,  # Data Offset
            self.flags,  # Flags
            65530,  # Window
            0,  # Checksum (initial value)
            0  # Urgent pointer
        )
        if self.data!=None:
            packet = packet+self.data
        pseudo_hdr = struct.pack(
            '!4s4sHH',
            socket.inet_aton(self.src_host),  # Source Address
            socket.inet_aton(self.dst_host),  # Destination Address
            socket.IPPROTO_TCP,  # Protocol ID
            len(packet)  # TCP Length
        )

        checksum = chksum(pseudo_hdr + packet)
        packet = packet[:16] + struct.pack('H', checksum) + packet[18:]

        return packet


def chksum(packet):
    if len(packet) % 2 != 0:
        packet += b'\0'
    res = sum(array.array("H", packet))
    res = (res >> 16) + (res & 0xffff)
    res += res >> 16
    return (~res) & 0xffff
