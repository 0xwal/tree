#include "include/binary-search-tree.h"
#include <stdlib.h>
#include <printf.h>

void bst_internal_add(node_s* currentNode, int value);

binary_search_tree_s* bst_create()
{
    binary_search_tree_s* bst = calloc(1, sizeof(binary_search_tree_s));
    return bst;
}

void bst_add(binary_search_tree_s* bst, int value)
{
    if (bst->root == NULL)
    {
        bst->root = (node_s*)calloc(1, sizeof(node_s));
        bst->root->data = value;
        return;
    }

    bst_internal_add(bst->root, value);
}

void bst_internal_add(node_s* currentNode, int value)
{
    int currentNodeValue = currentNode->data;

    if (value > currentNodeValue)
    {
        if (currentNode->right != NULL)
        {
            bst_internal_add(currentNode->right, value);
            return;
        }
        currentNode->right = calloc(1, sizeof(node_s));
        currentNode->right->data = value;
        return;
    }

    if (currentNode->left != NULL)
    {
        bst_internal_add(currentNode->left, value);
        return;
    }
    currentNode->left = calloc(1, sizeof(node_s));
    currentNode->left->data = value;
}
