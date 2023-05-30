#include <stdio.h>
#include "painter.h"

int main() {
    char* ilist[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};   
    painter_t* plist = init_painter(LIST, 9, NULL);
    reset_list(plist, ilist, 0);
    paint(plist);
    return 0;
}
