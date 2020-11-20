#include <memory.h>
#include "include/clist.h"


clist_s* clist_init(size_t size)
{
    clist_s* list = calloc(1, sizeof(clist_s));
    list->capacity = size * 2;
    list->data = calloc(list->capacity, 4);
    return list;
}

void clist_add(clist_s* clist, int element)
{
    if (clist->size == clist->capacity)
    {
        size_t newSize = clist->capacity * 2;
        clist->data = realloc(clist->data, newSize);
        clist->capacity = newSize;
    }
    clist->data[clist->size++] = element;
}


void clist_free(clist_s** clist)
{
    clist_s* list = *clist;
    list->size = 0;
    list->capacity = 0;
    free(list->data);
    list->data = NULL;
    free(list);
    *clist = NULL;
}
