from node import Node


class BinaryTree:

    @property
    def root(self) -> Node:
        return self.__root

    def __init__(self):
        self.__root = None

    def add(self, data):
        if self.__root is None:
            self.__root = Node(data)
            return

        self._add(data)

    def _add(self, data):
        tmp_node = self.root
        while 1:
            if tmp_node.right is None:
                tmp_node.insert_right(data)
                return
            if tmp_node.left is None:
                tmp_node.insert_left(data)
                return

            if tmp_node.right.right is None or tmp_node.right.left is None:
                tmp_node = tmp_node.right
                continue

            if tmp_node.left.right is None or tmp_node.left.left is None:
                tmp_node = tmp_node.left
                continue

            tmp_node = tmp_node.right

    def dump(self):
        print(self.__root.preorder_traversal())
