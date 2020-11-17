

#ifndef TRAVERSAL_HPP
#define TRAVERSAL_HPP

#include <vector>

#include "Node.hpp"

class Traversal
{

public:
    std::vector<int> inorder(Node* root);
    std::vector<int> preorder(Node* root);
    std::vector<int> postorder(Node* root);
};


#endif //TRAVERSAL_HPP
