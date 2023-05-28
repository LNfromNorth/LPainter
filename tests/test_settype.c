#include <stdio.h>
#include "painter.h"

int main(int argc, char** argv) {
    painter_t* painter = init_painter(LIST, 3, NULL);
    printf("head: %s \n", painter->head);
    reset_type(painter, FIFO, NULL);
    printf("head: %s \n", painter->head);
    reset_type(painter, STACK, NULL);
    printf("head: %s \n", painter->head);
    reset_type(painter, HEAD, "hello");
    printf("head: %s \n", painter->head);
    return 0;
}
