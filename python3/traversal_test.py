import unittest

import traversal
from node import Node

"""
    0
  3   2
5       4
"""


class Traversal(unittest.TestCase):
    def setUp(self) -> None:
        self.root = Node(0)
        inner_right = self.root.insert_right(Node(2))
        inner_right.insert_right(Node(4))
        inner_left = self.root.insert_left(Node(3))
        inner_left.insert_left(Node(5))

    def test_inorder__values_should_match_the_order(self):
        result = traversal.inorder_traversal(self.root)
        self.assertEqual(result, [5, 3, 0, 2, 4])

    def test_preorder__values_should_match_the_order(self):
        result = traversal.preorder_traversal(self.root)
        self.assertEqual(result, [0, 3, 5, 2, 4])

    def test_postorder__values_should_match_the_order(self):
        result = traversal.postorder_traversal(self.root)
        self.assertEqual(result, [5, 3, 4, 2, 0])


if __name__ == '__main__':
    unittest.main()
