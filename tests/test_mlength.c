#include <stdio.h>
#include "painter.h"

int main() {
    printf("start value %d\n", get_screen());
    set_screen(100);
    printf("after value %d\n", get_screen());
    return 0;
}
