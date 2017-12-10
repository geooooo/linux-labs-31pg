class Buffer:
    """
        Буфер ограниченного размера
    """

    def __init__(self, max_size):
        self._max_size = max_size
        self._cur_size = 0
        self._buffer = []

    def add(self, value):
        self._buffer.append(value)
        self._cur_size += 1

    def get(self):
        self._cur_size -= 1
        return self._buffer.pop()

    def is_full(self):
        return self._cur_size == self._max_size

    def is_empty(self):
        return self._cur_size == 0

    def print_buffer(self):
        print(self._buffer)
