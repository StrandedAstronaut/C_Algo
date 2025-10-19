/*
 * 链表数据结构头文件
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

// 链表节点结构
typedef struct Node {
    void *data;           // 数据指针
    struct Node *next;    // 指向下一个节点
} Node;

// 链表结构
typedef struct LinkedList {
    Node *head;           // 头节点
    Node *tail;           // 尾节点
    size_t size;          // 链表大小
    void (*destroy_data)(void *);  // 数据销毁函数
} LinkedList;

// 函数声明

/**
 * 创建一个新的链表
 * @param destroy_data 数据销毁函数，如果不需要则为NULL
 * @return 创建的链表指针
 */
LinkedList *linked_list_create(void (*destroy_data)(void *));

/**
 * 销毁链表
 * @param list 链表指针
 */
void linked_list_destroy(LinkedList *list);

/**
 * 在链表头部插入数据
 * @param list 链表指针
 * @param data 要插入的数据
 * @return 成功返回0，失败返回-1
 */
int linked_list_insert_head(LinkedList *list, void *data);

/**
 * 在链表尾部插入数据
 * @param list 链表指针
 * @param data 要插入的数据
 * @return 成功返回0，失败返回-1
 */
int linked_list_insert_tail(LinkedList *list, void *data);

/**
 * 在指定位置插入数据
 * @param list 链表指针
 * @param index 插入位置索引（从0开始）
 * @param data 要插入的数据
 * @return 成功返回0，失败返回-1
 */
int linked_list_insert_at(LinkedList *list, size_t index, void *data);

/**
 * 删除链表头部节点
 * @param list 链表指针
 * @return 删除的节点数据，如果链表为空返回NULL
 */
void *linked_list_remove_head(LinkedList *list);

/**
 * 删除链表尾部节点
 * @param list 链表指针
 * @return 删除的节点数据，如果链表为空返回NULL
 */
void *linked_list_remove_tail(LinkedList *list);

/**
 * 删除指定位置的节点
 * @param list 链表指针
 * @param index 要删除的节点索引（从0开始）
 * @return 删除的节点数据，如果索引无效返回NULL
 */
void *linked_list_remove_at(LinkedList *list, size_t index);

/**
 * 获取指定位置的节点数据
 * @param list 链表指针
 * @param index 节点索引（从0开始）
 * @return 节点数据，如果索引无效返回NULL
 */
void *linked_list_get(LinkedList *list, size_t index);

/**
 * 获取链表大小
 * @param list 链表指针
 * @return 链表节点数量
 */
size_t linked_list_size(const LinkedList *list);

/**
 * 检查链表是否为空
 * @param list 链表指针
 * @return 为空返回1，否则返回0
 */
int linked_list_is_empty(const LinkedList *list);

/**
 * 清空链表
 * @param list 链表指针
 */
void linked_list_clear(LinkedList *list);

#endif // LINKED_LIST_H