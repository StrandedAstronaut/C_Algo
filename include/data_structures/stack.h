/*
 * ջ���ݽṹͷ�ļ�
 */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

// ջ�ṹ
typedef struct Stack {
    void **data;           // ��������
    size_t capacity;       // ջ����
    size_t size;           // ��ǰջ��С
    void (*destroy_data)(void *);  // �������ٺ���
} Stack;

// ��������

/**
 * ����һ���µ�ջ
 * @param initial_capacity ��ʼ����
 * @param destroy_data �������ٺ������������Ҫ��ΪNULL
 * @return ������ջָ��
 */
Stack *stack_create(size_t initial_capacity, void (*destroy_data)(void *));

/**
 * ����ջ
 * @param stack ջָ��
 */
void stack_destroy(Stack *stack);

/**
 * ��ջ����
 * @param stack ջָ��
 * @param data Ҫ��ջ������
 * @return �ɹ�����0��ʧ�ܷ���-1
 */
int stack_push(Stack *stack, void *data);

/**
 * ��ջ����
 * @param stack ջָ��
 * @return ��ջ�����ݣ����ջΪ�շ���NULL
 */
void *stack_pop(Stack *stack);

/**
 * ��ȡջ��Ԫ��
 * @param stack ջָ��
 * @return ջ�����ݣ����ջΪ�շ���NULL
 */
void *stack_peek(const Stack *stack);

/**
 * ��ȡջ��С
 * @param stack ջָ��
 * @return ջ��Ԫ������
 */
size_t stack_size(const Stack *stack);

/**
 * ���ջ�Ƿ�Ϊ��
 * @param stack ջָ��
 * @return Ϊ�շ���1�����򷵻�0
 */
int stack_is_empty(const Stack *stack);

/**
 * ���ջ�Ƿ�����
 * @param stack ջָ��
 * @return ��������1�����򷵻�0
 */
int stack_is_full(const Stack *stack);

/**
 * ���ջ
 * @param stack ջָ��
 */
void stack_clear(Stack *stack);

/**
 * ����ջ����
 * @param stack ջָ��
 * @param new_capacity �µ�����
 * @return �ɹ�����0��ʧ�ܷ���-1
 */
int stack_resize(Stack *stack, size_t new_capacity);

#endif // STACK_H