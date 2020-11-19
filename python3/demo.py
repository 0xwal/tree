from binary_tree import BinaryTree


def demo():
    binary = BinaryTree()
    for i in range(10):
        binary.add(i)
    binary.dump()


if __name__ == '__main__':
    demo()
