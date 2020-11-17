from node import Node


def inorder_traversal(node: Node):
    if node is None:
        return
    inorder_traversal(node.left)
    print(node.data)
    inorder_traversal(node.right)


def preorder_traversal(node: Node):
    if node is None:
        return
    print(node.data)
    preorder_traversal(node.left)
    preorder_traversal(node.right)


def postorder_traversal(node: Node):
    if node is None:
        return
    postorder_traversal(node.left)
    postorder_traversal(node.right)
    print(node.data)


def execute_inorder_traversal():
    n = Node(0)
    right = n.insert_right(Node(2))
    right.insert_right(Node(4))
    left = n.insert_left(Node(3))
    left.insert_left(Node(5))
    inorder_traversal(n)


def execute_preorder_traversal():
    n = Node(0)
    right = n.insert_right(Node(2))
    right.insert_right(Node(4))
    left = n.insert_left(Node(3))
    left.insert_left(Node(5))
    preorder_traversal(n)


def execute_postorder_traversal():
    n = Node(0)
    right = n.insert_right(Node(2))
    right.insert_right(Node(4))
    left = n.insert_left(Node(3))
    left.insert_left(Node(5))
    postorder_traversal(n)


if __name__ == '__main__':
    print('----inorder traversal----')
    execute_inorder_traversal()
    print('----preorder traversal----')
    execute_preorder_traversal()
    print('----postorder traversal----')
    execute_postorder_traversal()
