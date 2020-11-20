from node import Node


class BinarySearchTree:
    __root: Node = None

    @property
    def root(self) -> Node:
        return self.__root

    def add(self, data):
        if self.__root is None:
            self.__root = Node(data)
            return

        if data < self.__root.data:
            tmp_node = self.__root
            while tmp_node.left is not None:
                tmp_node = tmp_node.left
            tmp_node.insert_left(data)
        else:
            tmp_node = self.__root
            while tmp_node.right is not None:
                tmp_node = tmp_node.right
            tmp_node.insert_right(data)
