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

void node_preorder_traversal(node_s* root, clist_s* list)
{
    if (root == NULL)
    {
        return;
    }

    clist_add(list, root->data);
    node_preorder_traversal(root->left, list);
    node_preorder_traversal(root->right, list);
}

void node_inorder_traversal(node_s* root, clist_s* list)
{
    if (root == NULL)
    {
        return;
    }

    node_inorder_traversal(root->left, list);
    clist_add(list, root->data);
    node_inorder_traversal(root->right, list);
}

void node_postorder_traversal(node_s* root, clist_s* list)
{
    if (root == NULL)
    {
        return;
    }

    node_postorder_traversal(root->left, list);
    node_postorder_traversal(root->right, list);
    clist_add(list, root->data);
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
