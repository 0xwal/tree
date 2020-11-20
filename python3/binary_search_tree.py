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

        node = self.__root
        while True:
            if data > node.data:
                if node.right is not None:
                    node = node.right
                    continue
                node.right = Node(data)
                break
            else:
                if node.left is not None:
                    node = node.left
                    continue
                node.left = Node(data)
                break
