#include <stdio.h>
#include "painter.h"

int main() {
    char* list[] = {"hello", "world", "lnfromnorth"};
    painter_t* painter = init_painter(FIFO, 3, NULL);
    reset_list(painter, list, 0);
    paint(painter);
}
