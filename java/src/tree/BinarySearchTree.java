package tree;

public class BinarySearchTree
{
    private Node _root;

    public Node getRoot()
    {
        return this._root;
    }

    public void add(int value)
    {
        if (this._root == null) {
            this._root = new Node(value);
            return;
        }

        Node node = this._root;
        while (true) {
            if (value > node.getValue()) {
                if (node.getRight() != null) {
                    node = node.getRight();
                    continue;
                }
                node.setRightNode(value);
            }
            else {
                if (node.getLeft() != null) {
                    node = node.getLeft();
                    continue;
                }
                node.setLeftNode(value);
            }
            break;
        }
    }

    public int find(int value)
    {
        Node node = getRoot();

        if (node == null) {
            return -1;
        }

        int iteration = 0;
        while (true) {
            if (value == node.getValue()) {
                return iteration;
            }

            if (value > node.getValue() && node.getRight() != null) {
                node = node.getRight();
                iteration++;
                continue;
            }
            else {
                if (node.getLeft() != null) {
                    node = node.getLeft();
                    iteration++;
                    continue;
                }
            }

            if (node.getRight() == null) {
                break;
            }
        }
        return -1;
    }
}
