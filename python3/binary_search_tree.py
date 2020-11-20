from node import Node


class BinarySearchTree:
    __root: Node = None

    @property
    def root(self) -> Node:
        return self.__root

    def add(self, data):
        if self.root is None:
            self.__root = Node(data)
            return

        self.__add(self.__root, data)

    def __add(self, node: Node, data):

        if data > node.data:
            if node.right is not None:
                self.__add(node.right, data)
                return
            node.right = Node(data)
        else:
            if node.left is not None:
                self.__add(node.left, data)
                return
            node.left = Node(data)
