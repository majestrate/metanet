__author__ = 'jeff'

from .net import i2p, protocol, log
from .routing.kad import distance

class MetaNet:

    def __init__(self, peers):
        self._net = i2p.I2PNetHandler()
        log.inject(self)

    def get_closest_peer(self, dest):
        """
        :return: peer closest to destination
        """
        min_dist = None
        for peer in self._net.get_peers():
            dist = distance(peer, dest)
            if min_dist is None:
                min_dist = dist
            elif min_dist > dist:
                min_dist = dist
        return min_dist

    def mainloop(self):
        message, peer = self._net.get_message()
        obj = protocol.parse_packet(message)
        if obj is None:
            self.log.warn('invalid object')
        if obj['cmd'] == 'getdata':
            if self.has_hash(obj['hash']):
                pass
        new_peer = self.get_closest_peer(peer)