import unittest

from node import Node


class TestNode(unittest.TestCase):

    def setUp(self) -> None:
        self.root_node = Node(0)

    def test_able_to_insert_right(self):
        self.assertIsNone(self.root_node.right)
        self.root_node.insert_right(2)
        self.assertIsNotNone(self.root_node.right)
        self.assertEqual(self.root_node.right.data, 2)

    def test_able_to_insert_left(self):
        self.assertIsNone(self.root_node.left)
        self.root_node.insert_left(2)
        self.assertIsNotNone(self.root_node.left)
        self.assertEqual(self.root_node.left.data, 2)


if __name__ == '__main__':
    unittest.main()
