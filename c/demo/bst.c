#include <stdio.h>
#include <binary-search-tree.h>

void print_preorder_traversal(node_s* root, clist_s* list);

void print_inorder_traversal(node_s* root, clist_s* list);

void print_postorder_traversal(node_s* root, clist_s* list);

int main()
{
    binary_search_tree_s* bst = bst_create();
    bst_add(bst, 5);
    bst_add(bst, 6);
    bst_add(bst, 4);
    bst_add(bst, 3);
    bst_add(bst, 0);
    bst_add(bst, 8);
    bst_add(bst, 7);

    clist_s* list = clist_create(16);

    print_preorder_traversal(bst->root, list);
    print_inorder_traversal(bst->root, list);
    print_postorder_traversal(bst->root, list);


    clist_destroy(&list);
    bst_destroy(&bst);

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
