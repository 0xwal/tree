#include <stdio.h>
#include "include/node.h"
#include "include/traversal.h"


void inorder_traversal(node_s* root, clist_s* list)
{
    if (root == NULL)
    {
        return;
    }

    inorder_traversal(root->left, list);
    clist_add(list, root->data);
    inorder_traversal(root->right, list);

}

void preorder_traversal(node_s* root, clist_s* list)
{
    if (root == NULL)
    {
        return;
    }

    clist_add(list, root->data);
    preorder_traversal(root->left, list);
    preorder_traversal(root->right, list);
}

void postorder_traversal(node_s* root, clist_s* list)
{
    if (root == NULL)
    {
        return;
    }

    postorder_traversal(root->left, list);
    postorder_traversal(root->right, list);
    clist_add(list, root->data);
}
