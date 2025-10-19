/*
 * �������ݽṹʵ���ļ� - ��ʵ��
 */

#include "../../include/data_structures/linked_list.h"


// ����ʵ��

/**
 * ����һ���µ�����
 * @param destroy_data �������ٺ������������Ҫ��ΪNULL
 * @return ����������ָ��
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
    new_list->destroy_data = destroy_data;  // ������ĺ���ָ�븳ֵ������ṹ�ĳ�Ա
    return new_list;
}

/**
 * ��������
 * @param list ����ָ��
 */
void linked_list_destroy(LinkedList *list)
{
    // TODO: ʵ����������Ĺ���
    if (list == NULL) {
        return;
    }
    if (list->destroy_data != NULL) {
        linked_list_clear(list);
    }
    free(list);
}

/**
 * ������ͷ����������
 * @param list ����ָ��
 * @param data Ҫ���������
 * @return �ɹ�����0��ʧ�ܷ���-1
 */
int linked_list_insert_head(LinkedList *list, void *data)
{
    // TODO: ʵ��������ͷ���������ݵĹ���
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
    return 0; // ��ʱ����ֵ 
}

/**
 * ������β����������
 * @param list ����ָ��
 * @param data Ҫ���������
 * @return �ɹ�����0��ʧ�ܷ���-1
 */
int linked_list_insert_tail(LinkedList *list, void *data)
{
    // TODO: ʵ��������β���������ݵĹ���
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
    return 0; // ��ʱ����ֵ
}

/**
 * ��ָ��λ�ò�������
 * @param list ����ָ��
 * @param index ����λ����������0��ʼ��
 * @param data Ҫ���������
 * @return �ɹ�����0��ʧ�ܷ���-1
 */
int linked_list_insert_at(LinkedList *list, size_t index, void *data)
{
    if (list == NULL) {
        return -1;
    }
    if (index > list->size) {
        return -1;
    }
    
    // ��������λ�ã�ֱ�ӵ��ö�Ӧ�Ĳ��뺯��
    if (index == 0) {
        return linked_list_insert_head(list, data);
    } else if (index == list->size) {
        return linked_list_insert_tail(list, data);
    }
    
    // �����м�λ�ã��ֶ�ʵ�ֲ���
    Node *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) {
        return -1;
    }
    new_node->data = data;
    
    // �ҵ�����λ�õ�ǰһ���ڵ�
    Node *prev = list->head;
    for (size_t i = 0; i < index - 1; i++) {
        prev = prev->next;
    }
    
    // �����½ڵ�
    new_node->next = prev->next;
    prev->next = new_node;
    list->size++;
    
    return 0;
}

/**
 * ɾ������ͷ���ڵ�
 * @param list ����ָ��
 * @return ɾ���Ľڵ����ݣ��������Ϊ�շ���NULL
 */
void *linked_list_remove_head(LinkedList *list)
{
    // TODO: ʵ��ɾ������ͷ���ڵ�Ĺ���
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
    return data; // ��ʱ����ֵ
}

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
void *linked_list_remove_at(LinkedList *list, size_t index)
{
    // TODO: ʵ��ɾ��ָ��λ�õĽڵ㹦��
    return NULL; // ��ʱ����ֵ
}

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
size_t linked_list_size(const LinkedList *list)
{
    // TODO: ʵ�ֻ�ȡ�����С�Ĺ���
    return 0; // ��ʱ����ֵ
}

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
void linked_list_clear(LinkedList *list)
{
    // TODO: ʵ���������Ĺ���
}
