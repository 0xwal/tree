

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "node.h"

typedef struct binary_search_tree binary_search_tree_s;
struct binary_search_tree
{
    node_s* root;
};

#ifdef __cplusplus
extern "C" {
#endif


binary_search_tree_s* bst_create();

void bst_add(binary_search_tree_s* bst, int value);

int bst_find(binary_search_tree_s* bst, int value);

void bst_destroy(binary_search_tree_s** bst);

#ifdef __cplusplus
}
#endif
#endif //BINARY_SEARCH_TREE_H
