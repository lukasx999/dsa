#ifndef _LIB_H
#define _LIB_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


typedef struct {
    int *items;
    size_t size;
    size_t _capacity;
    size_t _growth_factor;
} List;


extern List list_new(size_t growth_factor, size_t initial_capacity);
extern void list_push(List *list, int item);
extern void list_remove(List *list, size_t index);
extern void list_insert_before(List *list, size_t index, int item);
extern void list_print(List *list);
extern void list_destroy(List *list);






#endif // _LIB_H
