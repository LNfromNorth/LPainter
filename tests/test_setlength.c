#include <stdio.h>
#include "painter.h"

int main(int argc, char** argv) {
    char* list[3] = {"hello", "world", "lnfromnorth"};
    painter_t* painter = init_painter(LIST, 3, NULL);
    painter_t* painter2 = init_painter(LIST_DOUBLE, 3, NULL);

    reset_list(painter, list, 0);
    printf("length is %d\n", painter->length);
    for(int i = 0; i < painter->index; i++) {
        printf("%d:", painter->max_table[i]);
        printf("%s ", painter->list_main[i]);
    }
    printf("\n");
    reset_length(painter, 10);
    printf("length is %d\n", painter->length);
    for(int i = 0; i < painter->index; i++) {
        printf("%d:", painter->max_table[i]);
        printf("%s ", painter->list_main[i]);
    }
    printf("\n");

    reset_list(painter2, list, 0);
    reset_list(painter2, list, 1);
    printf("length is %d\n", painter2->length);
    for(int i = 0; i < painter2->index; i++) {
        printf("%d:", painter2->max_table[i]);
        printf("%s-", painter2->list_main[i]);
        printf("%s ", painter2->list_aux[i]);
    }
    printf("\n");

    reset_length(painter, 11);
    printf("length is %d\n", painter2->length);
    for(int i = 0; i < painter2->index; i++) {
        printf("%d:", painter2->max_table[i]);
        printf("%s-", painter2->list_main[i]);
        printf("%s ", painter2->list_aux[i]);
    }
    printf("\n");


    return 0;
}
