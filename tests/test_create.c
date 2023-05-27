#include <stdio.h>
#include "painter.h"

int main() {
    painter_t* painter1 = init_painter(LIST, 10, NULL);
    printf("%d\n", painter1->length);
    printf("%d\n", painter1->index);

    painter_t* painter2 = init_painter(FIFO, 10, NULL);
    printf("%d\n", painter2->length);
    printf("%d\n", painter2->index);
    printf("%s\n", painter2->list_main[0]);
    printf("%s\n", painter2->head);

    painter_t* painter3 = init_painter(STACK, 10, NULL);
    printf("%d\n", painter3->length);
    printf("%d\n", painter3->index);
    printf("%s\n", painter3->list_main[0]);
    printf("%s\n", painter3->head);

    painter_t* painter4 = init_painter(HEAD, 10, "hello");
    printf("%d\n", painter4->length);
    printf("%d\n", painter4->index);
    printf("%s\n", painter4->list_main[0]);
    printf("%s\n", painter4->head);

    return 0;
}
