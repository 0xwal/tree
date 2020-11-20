#include <stdlib.h>
#include "include/node.h"

node_s* node_create(int value)
{
    node_s* node = (node_s*)malloc(sizeof(node_s));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


node_s* node_insert_right(node_s* parent, int value)
{
    parent->right = node_create(value);
    return parent->right;
}

node_s* node_insert_left(node_s* parent, int value)
{
    parent->left = node_create(value);
    return parent->left;
}

void node_destroy(node_s** root)
{
    if (*root == NULL)
    {
        return;
    }

    node_destroy(&(*root)->right);
    node_destroy(&(*root)->left);

    free(*root);
    *root = NULL;
}
