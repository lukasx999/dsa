#include <stdio.h>
#include <stdlib.h>

#include "./lib.h"



int main(void) {

    List list = list_new(2, 5);
    list_push(&list, 1);
    list_push(&list, 2);
    list_push(&list, 3);
    list_push(&list, 4);
    list_push(&list, 5);
    list_push(&list, 6);

    list_remove(&list, 2);
    list_insert_before(&list, 1, 45);
    list_insert_before(&list, 0, 123);



    list_print(&list);

    list_destroy(&list);


    return EXIT_SUCCESS;

}
