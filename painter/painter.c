#include "painter.h"
#include "log.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int max_screen_length = 80;

void set_screen(int value) {
    max_screen_length = value > 0 ? value : max_screen_length;
}

int get_screen() {
    return max_screen_length;
}

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

void get_table(painter_t* painter, int index) {
    int main, aux;
    if(index != -1) {
        main = strlen(painter->list_main[index]);
        aux = strlen(painter->list_aux[index]);
        painter->max_table[index] = main > aux ? main + 4: aux + 4;
    } else {
        for(int i = 0; i < painter->index; i++) {
            main = strlen(painter->list_main[i]);
            aux = strlen(painter->list_aux[i]);
            painter->max_table[i] = main > aux ? main + 4: aux + 4;
        }
    }
}

painter_t* init_painter(type_t type, int length, const char* head) {
    painter_t* painter = (painter_t*)malloc(sizeof(painter_t));
    int clength = length;
    painter->index = 0;
    if(type > 1) {
        clength = clength + 1;
        painter->index = 1;
        switch(type) {
            case FIFO: 
                
        }
    }
    if(type == LIST_DOUBLE)
        painter->list_aux = (char**)malloc(sizeof(char*) * clength);
    else painter->list_aux = NULL;
    painter->list_main = (char**)malloc(sizeof(char*) * clength);
    painter->max_table = (int*)malloc(sizeof(int) * clength);
    painter->head = NULL;
    painter->type = type;
    painter->length = clength;
    return painter;
}

void destroy_painter(painter_t* painter) {
    free(painter->list_main);
    free(painter->list_aux);
    free(painter->max_table);
    free(painter->head);
    free(painter);
}

int reset_type(painter_t* painter, type_t type) {
    if(painter == NULL)
        return 0;
    painter->type = type;
    return 1;
}

int reset_length(painter_t* painter, int length) {
    if(painter == NULL)
        return 0;
    painter->length = length;
    return 1;
}

int reset_list(painter_t* painter, char** list, int sec) {
    if(painter == NULL)
        return 0;
    if(sec == 1) {
        if(painter->type != LIST_DOUBLE) {
            debug("get the wrong type, when want to set the list aux")            
            return 0;
        }
    }
    if(sec == 1)
        painter->list_aux = list;
    else
        painter->list_main = list;
    get_table(painter, -1);
    return 1;
}

// int add_item(void)

/*
 * paint
 */
void paint(painter_t* painter) {
    if(painter == NULL) return 0;

    switch(painter->type) {
        case LIST: break;
        case LIST_DOUBLE: break;
        case FIFO: break;
        case FIFO_RE: break;
        case STACK: break;
        case STACK_RE: break;
        case HEAD: 
            if(painter->head == NULL) {
                debug("use the type head, but not set the haed");
                return 0;
            }
            break;
    }
}

// /*
//  * use the format to alien to the left
//  */
// int paint_main(char** list, int* len_self, int* len_main, int count) {
//   return 0;  
// }
//
// /*
//  * paint of list
//  */
// int paint_list(char** list, int count, int index) {
//     return 0;
// }
//
// int paint_list_with_head(char** list, int count, int index) {
//   return 0;  
// }
//
// int paint_list_double_line(char** list, int count, int index) {
//   return 0;  
// }
//
// /*
//  * paint of fifo
//  */
// int paint_fifo(char** list, int count) {
//     return 0;
// }
//
// int paint_fifo_reverse(char** list, int count) {
//   return 0;
// }
//
// /*
//  * paint of stack
//  */
// int paint_stack(char** list, int count) {
//     return 0;
// }
//
// int paint_stack_reverse(char** list, int count) {
//   return 0;
// }
//
// /*
//  * others
//  */
// int paint_string(int* list, char* start, int count) {
//     return 0;
// }
