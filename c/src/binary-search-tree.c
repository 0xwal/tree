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

int bst_find(binary_search_tree_s* bst, int value)
{


    node_s* node = bst->root;
    int iteration = 0;

    if (node == NULL)
    {
        return -1;
    }


    while (1)
    {

        if (node->data == value)
        {
            return iteration;
        }

        iteration++;

        if (value > node->data && node->right != NULL)
        {
            node = node->right;
            continue;
        }
        else
        {
            if (node->left != NULL)
            {
                node = node->left;
                continue;
            }
        }

        if (node->right == NULL && node->left == NULL)
        {
            break;
        }
    }

    return -1;
}

void bst_destroy(binary_search_tree_s** bst)
{
    free(*bst);
    *bst = NULL;
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
