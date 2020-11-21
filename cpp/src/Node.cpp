#include <memory>
#include "include/Node.hpp"

Node::Node(int value) : value(value), right(nullptr), left(nullptr)
{
}

std::shared_ptr<Node> Node::insertRight(int v)
{
    auto node = std::make_shared<Node>(v);
    right = node;
    return node;
}

std::shared_ptr<Node> Node::insertLeft(int v)
{
    left = std::make_shared<Node>(v);
    return left;
}

std::list<int> Node::preorderTraversal() const
{
    std::list<int> list;

    list.push_back(value);

    if (left != nullptr)
    {
        std::list<int> leftValues = left->preorderTraversal();
        list.merge(leftValues);
    }

    if (right != nullptr)
    {
        std::list<int> rightValues = right->preorderTraversal();
        for (int i: rightValues)
        {
            list.push_back(i);
        }
    }
    return list;
}

std::list<int> Node::inorderTraversal() const
{
    std::list<int> list;

    if (left != nullptr)
    {
        std::list<int> leftValues = left->inorderTraversal();
        list.merge(leftValues);
    }

    list.push_back(value);

    if (right != nullptr)
    {
        std::list<int> rightValues = right->inorderTraversal();
        for (int i: rightValues)
        {
            list.push_back(i);
        }
    }
    return list;
}

std::list<int> Node::postorderTraversal() const
{
    std::list<int> list;

    if (left != nullptr)
    {
        std::list<int> leftValues = left->postorderTraversal();
        list.merge(leftValues);
    }


    if (right != nullptr)
    {
        std::list<int> rightValues = right->postorderTraversal();
        for (int i: rightValues)
        {
            list.push_back(i);
        }
    }
    list.push_back(value);
    return list;
}
