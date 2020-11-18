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

    def inorder_traversal(self) -> list:
        numbers = []
        if self.left is not None:
            numbers += self.left.inorder_traversal()
        numbers.append(self.data)
        if self.right is not None:
            numbers += self.right.inorder_traversal()
        return numbers

    def preorder_traversal(self):
        numbers = [self.data]
        if self.left is not None:
            numbers += self.left.preorder_traversal()
        if self.right is not None:
            numbers += self.right.preorder_traversal()
        return numbers

    def postorder_traversal(self):
        numbers = []
        if self.left is not None:
            numbers += self.left.postorder_traversal()
        if self.right is not None:
            numbers += self.right.postorder_traversal()
        numbers.append(self.data)
        return numbers
