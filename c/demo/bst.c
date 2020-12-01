#include <stdio.h>
#include <node.h>
#include <binary-search-tree.h>

void print_preorder_traversal(node_s* root, clist_s* list);

void print_inorder_traversal(node_s* root, clist_s* list);

void print_postorder_traversal(node_s* root, clist_s* list);

int main()
{
    node_s* root = node_create(0);

    node_s* innerRight = node_insert_right(root, 2);
    node_insert_right(innerRight, 4);
    node_insert_left(innerRight, 7);

    node_s* innerLeft = node_insert_left(root, 3);
    node_insert_right(innerLeft, 6);
    node_insert_left(innerLeft, 5);

    clist_s* list = clist_create(16);

    print_preorder_traversal(root, list);
    print_inorder_traversal(root, list);
    print_postorder_traversal(root, list);


    clist_destroy(&list);
    node_destroy(&root);

    return 0;
}

void print_preorder_traversal(node_s* root, clist_s* list)
{
    list->size = 0;
    node_preorder_traversal(root, list);

    for (int i = 0; i < list->size; ++i)
    {
        printf("%d ", *(int*)list->values[i]);
    }
    printf("\n");
}

void print_inorder_traversal(node_s* root, clist_s* list)
{
    list->size = 0;
    node_inorder_traversal(root, list);

    for (int i = 0; i < list->size; ++i)
    {
        printf("%d ", *(int*)list->values[i]);
    }
    printf("\n");
}

void print_postorder_traversal(node_s* root, clist_s* list)
{
    list->size = 0;
    node_postorder_traversal(root, list);

    for (int i = 0; i < list->size; ++i)
    {
        printf("%d ", *(int*)list->values[i]);
    }
    printf("\n");
}
