/*
 * 队列数据结构头文件
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

// 队列结构
typedef struct Queue {
    void **data;           // 数据数组
    size_t capacity;       // 队列容量
    size_t front;          // 队首索引
    size_t rear;           // 队尾索引
    size_t size;           // 当前队列大小
    void (*destroy_data)(void *);  // 数据销毁函数
} Queue;

// 函数声明

/**
 * 创建一个新的队列
 * @param initial_capacity 初始容量
 * @param destroy_data 数据销毁函数，如果不需要则为NULL
 * @return 创建的队列指针
 */
Queue *queue_create(size_t initial_capacity, void (*destroy_data)(void *));

/**
 * 销毁队列
 * @param queue 队列指针
 */
void queue_destroy(Queue *queue);

/**
 * 入队操作
 * @param queue 队列指针
 * @param data 要入队的数据
 * @return 成功返回0，失败返回-1
 */
int queue_enqueue(Queue *queue, void *data);

/**
 * 出队操作
 * @param queue 队列指针
 * @return 出队的数据，如果队列为空返回NULL
 */
void *queue_dequeue(Queue *queue);

/**
 * 获取队首元素
 * @param queue 队列指针
 * @return 队首数据，如果队列为空返回NULL
 */
void *queue_front(const Queue *queue);

/**
 * 获取队尾元素
 * @param queue 队列指针
 * @return 队尾数据，如果队列为空返回NULL
 */
void *queue_rear(const Queue *queue);

/**
 * 获取队列大小
 * @param queue 队列指针
 * @return 队列中元素数量
 */
size_t queue_size(const Queue *queue);

/**
 * 检查队列是否为空
 * @param queue 队列指针
 * @return 为空返回1，否则返回0
 */
int queue_is_empty(const Queue *queue);

/**
 * 检查队列是否已满
 * @param queue 队列指针
 * @return 已满返回1，否则返回0
 */
int queue_is_full(const Queue *queue);

/**
 * 清空队列
 * @param queue 队列指针
 */
void queue_clear(Queue *queue);

/**
 * 调整队列容量
 * @param queue 队列指针
 * @param new_capacity 新的容量
 * @return 成功返回0，失败返回-1
 */
int queue_resize(Queue *queue, size_t new_capacity);

#endif // QUEUE_H