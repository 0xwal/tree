package tree;

import java.util.ArrayList;
import java.util.List;

public class Node
{
    private final int _value;
    private Node _right;
    private Node _left;

    public Node(int value)
    {
        this._value = value;
    }

    public Node getRight()
    {
        return this._right;
    }

    public Node getLeft()
    {
        return this._left;
    }

    public int getValue()
    {
        return this._value;
    }

    public Node setRightNode(int value)
    {
        this._right = new Node(value);
        return this._right;
    }

    public Node setLeftNode(int value)
    {
        this._left = new Node(value);
        return this._left;
    }

    public List<Integer> preorderTraversal()
    {
        List<Integer> list = new ArrayList<>();
        list.add(this._value);
        if (getLeft() != null) {
            list.addAll(this.getLeft().preorderTraversal());
        }

        if (getRight() != null) {
            list.addAll(this.getRight().preorderTraversal());
        }
        return list;
    }

    public List<Integer> inorderTraversal()
    {
        List<Integer> list = new ArrayList<>();
        if (getLeft() != null) {
            list.addAll(this.getLeft().inorderTraversal());
        }

        list.add(this._value);
        if (getRight() != null) {
            list.addAll(this.getRight().inorderTraversal());
        }
        return list;
    }

    public List<Integer> postorderTraversal()
    {
        List<Integer> list = new ArrayList<>();
        if (getLeft() != null) {
            list.addAll(this.getLeft().postorderTraversal());
        }

        if (getRight() != null) {
            list.addAll(this.getRight().postorderTraversal());
        }
        list.add(this._value);
        return list;
    }
}
