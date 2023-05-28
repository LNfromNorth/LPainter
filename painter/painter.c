#include "painter.h"
#include "log.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define draw_ud(list, count) \
    for(int i = 0; i < count; i++) { \
        printf("+"); \
        for(int j = 0; j < list[i]; j++) { \ printf("-"); \
        } \
    } \ printf("+");


static int max_screen_length = 80;

void set_screen(int value) {
    debug("reset the max screen length of window");
    max_screen_length = value > 0 ? value : max_screen_length;
}

int get_screen() {
    debug("get the max screen length of window");
    return max_screen_length;
}

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
    int main;
    int aux = 0;
    if(index < -1) {
        main = strlen(painter->list_main[index]);
        aux = strlen(painter->list_aux[index]);
        painter->max_table[index] = main > aux ? main + 4: aux + 4;
    } else {
        int i = (painter->type > 1) ? 0 : 1;
        for(; i < painter->length; i++) {
            main = strlen(painter->list_main[i]);
            if(painter->type == LIST_DOUBLE && painter->aux_set == 1)
                aux = strlen(painter->list_aux[i]);
            painter->max_table[i] = main > aux ? main + 4: aux + 4;
        }
    }
}

painter_t* init_painter(type_t type, int length, char* head) {
    // assert the value
    assert(type >= 0 && type <= 6);
    assert(length > 0);

    painter_t* painter = (painter_t*)malloc(sizeof(painter_t));

    // double list init the aux list
    if(type == LIST_DOUBLE)
        painter->list_aux = (char**)malloc(sizeof(char*) * (length + 1));
    else painter->list_aux = NULL;
    painter->list_main = (char**)malloc(sizeof(char*) * (length + 1));
    painter->max_table = (int*)malloc(sizeof(int) * (length + 1));

    painter->aux_set = 0;
    painter->length = length + 1;
    painter->index = 1;

    reset_type(painter, type, head);

    return painter;
}

void destroy_painter(painter_t* painter) {
    for(int i = 0; i < painter->index; i++) {
        free(painter->list_main[i]);
        free(painter->list_aux[i]);
    }

    free(painter->list_main);
    free(painter->list_aux);

    free(painter->max_table);
    free(painter->head);

    free(painter);
}

int reset_type(painter_t* painter, type_t type, char* head) {
    if(painter == NULL)
        return 0;

    switch(type) {
        case FIFO: 
        case FIFO_RE:
            painter->list_main[0] = "head>"; 
            painter->head = "head>";
            break;
        case STACK:
        case STACK_RE:
            painter->list_main[0] = "top>"; 
            painter->head = "top>";
            break;
        case HEAD:
            painter->list_main[0] = head; 
            painter->head = head; break; 
        default:
            painter->list_main[0] = NULL;
            painter->head = NULL;
            break;
    }

    painter->type = type;

    return 1;
}

int reset_length(painter_t* painter, int length) {
    if(painter == NULL)
        return 0;

    char** temp = painter->list_main;
    char** atemp = painter->list_aux;
    int* ttemp = painter->max_table;

    painter->list_main = (char**)malloc(sizeof(char*) * (length + 1));
    painter->max_table = (int*)malloc(sizeof(int) * (length + 1));
    if(painter->type == LIST_DOUBLE)
        painter->list_aux = (char**)malloc(sizeof(char*) * (length + 1));

    for(int i = 0; i < painter->length; ++i) {
        painter->max_table[i] = ttemp[i];
        painter->list_main[i] = temp[i];
        if(painter->type == LIST_DOUBLE) {
            painter->list_aux[i] = atemp[i];
        }
    }

    painter->length = length + 1;
    return 1;
}

int reset_list(painter_t* painter, char** list, int sec) {
    if(painter == NULL)
        return 0;

    if(sec == 1) {
        painter->aux_set = 1;
        if(painter->type != LIST_DOUBLE) {
            debug("get the wrong type, when want to set the list aux");
            return 0;
        }
    }

    for(int j = 0, i = 1; i < painter->length; ++j, ++i) {
        char* item = (char*)malloc(sizeof(char) * strlen(list[j]));
        strncpy(item, list[j], strlen(list[j]));
        if(sec == 1) painter->list_aux[i] = item;
        else painter->list_main[i] = item;
    }
    painter->index = painter->length;
    get_table(painter, -1);
    return 1;
}

// int add_item(void)

/*
 * paint
 */
void paint(painter_t* painter) {
    if(painter == NULL) return;

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
                return;
            }
            break;
    }
}


