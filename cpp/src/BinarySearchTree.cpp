
#include <memory>
#include <iostream>
#include "include/BinarySearchTree.hpp"

std::shared_ptr<Node> BinarySearchTree::root() const
{
    return m_root;
}

void BinarySearchTree::add(int value)
{
    if (!m_root)
    {
        m_root = std::make_shared<Node>(value);
        return;
    }

    std::shared_ptr<Node> node = root();
    while (true)
    {
        if (value > node->value)
        {
            if (node->right != nullptr)
            {
                node = node->right;
                continue;
            }
            node->right = std::make_shared<Node>(value);
            break;
        }
        else
        {
            if (node->left != nullptr)
            {
                node = node->left;
                continue;
            }

            node->left = std::make_shared<Node>(value);
            break;
        }
    }
}

int BinarySearchTree::find(int value) const
{
    std::shared_ptr<Node> node = this->root();
    if (node == nullptr)
    {
        return -1;
    }

    int iteration = 0;
    while (true)
    {
        if (value == node->value)
        {
            return iteration;
        }

        iteration++;

        if (value > node->value && node->right != nullptr)
        {
            node = node->right;
            continue;
        }
        else
        {
            if (node->left != nullptr)
            {
                node = node->left;
                continue;
            }
        }

        break;
    }
    return -1;
}
