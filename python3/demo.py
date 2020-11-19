import sys

from binary_tree import BinaryTree


def demo():
    binary = BinaryTree()
    for i in range(count):
        binary.add(i)
    binary.dump()


if __name__ == '__main__':
    count = 10
    if len(sys.argv) > 1 and sys.argv[1].isnumeric():
        count = int(sys.argv[1])
    demo()
