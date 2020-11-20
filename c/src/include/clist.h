#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

typedef struct clist clist_s;
struct clist
{
    int size;
    int* data;
    size_t capacity;
};

#ifdef __cplusplus
extern "C" {
#endif

clist_s* clist_init(size_t size);

void clist_add(clist_s* clist, int element);

void clist_free(clist_s** clist);

#ifdef __cplusplus
}
#endif


#endif //CLIST_H
