#ifndef _LIB_H
#define _LIB_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>



typedef struct Link {
    struct Link *next;
    int data;
} Link;


extern Link* ll_create(void);
extern void ll_append(Link *head, int data);



#endif // _LIB_H
