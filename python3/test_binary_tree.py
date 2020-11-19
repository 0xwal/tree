import unittest

from binary_tree import BinaryTree
from node import Node


class TestBinaryTree(unittest.TestCase):

    def setUp(self) -> None:
        self.binary_tree = BinaryTree()

    def test_a_new_node_should_be_added_to_the_root_when_root_is_none(self):
        self.binary_tree.add(5)
        self.assertIsNotNone(self.binary_tree.root)
        self.assertIsInstance(self.binary_tree.root, Node)

    def test_a_new_node_should_not_be_added_to_the_root_when_it_is_not_none(self):
        self.binary_tree.add(5)
        self.binary_tree.add(3)
        self.assertEqual(self.binary_tree.root.data, 5)

    def test_a_new_node_should_be_added_to_right_when_left_is_not_none(self):
        self.binary_tree.add(5)
        self.binary_tree.root.insert_left(2)
        self.binary_tree.add(3)
        self.assertEqual(self.binary_tree.root.preorder_traversal(), [5, 2, 3])

    def test_a_new_node_should_be_added_to_left_when_right_is_not_none(self):
        self.binary_tree.add(5)
        self.binary_tree.root.insert_right(2)
        self.binary_tree.add(3)
        self.assertEqual(self.binary_tree.root.preorder_traversal(), [5, 3, 2])

    def test_a_new_node_should_be_added_to_next_level_when_left_and_right_already_filled(self):
        self.binary_tree.add(0)
        self.binary_tree.root.insert_right(1)
        self.binary_tree.root.insert_left(2)
        self.binary_tree.add(3)
        self.assertEqual(self.binary_tree.root.preorder_traversal(), [0, 2, 1, 3])

    def test_right_node_should_be_filled_before_its_left_sibling(self):
        self.binary_tree.add(0)  # root
        self.binary_tree.add(1)  # root->right
        self.binary_tree.add(2)  # root->left
        self.binary_tree.add(3)  # root->right->right
        self.binary_tree.add(4)  # root->right->left
        self.binary_tree.add(5)  # root->left->right
        self.binary_tree.add(6)  # root->left->left
        self.binary_tree.add(7)  # root->right->right->right

        self.assertEqual(self.binary_tree.root.preorder_traversal(), [0, 2, 6, 5, 1, 4, 3, 7])


if __name__ == '__main__':
    unittest.main()
