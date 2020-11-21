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

    def test_larger_number_should_be_added_to_the_right_side_of_tree(self):
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
        #      2        9
        #    1   3    7   10
        #  0        6   8
        #
        #
        #
        bst = BinarySearchTree()
        bst.add(5)
        bst.add(2)
        bst.add(1)
        bst.add(3)
        bst.add(9)
        bst.add(10)
        bst.add(7)
        bst.add(6)
        bst.add(8)
        bst.add(0)
        self.assertEqual(bst.root.preorder_traversal(), [5, 2, 1, 0, 3, 9, 7, 6, 8, 10])

    def test_find_an_existent_value(self):
        #          5
        #      2        9
        #    1   3    7   10
        #  0        6   8
        #
        #
        #
        bst = BinarySearchTree()
        bst.add(5)
        bst.add(2)
        bst.add(1)
        bst.add(3)
        bst.add(9)
        bst.add(10)
        bst.add(7)
        bst.add(6)
        bst.add(8)
        bst.add(0)
        self.assertEqual(bst.find(5), 0)
        self.assertEqual(bst.find(9), 1)
        self.assertEqual(bst.find(7), 2)
        self.assertEqual(bst.find(2), 1)
        self.assertEqual(bst.find(3), 2)
        self.assertEqual(bst.find(0), 3)
        self.assertEqual(bst.find(8), 3)

    def test_find_value_that_does_not_exist(self):
        bst = BinarySearchTree()
        bst.add(5)
        self.assertEqual(bst.find(100), -1)

    def test_try_to_find_a_value_with_bst_that_has_no_node(self):
        bst = BinarySearchTree()
        self.assertEqual(bst.find(100), -1)


if __name__ == '__main__':
    unittest.main()
