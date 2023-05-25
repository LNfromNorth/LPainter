#include <stdio.h>
#include "painter.h"

int main() {
    int in_list[3] = {-12, 23, 33};
    float fo_list[3] = {2.15, 3.10, 4.56};
    char** ch_list;
    int_format(&ch_list, in_list, 3);
    for(int i = 0; i < 3; i++) {
        printf("%s ", ch_list[i]);
    }
    printf("\n");
    float_format(&ch_list, "%.2f", fo_list, 3);
    for(int i = 0; i < 3; i++) {
        printf("%s ", ch_list[i]);
    }
    printf("\n");
    return 0;
}
