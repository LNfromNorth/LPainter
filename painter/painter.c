#include "painter.h"
#include "log.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


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
    if(type == HEAD) 
        assert(head != NULL);

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
    if(painter == NULL) return 0;

    if(type == HEAD)
        assert(head != NULL);

    switch(type) {
        case FIFO: 
        case FIFO_RE:
            painter->list_main[0] = "head>"; 
            painter->head = "head>"; break;
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
    if(painter == NULL) return 0;

    assert(length > 0);

    char** temp = painter->list_main;
    char** atemp = painter->list_aux;
    int* ttemp = painter->max_table;

    painter->list_main = (char**)malloc(sizeof(char*) * (length + 1));
    painter->max_table = (int*)malloc(sizeof(int) * (length + 1));
    if(painter->type == LIST_DOUBLE)
        painter->list_aux = (char**)malloc(sizeof(char*) * (length + 1));

    int end = painter->length > length ? length + 1 : painter->length;

    for(int i = 0; i < end; ++i) {
        painter->max_table[i] = ttemp[i];
        painter->list_main[i] = temp[i];
        if(painter->type == LIST_DOUBLE) {
            painter->list_aux[i] = atemp[i];
        }
    }

    if(painter->length < length) painter->index = length + 1;

    painter->length = length + 1;
    return 1;
}

int reset_list(painter_t* painter, char** list, int sec) {
    if(painter == NULL) return 0;

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

void draw_ud(int* max, int start, int end) {
    for(int i = start; i < end; ++i) {
        printf("+");
        for(int j = 0; j < max[i]; ++j)
            printf("-");
    }
    printf("+\n");
}

void draw_text(char** list, int* max, int start, int end) {
    for(int i = start; i < end; ++i) {
        // alien to the rigth
        int space = max[i] - strlen(list[i]);
        printf("|");
        for(int j = 0; j < space / 2; ++j)
            printf(" ");
        printf("%s", list[i]);
        for(int j = 0; j < (space - space / 2); ++j)
            printf(" ");
    }
    printf("|\n");
}

/*
 * paint
 */
void paint(painter_t* painter) {
    if(painter == NULL) return;

    int start = (painter->type < 2) ? 1 : 0;
    while(start < painter->index) {
        int end = start;
        int sum = 0;
        for(end = start; end < painter->index; ++end) {
            sum += painter->max_table[end];
            if(sum > max_screen_length) break;
        }
        draw_ud(painter->max_table, start, end);
        draw_text(painter->list_main, painter->max_table, start, end);
        draw_ud(painter->max_table, start, end);
        if(painter->type == LIST_DOUBLE) {
            draw_text(painter->list_aux, painter->max_table, start, end);
            draw_ud(painter->max_table, start, end);
        }
        start = end;
    }
}
