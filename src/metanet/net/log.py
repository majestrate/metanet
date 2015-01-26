__author__ = 'jeff'

import logging

def inject(obj):
    """
    inject logger object into object
    """
    obj.log = logging.getLogger(obj.__class__.__name__)