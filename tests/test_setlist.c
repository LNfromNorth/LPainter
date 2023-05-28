#include <stdio.h>
#include "painter.h"

int main(int argc, char** argv) {
    char* list[3] = {"hello", "world", "lnfromnorth"};
    char* dlist[3] = {"100000", "2", "3"};

    painter_t* plist = init_painter(LIST, 3, NULL);
    painter_t* pdlist = init_painter(LIST_DOUBLE, 3, NULL);
    painter_t* pfifo = init_painter(FIFO, 3, NULL);

    reset_list(plist, list, 0);
    reset_list(pdlist, list, 0);
    reset_list(pdlist, dlist, 1);
    reset_list(pfifo, list, 0);

    for(int i = 0; i < plist->length; i++) {
        printf("%d:", plist->max_table[i]);
        printf("%s ", plist->list_main[i]);
    }
    printf("\n");
    for(int i = 0; i < pdlist->length; i++) {
        printf("%d:", pdlist->max_table[i]);
        printf("%s ", pdlist->list_aux[i]);
        printf("%s ", pdlist->list_main[i]);
    }
    printf("\n");
    for(int i = 0; i < pfifo->length; i++) {
        printf("%d:", pfifo->max_table[i]);
        printf("%s ", pfifo->list_main[i]);
    }
    printf("\n");

    return 0;
}
