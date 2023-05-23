#include "painter.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define draw_ud(list, count) \
    for(int i = 0; i < count; i++) { \
        printf("+"); \
        for(int j = 0; j < list[i]; j++) { \
            printf("-"); \
        } \
    } \
    printf("+");

#define draw_list(list, count, index) \
    for(int i = 0; i < count; i++) { \
        printf("|"); \
        if(index == i) \
            printf("  \33[44m%s\33[0m  ", list[i]); \
        else \
            printf("  %s  ", list[i]); \
    } \
    printf("|");


int int_format(char*** char_list, int* in_list, int count) {
    char** tlist = (char**)malloc(count * sizeof(char*));
    for(int i = 0; i < count; i++) {
        int num = in_list[i];
        char rcnum[10];
        char cnum[10];
        int pos = 0;
        if(num == 0) rcnum[pos++] = '0';
        while(num != 0) {
            rcnum[pos++] = (num % 10) + '0';
            num = num / 10;
        }
        for(int j = 0; j <= pos-1; j++) {
            cnum[j] = rcnum[pos - 1 - j];
        }
        cnum[pos] = '\0';
        char* item = (char*)malloc(pos * sizeof(char));
        strncpy(item, cnum, pos);
        tlist[i] = item;
    }
    *char_list = tlist;
    return 0;
}

int float_format() {
    return 0;
}

int paint_list(char** list, int count, int index) {
    int item_length[count];
    for(int i = 0; i < count; i++) {
        item_length[i] = strlen(list[i]) + 4;
    }
    draw_ud_list(item_length, count);
    draw_list_list(list, count, index);
    draw_ud_list(item_length, count);
    return 0;
}

int paint_fifo(char** list, int count) {
    int item_length[count];
    for(int i = 0; i < count; i++) {
        item_length[i] = strlen(list[i]) + 4;
    }
    draw_ud_fifo(item_length, count);
    draw_list_fifo(list, count);
    draw_ud_fifo(item_length, count);
    return 0;
}

int paint_stack(char** list, int count) {
    int item_length[count];
    for(int i = 0; i < count; i++) {
        item_length[i] = strlen(list[i]) + 4;
    }
    draw_ud_stack(item_length, count);
    draw_list_stack(list, count);
    draw_ud_stack(item_length, count);
    return 0;
}

int paint_lru(int* list, int* use, int count) {
    char** list_main;
    char** list_use;
    int_format(&list_main, list, count);
    int_format(&list_use, use, count);
    int item_length_main[count];
    int item_length_use[count];
    for(int i = 0; i < count; i++) {
        item_length_main[i] = strlen(list_main[i]) + 4;
    }
    for(int i = 0; i < count; i++) {
        item_length_use[i] = strlen(list_use[i]) + 4;
    }
    draw_ud_lru(item_length_main, count);
    draw_list_lru_mem(list_main, count);
    draw_ud_lru(item_length_main, count);
    draw_ud_lru(item_length_use, count);
    draw_list_lru_use(list_use, count);
    draw_ud_lru(item_length_use, count);
    return 0;
}

void paint(int* list, int count, int type, int index) {
    char** char_list;
    int_format(&char_list, list, count);
    switch(type) {
        case(1):
            paint_list(char_list, count, index);
            break;
        case(2):
            paint_fifo(char_list, count);
            break;
        case(3):
            paint_stack(char_list, count);
            break;
        default:
            printf("wrong para get!\n");
            break;
    }
}
