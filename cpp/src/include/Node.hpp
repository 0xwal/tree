
#ifndef NODE_HPP
#define NODE_HPP

#include <list>

class Node
{
public:

    int value;

    std::shared_ptr<Node> right;
    std::shared_ptr<Node> left;

    explicit Node(int value);

    std::shared_ptr<Node> insertRight(int v);

    std::shared_ptr<Node> insertLeft(int v);

    std::list<int> preorderTraversal() const;
    std::list<int> inorderTraversal() const;
    std::list<int> postorderTraversal() const;

};

#endif //NODE_HPP
