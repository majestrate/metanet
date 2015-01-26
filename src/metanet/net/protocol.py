__author__ = 'jeff'

from . import bencode

def ping_packet(peer, id):
    """
    make ping packet for peer
    :return: bytes
    """
    obj = {'version': 1, 'cmd': 'ping', 'id': id}
    return bencode.encode(obj)

def getdata_packet(send_to_peer, hash, sig, id):
    """
    make getdata packet
    :param hash: hash of object
    :return: bytes
    """
    obj = {'version': 1, 'cmd': 'getdata', 'id': id, 'peer': send_to_peer, 'sig': sig}
    return bencode.encode(obj)

def gotdata_packet(data, id):
    """
    make gotdata
    :param data: actual data
    :return: bytes
    """
    obj = {'version': 1, 'cmd': 'gotdata', 'id': id, 'data': data}
    return bencode.encode(obj)

def parse_packet(data):
    obj = bencode.decode(data)
    for req in ('version', 'cmd', 'id'):
        if req not in obj:
            return None
    if obj['version'] == 1:
        return obj