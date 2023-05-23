#ifndef __PAINTER_H
#define __PAINTER_H

#define MAX_INT_LENGTH

/*
 * 实现将整形数组转换成为字符型数组
 */
int int_format(char*** char_list, int* in_list, int count);

/*
 * 实现将浮点型数组转换成为字符型数组
 */
int float_format();

/*
 * list 相关
 */
int paint_list(char** list, int count, int index);
int paint_list_with_head(char** list, int count, int index);
int paint_list_dobule_line(char** list, int count, int index);

/*
 * fifo 相关
 */
int paint_fifo(char** list, int count);
int paint_fifo_reverse(char** list, int count);

/*
 * stack 相关
 */
int paint_stack(char** list, int count);
int paint_stack_reverse(char** list, int count);

/*
 * 特殊内容 string
 */
int paint_string(int* list, int* use, int count);

#endif
