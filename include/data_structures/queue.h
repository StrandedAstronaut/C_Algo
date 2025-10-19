/*
 * �������ݽṹͷ�ļ�
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

// ���нṹ
typedef struct Queue {
    void **data;           // ��������
    size_t capacity;       // ��������
    size_t front;          // ��������
    size_t rear;           // ��β����
    size_t size;           // ��ǰ���д�С
    void (*destroy_data)(void *);  // �������ٺ���
} Queue;

// ��������

/**
 * ����һ���µĶ���
 * @param initial_capacity ��ʼ����
 * @param destroy_data �������ٺ������������Ҫ��ΪNULL
 * @return �����Ķ���ָ��
 */
Queue *queue_create(size_t initial_capacity, void (*destroy_data)(void *));

/**
 * ���ٶ���
 * @param queue ����ָ��
 */
void queue_destroy(Queue *queue);

/**
 * ��Ӳ���
 * @param queue ����ָ��
 * @param data Ҫ��ӵ�����
 * @return �ɹ�����0��ʧ�ܷ���-1
 */
int queue_enqueue(Queue *queue, void *data);

/**
 * ���Ӳ���
 * @param queue ����ָ��
 * @return ���ӵ����ݣ��������Ϊ�շ���NULL
 */
void *queue_dequeue(Queue *queue);

/**
 * ��ȡ����Ԫ��
 * @param queue ����ָ��
 * @return �������ݣ��������Ϊ�շ���NULL
 */
void *queue_front(const Queue *queue);

/**
 * ��ȡ��βԪ��
 * @param queue ����ָ��
 * @return ��β���ݣ��������Ϊ�շ���NULL
 */
void *queue_rear(const Queue *queue);

/**
 * ��ȡ���д�С
 * @param queue ����ָ��
 * @return ������Ԫ������
 */
size_t queue_size(const Queue *queue);

/**
 * �������Ƿ�Ϊ��
 * @param queue ����ָ��
 * @return Ϊ�շ���1�����򷵻�0
 */
int queue_is_empty(const Queue *queue);

/**
 * �������Ƿ�����
 * @param queue ����ָ��
 * @return ��������1�����򷵻�0
 */
int queue_is_full(const Queue *queue);

/**
 * ��ն���
 * @param queue ����ָ��
 */
void queue_clear(Queue *queue);

/**
 * ������������
 * @param queue ����ָ��
 * @param new_capacity �µ�����
 * @return �ɹ�����0��ʧ�ܷ���-1
 */
int queue_resize(Queue *queue, size_t new_capacity);

#endif // QUEUE_H