#include <stdlib.h>
#include "include/node.h"

node_s* create_node(int value)
{
    node_s* node = (node_s*)malloc(sizeof(node_s));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


node_s* insert_right(node_s* parent, int value)
{
    parent->right = create_node(value);
    return parent->right;
}

node_s* insert_left(node_s* parent, int value)
{
    parent->left = create_node(value);
    return parent->left;
}

void free_nodes(node_s** root)
{
    if (*root == NULL)
    {
        return;
    }

    free_nodes(&(*root)->right);
    free_nodes(&(*root)->left);

    free(*root);
    *root = NULL;
}
