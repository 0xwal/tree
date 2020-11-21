#ifndef NODE_H
#define NODE_H

#include <clist.h>

typedef struct node node_s;

struct node
{
    int data;
    node_s* right;
    node_s* left;
};

#ifdef __cplusplus
extern "C" {
#endif


node_s* node_create(int value);

node_s* node_insert_right(node_s* parent, int value);
node_s* node_insert_left(node_s* parent, int value);

void node_preorder_traversal(node_s* root, clist_s* list);
void node_inorder_traversal(node_s* root, clist_s* list);
void node_postorder_traversal(node_s* root, clist_s* list);

void node_destroy(node_s** root);


#ifdef __cplusplus
}
#endif


#endif //NODE_H
