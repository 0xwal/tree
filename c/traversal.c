#include <stdio.h>
#include <stdlib.h>
#include "node.h"

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

void inorder_traversal(node_s* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder_traversal(root->left);
    printf("%d\n", root->data);
    inorder_traversal(root->right);
}

void preorder_traversal(node_s* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d\n", root->data);
    inorder_traversal(root->left);
    inorder_traversal(root->right);
}

void postorder_traversal(node_s* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder_traversal(root->left);
    inorder_traversal(root->right);
    printf("%d\n", root->data);
}

void free_nodes(node_s* root)
{
    if (root == NULL)
    {
        return;
    }

    free_nodes(root->right);
    free_nodes(root->left);

    free(root);
}

int main()
{
    node_s* root = create_node(0);


    node_s* right = insert_right(root, 2);
    insert_right(right, 4);


    node_s* left = insert_left(root, 3);
    insert_left(left, 5);

    printf("----inorder traversal----\n");
    inorder_traversal(root);

    printf("----preorder traversal----\n");
    preorder_traversal(root);


    printf("----postorder traversal----\n");
    postorder_traversal(root);


    free_nodes(root);

    return 0;
}
