/*
 * �������ݽṹͷ�ļ�
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

// ����ڵ�ṹ
typedef struct Node {
    void *data;           // ����ָ��
    struct Node *next;    // ָ����һ���ڵ�
} Node;

// ����ṹ
typedef struct LinkedList {
    Node *head;           // ͷ�ڵ�
    Node *tail;           // β�ڵ�
    size_t size;          // �����С
    void (*destroy_data)(void *);  // �������ٺ���
} LinkedList;

// ��������

/**
 * ����һ���µ�����
 * @param destroy_data �������ٺ������������Ҫ��ΪNULL
 * @return ����������ָ��
 */
LinkedList *linked_list_create(void (*destroy_data)(void *));

/**
 * ��������
 * @param list ����ָ��
 */
void linked_list_destroy(LinkedList *list);

/**
 * ������ͷ����������
 * @param list ����ָ��
 * @param data Ҫ���������
 * @return �ɹ�����0��ʧ�ܷ���-1
 */
int linked_list_insert_head(LinkedList *list, void *data);

/**
 * ������β����������
 * @param list ����ָ��
 * @param data Ҫ���������
 * @return �ɹ�����0��ʧ�ܷ���-1
 */
int linked_list_insert_tail(LinkedList *list, void *data);

/**
 * ��ָ��λ�ò�������
 * @param list ����ָ��
 * @param index ����λ����������0��ʼ��
 * @param data Ҫ���������
 * @return �ɹ�����0��ʧ�ܷ���-1
 */
int linked_list_insert_at(LinkedList *list, size_t index, void *data);

/**
 * ɾ������ͷ���ڵ�
 * @param list ����ָ��
 * @return ɾ���Ľڵ����ݣ��������Ϊ�շ���NULL
 */
void *linked_list_remove_head(LinkedList *list);

/**
 * ɾ������β���ڵ�
 * @param list ����ָ��
 * @return ɾ���Ľڵ����ݣ��������Ϊ�շ���NULL
 */
void *linked_list_remove_tail(LinkedList *list);

/**
 * ɾ��ָ��λ�õĽڵ�
 * @param list ����ָ��
 * @param index Ҫɾ���Ľڵ���������0��ʼ��
 * @return ɾ���Ľڵ����ݣ����������Ч����NULL
 */
void *linked_list_remove_at(LinkedList *list, size_t index);

/**
 * ��ȡָ��λ�õĽڵ�����
 * @param list ����ָ��
 * @param index �ڵ���������0��ʼ��
 * @return �ڵ����ݣ����������Ч����NULL
 */
void *linked_list_get(LinkedList *list, size_t index);

/**
 * ��ȡ�����С
 * @param list ����ָ��
 * @return ����ڵ�����
 */
size_t linked_list_size(const LinkedList *list);

/**
 * ��������Ƿ�Ϊ��
 * @param list ����ָ��
 * @return Ϊ�շ���1�����򷵻�0
 */
int linked_list_is_empty(const LinkedList *list);

/**
 * �������
 * @param list ����ָ��
 */
void linked_list_clear(LinkedList *list);

#endif // LINKED_LIST_H