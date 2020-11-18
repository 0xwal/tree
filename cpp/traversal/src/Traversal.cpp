

#include "include/Traversal.hpp"

//TODO refactor it all, covered in unit tests
std::vector<int> Traversal::inorder(Node* root)
{
    if (root == nullptr)
    {
        return std::vector<int>();
    }

    std::vector<int> numbers = inorder(root->left);

    numbers.push_back(root->value);

    const std::vector<int>& vector = inorder(root->right);

    for (int i : vector)
    {
        numbers.push_back(i);
    }

    return numbers;
}

std::vector<int> Traversal::preorder(Node* root)
{
    if (root == nullptr)
    {
        return std::vector<int>();
    }

    std::vector<int> numbers;

    numbers.push_back(root->value);
    const std::vector<int>& leftNumbers = preorder(root->left);

    for (int i: leftNumbers)
    {
        numbers.push_back(i);
    }

    const std::vector<int>& vector = preorder(root->right);

    for (int i : vector)
    {
        numbers.push_back(i);
    }

    return numbers;
}

std::vector<int> Traversal::postorder(Node* root)
{
    if (root == nullptr)
    {
        return std::vector<int>();
    }

    std::vector<int> numbers;


    const std::vector<int>& leftNumbers = postorder(root->left);

    numbers.reserve(leftNumbers.size());

    for (int i: leftNumbers)
    {
        numbers.push_back(i);
    }


    const std::vector<int>& vector = postorder(root->right);

    for (int i : vector)
    {
        numbers.push_back(i);
    }

    numbers.push_back(root->value);
    return numbers;
}
