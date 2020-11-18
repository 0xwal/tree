class Node:
    right: 'Node' = None
    left: 'Node' = None

    def __init__(self, data):
        self.data = data

    def insert_right(self, data) -> 'Node':
        data = Node(data)
        self.right = data
        return data

    def insert_left(self, data) -> 'Node':
        data = Node(data)
        self.left = data
        return data

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
