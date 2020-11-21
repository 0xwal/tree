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

    def find(self, data):
        iteration = 0

        if self.__root is None:
            return -1

        node = self.__root
        while True:

            if data == node.data:
                return iteration

            if node.right is None and node.left is None:
                break

            if data > node.data and node.right is not None:
                node = node.right
                iteration += 1
                continue

            else:
                if node.left is not None:
                    node = node.left
                    iteration += 1
                    continue

        return -1

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
