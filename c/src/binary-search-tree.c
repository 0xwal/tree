#include "include/binary-search-tree.h"
#include <stdlib.h>
#include <printf.h>

void bsd_internal_add(node_s* currentNode, int value);

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

    bsd_internal_add(bst->root, value);
}

void bsd_internal_add(node_s* currentNode, int value)
{
    while (1)
    {
        if (currentNode->data < value)
        {
            if (currentNode->right != NULL)
            {
                currentNode = currentNode->right;
                continue;
            }
            currentNode->right = calloc(1, sizeof(node_s));
            currentNode->right->data = value;

            break;
        }

        if (currentNode->data > value)
        {
            if (currentNode->left != NULL)
            {
                currentNode = currentNode->left;
                continue;
            }
            currentNode->left = calloc(1, sizeof(node_s));
            currentNode->left->data = value;
            break;
        }
    }
}
