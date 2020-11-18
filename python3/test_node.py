import unittest

from node import Node


class TestNode(unittest.TestCase):

    def setUp(self) -> None:
        self.rootNode = Node(0)

    def test_able_to_insert_right(self):
        self.assertIsNone(self.rootNode.right)
        self.rootNode.insert_right(2)
        self.assertIsNotNone(self.rootNode.right)
        self.assertEqual(self.rootNode.right.data, 2)

    def test_able_to_insert_left(self):
        self.assertIsNone(self.rootNode.left)
        self.rootNode.insert_left(2)
        self.assertIsNotNone(self.rootNode.left)
        self.assertEqual(self.rootNode.left.data, 2)


if __name__ == '__main__':
    unittest.main()
