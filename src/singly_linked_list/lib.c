#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "./lib.h"


static Link* _new_node(int data) {
    Link *link = malloc(sizeof(Link));
    link->data = data;
    link->next = NULL;
    return link;
}

Link* ll_create(void) {
    Link *head = _new_node(0);
    return head;
}

void ll_append(Link *head, int data) {

    Link *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    Link *new = _new_node(data);
    current->next = new;

}



