#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "./lib.h"



static void _list_grow(List *list) {
    list->_capacity *= list->_growth_factor;

    int *new = malloc(list->_capacity * sizeof(int));
    memcpy(new, list->items, list->size * sizeof(int));
    free(list->items);
    list->items = new;

}





List list_new(size_t growth_factor, size_t initial_capacity) {
    List list = {
        .items    = NULL,
        .size     = 0,
        ._capacity      = initial_capacity,
        ._growth_factor = growth_factor,
    };

    list.items = malloc(list._capacity * sizeof(int));

    return list;
}



#if 0

void list_push(List *list, int item) {

    if (list->size == list->_capacity) {
        list->_capacity *= list->_growth_factor;
        list->items = realloc(list->items, list->_capacity * sizeof(int));
    }

    list->items[list->size++] = item;

}

#else



void list_push(List *list, int item) {

    if (list->size == list->_capacity) {
        _list_grow(list);
    }

    list->items[list->size++] = item;

}

#endif


void list_remove(List *list, size_t index) {

    assert(index < list->size);

    void *dest = list->items + index;
    const void *src = list->items + index + 1;
    size_t n = list->size - index - 1;

    memmove(dest, src, n * sizeof(int));
    list->size--;

}

void list_insert_before(List *list, size_t index, int item) {

    assert(index < list->size);

    if (list->size == list->_capacity) {
        _list_grow(list);
    }

    void *dest = list->items + index + 1;
    const void *src = list->items + index;
    size_t n = list->size - index;
    memmove(dest, src, n * sizeof(int));
    list->items[index] = item;
    list->size++;

}


void list_print(List *list) {

    printf("[ ");
    for (size_t i=0; i < list->size-1; ++i) {
        printf("%d, ", list->items[i]);
    }
    printf("%d ]\n", list->items[list->size-1]);

}


void list_destroy(List *list) {
    free(list->items);
    list->items = NULL;
}
