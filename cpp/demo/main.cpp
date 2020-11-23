#include <iostream>
#include <BinarySearchTree.hpp>

int main()
{
    BinarySearchTree binarySearchTree;
    binarySearchTree.add(2);
    binarySearchTree.add(1);
    binarySearchTree.add(4);
    binarySearchTree.add(3);


    for (int i: binarySearchTree.root()->preorderTraversal())
    {
        std::cout << i << std::endl;
    }

    return 0;
}

