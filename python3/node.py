class Node:
    def __init__(self, data):
        self.right = None
        self.left = None
        self.data = data

    def insert_right(self, node: 'Node') -> 'Node':
        self.right = node
        return node

    def insert_left(self, node: 'Node') -> 'Node':
        self.left = node
        return node
