/*
 * 栈数据结构头文件
 */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

// 栈结构
typedef struct Stack {
    void **data;           // 数据数组
    size_t capacity;       // 栈容量
    size_t size;           // 当前栈大小
    void (*destroy_data)(void *);  // 数据销毁函数
} Stack;

// 函数声明

/**
 * 创建一个新的栈
 * @param initial_capacity 初始容量
 * @param destroy_data 数据销毁函数，如果不需要则为NULL
 * @return 创建的栈指针
 */
Stack *stack_create(size_t initial_capacity, void (*destroy_data)(void *));

/**
 * 销毁栈
 * @param stack 栈指针
 */
void stack_destroy(Stack *stack);

/**
 * 入栈操作
 * @param stack 栈指针
 * @param data 要入栈的数据
 * @return 成功返回0，失败返回-1
 */
int stack_push(Stack *stack, void *data);

/**
 * 出栈操作
 * @param stack 栈指针
 * @return 出栈的数据，如果栈为空返回NULL
 */
void *stack_pop(Stack *stack);

/**
 * 获取栈顶元素
 * @param stack 栈指针
 * @return 栈顶数据，如果栈为空返回NULL
 */
void *stack_peek(const Stack *stack);

/**
 * 获取栈大小
 * @param stack 栈指针
 * @return 栈中元素数量
 */
size_t stack_size(const Stack *stack);

/**
 * 检查栈是否为空
 * @param stack 栈指针
 * @return 为空返回1，否则返回0
 */
int stack_is_empty(const Stack *stack);

/**
 * 检查栈是否已满
 * @param stack 栈指针
 * @return 已满返回1，否则返回0
 */
int stack_is_full(const Stack *stack);

/**
 * 清空栈
 * @param stack 栈指针
 */
void stack_clear(Stack *stack);

/**
 * 调整栈容量
 * @param stack 栈指针
 * @param new_capacity 新的容量
 * @return 成功返回0，失败返回-1
 */
int stack_resize(Stack *stack, size_t new_capacity);

#endif // STACK_H