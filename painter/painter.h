#ifndef __PAINTER_H
#define __PAINTER_H

#define MAX_INT_LENGTH

// 类型描述
typedef enum {
    LIST = 0,
    LIST_DOUBLE = 1,
    FIFO = 2,
    STACK = 3,
    HEAD = 4,
} type_t;

// 返回值类型
typedef enum {
    SUCCESS = 0,
    NULL_PAINT = 1,
    NULL_LIST = 2,
    NULL_HEAD = 3,
    INV_LENGTH = 4,

} rt_t;

// 打印结构
typedef struct {
    char** list_main;   // 打印列表
    char** list_aux;    // 附属表
    int aux_set;
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
painter_t* init_painter(type_t type, int length, char* head);

/*
 * 重新设置类型
 */
int reset_type(painter_t* painter, type_t type, char* head);
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

#endif
