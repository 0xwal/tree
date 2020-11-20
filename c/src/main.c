#include <stdio.h>
#include "include/node.h"
#include "include/traversal.h"

int main()
{
    node_s* root = node_create(0);

    node_s* innerRight = node_insert_right(root, 2);
    node_insert_right(innerRight, 4);
    node_insert_left(innerRight, 7);

    node_s* innerLeft = node_insert_left(root, 3);
    node_insert_right(innerLeft, 6);
    node_insert_left(innerLeft, 5);

    clist_s* list = clist_init(16);

    preorder_traversal(root, list);

    for (int i = 0; i < list->size; ++i)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");

    clist_free(&list);
    node_destroy(&root);

    return 0;
}
