/*
 * 链表数据结构实现文件 - 待实现
 */

#include "../../include/data_structures/linked_list.h"


// 函数实现

/**
 * 创建一个新的链表
 * @param destroy_data 数据销毁函数，如果不需要则为NULL
 * @return 创建的链表指针
 */
LinkedList *linked_list_create(void (*destroy_data)(void *))
{
    LinkedList *new_list = malloc(sizeof(*new_list));
    if (new_list == NULL) {
        return NULL;
    }
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    new_list->destroy_data = destroy_data;  // 将传入的函数指针赋值给链表结构的成员
    return new_list;
}

/**
 * 销毁链表
 * @param list 链表指针
 */
void linked_list_destroy(LinkedList *list)
{
    // TODO: 实现销毁链表的功能
    if (list == NULL) {
        return;
    }
    if (list->destroy_data != NULL) {
        linked_list_clear(list);
    }
    free(list);
}

/**
 * 在链表头部插入数据
 * @param list 链表指针
 * @param data 要插入的数据
 * @return 成功返回0，失败返回-1
 */
int linked_list_insert_head(LinkedList *list, void *data)
{
    // TODO: 实现在链表头部插入数据的功能
    if (list == NULL) {
        return -1;
    }
    Node *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) {
        return -1;
    }
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
    return 0; // 临时返回值 
}

/**
 * 在链表尾部插入数据
 * @param list 链表指针
 * @param data 要插入的数据
 * @return 成功返回0，失败返回-1
 */
int linked_list_insert_tail(LinkedList *list, void *data)
{
    // TODO: 实现在链表尾部插入数据的功能
    if (list == NULL) {
        return -1;
    }
    Node *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) {
        return -1;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    list->size++;
    return 0; // 临时返回值
}

/**
 * 在指定位置插入数据
 * @param list 链表指针
 * @param index 插入位置索引（从0开始）
 * @param data 要插入的数据
 * @return 成功返回0，失败返回-1
 */
int linked_list_insert_at(LinkedList *list, size_t index, void *data)
{
    if (list == NULL) {
        return -1;
    }
    if (index > list->size) {
        return -1;
    }
    
    // 对于特殊位置，直接调用对应的插入函数
    if (index == 0) {
        return linked_list_insert_head(list, data);
    } else if (index == list->size) {
        return linked_list_insert_tail(list, data);
    }
    
    // 对于中间位置，手动实现插入
    Node *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) {
        return -1;
    }
    new_node->data = data;
    
    // 找到插入位置的前一个节点
    Node *prev = list->head;
    for (size_t i = 0; i < index - 1; i++) {
        prev = prev->next;
    }
    
    // 插入新节点
    new_node->next = prev->next;
    prev->next = new_node;
    list->size++;
    
    return 0;
}

/**
 * 删除链表头部节点
 * @param list 链表指针
 * @return 删除的节点数据，如果链表为空返回NULL
 */
void *linked_list_remove_head(LinkedList *list)
{
    // TODO: 实现删除链表头部节点的功能
    if (list == NULL) {
        return NULL;
    }
    if (list->head == NULL) {
        return NULL;
    }
    Node *old_head = list->head;
    list->head = old_head->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    void *data = old_head->data;
    if (list->destroy_data != NULL) {
        list->destroy_data(data);
    }
    free(old_head);
    list->size--;
    return data; // 临时返回值
}

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
void *linked_list_remove_at(LinkedList *list, size_t index)
{
    // TODO: 实现删除指定位置的节点功能
    return NULL; // 临时返回值
}

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
size_t linked_list_size(const LinkedList *list)
{
    // TODO: 实现获取链表大小的功能
    return 0; // 临时返回值
}

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
void linked_list_clear(LinkedList *list)
{
    // TODO: 实现清空链表的功能
}
