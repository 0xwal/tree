import unittest

from binary_search_tree import BinarySearchTree


class TestBinarySearchTree(unittest.TestCase):

    def test_root_should_be_none_on_initialization(self):
        bst = BinarySearchTree()
        self.assertIsNone(bst.root)

    def test_assign_first_added_node_to_root(self):
        bst = BinarySearchTree()
        bst.add(5)
        self.assertEqual(bst.root.data, 5)

    def test_add_a_new_node_to_tree_when_the_root_is_not_none(self):
        bst = BinarySearchTree()
        bst.add(5)
        bst.add(4)
        self.assertEqual(bst.root.data, 5)

    def test_smaller_number_should_be_added_to_the_left_side_of_tree(self):
        bst = BinarySearchTree()
        bst.add(5)
        bst.add(4)
        self.assertEqual(bst.root.preorder_traversal(), [5, 4])

    def test_larger_numer_should_be_added_to_the_right_side_of_tree(self):
        bst = BinarySearchTree()
        bst.add(5)
        bst.add(6)
        self.assertEqual(bst.root.preorder_traversal(), [5, 6])

    def test_multiple_small_numbers_should_be_nested_to_left(self):
        bst = BinarySearchTree()
        bst.add(5)
        bst.add(4)
        bst.add(3)
        bst.add(2)
        bst.add(1)
        self.assertEqual(bst.root.preorder_traversal(), [5, 4, 3, 2, 1])

    def test_multiple_large_numbers_should_be_nested_to_right(self):
        bst = BinarySearchTree()
        bst.add(1)
        bst.add(2)
        bst.add(3)
        bst.add(4)
        bst.add(5)
        self.assertEqual(bst.root.preorder_traversal(), [1, 2, 3, 4, 5])

    def test_mixed_numbers_should_be_in_correct_order_in_the_tree(self):
        #          5
        #       2     8
        #     4     7   9
        #   3
        #
        #
        #
        bst = BinarySearchTree()
        bst.add(5)
        bst.add(2)
        bst.add(4)
        bst.add(3)
        bst.add(8)
        bst.add(7)
        bst.add(9)
        self.assertEqual(bst.root.preorder_traversal(), [5, 2, 4, 3, 8, 7, 9])


if __name__ == '__main__':
    unittest.main()
