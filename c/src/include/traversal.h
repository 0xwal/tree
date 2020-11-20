#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "clist.h"

#ifdef __cplusplus
extern "C" {
#endif

void inorder_traversal(node_s* root, clist_s* list);
void preorder_traversal(node_s* root, clist_s* list);
void postorder_traversal(node_s* root, clist_s* list);

#ifdef __cplusplus
}
#endif
#endif //TRAVERSAL_H
