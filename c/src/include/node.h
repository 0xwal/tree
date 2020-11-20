#ifndef NODE_H
#define NODE_H

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


node_s* create_node(int value);
node_s* insert_right(node_s* parent, int value);
node_s* insert_left(node_s* parent, int value);
void free_nodes(node_s** root);


#ifdef __cplusplus
}
#endif


#endif //NODE_H
