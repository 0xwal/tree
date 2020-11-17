//
// Created by mine-air on 17/11/2020.
//

#ifndef NODE_H
#define NODE_H

typedef struct node node_s;

struct node {
    int data;
    node_s* right;
    node_s* left;
};

#endif //NODE_H
