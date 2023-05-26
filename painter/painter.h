#ifndef __PAINTER_H
#define __PAINTER_H

#define MAX_INT_LENGTH

// 类型描述
typedef enum {
    LIST = 0,
    LIST_DOUBLE = 1,
    FIFO = 2,
    FIFO_RE = 3,
    STACK = 4,
    STACK_RE = 5,
    HEAD = 6,
} type_t;

// 打印结构
typedef struct {
    char** list_main;   // 打印列表
    char** list_aux;    // 附属表
    int* max_table;     // 最大长度表单
    char* head;         // 头部信息
    type_t type;        // 打印类型
    int length;         // 长度
    int index;          // 索引位置
} painter_t;

int get_screen();
void set_screen(int value);


/*
 * 初始化结构体
 */
painter_t* init_painter(type_t type, int length);

/*
 * 重新设置类型
 */
int reset_type(painter_t* painter, type_t type);
int reset_length(painter_t* painter, int length);
int reset_list(painter_t* painter, char** list, int sec);
int add_item(void* );

/*
 * painter
 */
void paint(painter_t* painter);

/*
 * 销毁结构体
 */
void destroy_painter(painter_t* painter);


// /*
//  * Format:实现将整形数组转换成为字符型数组
//  */
// int int_format(char*** char_list, int* in_list, int count);
// int float_format(char*** list, char* format, float* fo_list, int count);
//
// /*
//  * list 相关
//  */
// int paint_list(char** list, int count, int index);
// int paint_list_dobule_line(char** list, int count, int index);
//
// /*
//  * fifo 相关
//  */
// int paint_fifo(char** list, int count);
// int paint_fifo_reverse(char** list, int count);
//
// /*
//  * stack 相关
//  */
// int paint_stack(char** list, int count);
// int paint_stack_reverse(char** list, int count);
//
// /*
//  * 特殊内容 string
//  */
// int paint_string(int* list, char* start, int count);
//
#endif
