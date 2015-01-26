__author__ = 'jeff'


class BaseNetHandler:
    """
    basic stateless network handler interface
    """

    def send_message(self, message, peer):
        """
        send message to endpoint
        :param message: message data
        :param peer: remote peer
        :return: None
        """

    def get_message(self):
        """
        get next message from network
        :return: message data, peer
        """

    def get_address(self):
        """
        :return: our address as string
        """

    def get_peers(self):
        """
        :return: all peers we are connected to
        """

    def run_until_done(self):
        """
        run network i/o until done
        """