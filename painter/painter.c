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

int int_format(char*** char_list, int* in_list, int count) {
    char** tlist = (char**)malloc(count * sizeof(char*));
    for(int i = 0; i < count; i++) {
        int num = in_list[i];
        int neg = 0;
        char rcnum[100];
        char cnum[100];
        int pos = 0;
        // test if the num is neg
        if(num < 0) {
            num = -num;
            neg = 1;
        }
        if(num == 0) rcnum[pos++] = '0';
        while(num != 0) {
            rcnum[pos++] = (num % 10) + '0';
            num = num / 10;
        }
        int k = 0;
        if(neg == 1) cnum[k++] = '-';
        for(int j = 0; j <= pos-1; j++) {
            cnum[k++] = rcnum[pos - 1 - j];
        }
        cnum[k] = '\0';
        char* item = (char*)malloc(k * sizeof(char));
        strncpy(item, cnum, k);
        tlist[i] = item;
    }
    *char_list = tlist;
    return 0;
}

int float_format(char*** list, char* format, float* fo_list, int count) {
    // TODO
    char** tlist = (char**)malloc(count * sizeof(char*));
    for(int i = 0; i < count; i++) {
        char cflo[10];
        sprintf(cflo, format, fo_list[i]);
        int length = strlen(cflo);
        char* item = (char*)malloc(length * sizeof(char));
        strncpy(item, cflo, length);
        tlist[i] = item;
    }
    *list = tlist;
    return 0;
}

/*
 * use the format to alien to the left
 */
int paint_main(char** list, int* len_self, int* len_main, int count) {
  return 0;  
}

/*
 * paint of list
 */
int paint_list(char** list, int count, int index) {
    int item_length[count];
    for(int i = 0; i < count; i++) {
        item_length[i] = strlen(list[i]) + 4;
    }
    return 0;
}

int paint_list_with_head(char** list, int count, int index) {
  return 0;  
}

int paint_list_double_line(char** list, int count, int index) {
  return 0;  
}

/*
 * paint of fifo
 */
int paint_fifo(char** list, int count) {
    int item_length[count];
    for(int i = 0; i < count; i++) {
        item_length[i] = strlen(list[i]) + 4;
    }
    return 0;
}

int paint_fifo_reverse(char** list, int count) {
  return 0;
}

/*
 * paint of stack
 */
int paint_stack(char** list, int count) {
    int item_length[count];
    for(int i = 0; i < count; i++) {
        item_length[i] = strlen(list[i]) + 4;
    }
    return 0;
}

int paint_stack_reverse(char** list, int count) {
  return 0;
}

/*
 * others
 */
int paint_string(int* list, char* start, int count) {
    char** list_main;
    char** list_use;
    int_format(&list_main, list, count);
    int item_length_main[count];
    int item_length_use[count];
    for(int i = 0; i < count; i++) {
        item_length_main[i] = strlen(list_main[i]) + 4;
    }
    for(int i = 0; i < count; i++) {
        item_length_use[i] = strlen(list_use[i]) + 4;
    }
    return 0;
}
