#include <stdio.h>
#include "painter.h"

int main() {
    char* list[] = {"hello", "world", "lnfromnorth"};
    char* list2[] = {"2", "3", "4"};
    char* list3[] = {"hello", "world", "lnfromnorth", "hello", "world", "lnfromnorth", "hello", "world", "lnfromnorth", "hello", "world", "lnfromnorth"};

    painter_t* plist = init_painter(LIST, 3, NULL);
    painter_t* plistl = init_painter(LIST, 12, NULL);
    painter_t* plistd = init_painter(LIST_DOUBLE, 3, NULL);
    painter_t* pfifo = init_painter(FIFO, 3, NULL);
    painter_t* pstack = init_painter(STACK, 3, NULL);
    painter_t* phead = init_painter(HEAD, 3, "head is this");

    reset_list(plist, list, 0);
    reset_list(plistl, list3, 0);
    reset_list(plistd, list, 0);
    reset_list(plistd, list2, 1);
    reset_list(pfifo, list, 0);
    reset_list(pstack, list, 0);
    reset_list(phead, list, 0);

    printf("list:\n");
    paint(plist);
    printf("list_long:\n");
    paint(plistl);
    printf("list_double:\n");
    paint(plistd);
    printf("fifo:\n");
    paint(pfifo);
    printf("stack:\n");
    paint(pstack);
    printf("head:\n");
    paint(phead);

    return 0;
}
