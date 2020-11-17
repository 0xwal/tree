
#ifndef NODE_HPP
#define NODE_HPP

class Node
{
public:
    int value;
    Node* right;
    Node* left;

    explicit Node(int value) : value(value), right(nullptr), left(nullptr)
    {
    }

    Node* insertRight(int v)
    {
        Node* node = new Node(v);
        this->right = node;
        return node;
    }

    Node* insertLeft(int v)
    {
        Node* node = new Node(v);
        this->left = node;
        return node;
    }
};

#endif //NODE_HPP
