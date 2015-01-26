__author__ = 'jeff'

import hashlib


def distance(x, y):
    """
    compute distance between x and y
    :param x:
    :param y:
    :return: distance as long int
    """

    hx = hashlib.new('sha1')
    hx.update(x)
    ix = int.from_bytes(hx.digest(), byteorder='big')

    hy = hashlib.new('sha1')
    hy.update(y)
    iy = int.from_bytes(hy.digest(), byteorder='big')

    return ix ^ iy