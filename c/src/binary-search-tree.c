#include "include/binary-search-tree.h"
#include <stdlib.h>

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
    }
}
