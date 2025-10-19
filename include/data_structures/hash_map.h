/*
 * ��ϣ�����ݽṹͷ�ļ�
 */

#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdlib.h>

// ��ϣ��ڵ�
typedef struct HashMapNode {
    void *key;               // ��
    void *value;             // ֵ
    struct HashMapNode *next; // ��һ���ڵ㣨�����ͻ��
} HashMapNode;

// ��ϣ��ṹ
typedef struct HashMap {
    HashMapNode **buckets;    // Ͱ����
    size_t capacity;          // Ͱ������
    size_t size;              // ��ǰԪ������
    size_t (*hash_func)(const void *key); // ��ϣ����
    int (*key_equals)(const void *key1, const void *key2); // ���ȽϺ���
    void (*destroy_key)(void *key);    // �����ٺ���
    void (*destroy_value)(void *value); // ֵ���ٺ���
}
HashMap;

// ��������

/**
 * ����һ���µĹ�ϣ��
 * @param initial_capacity ��ʼͰ����
 * @param hash_func ��ϣ����
 * @param key_equals ���ȽϺ���
 * @param destroy_key �����ٺ���������Ҫ��ΪNULL
 * @param destroy_value ֵ���ٺ���������Ҫ��ΪNULL
 * @return �����Ĺ�ϣ��ָ��
 */
HashMap *hash_map_create(
    size_t initial_capacity,
    size_t (*hash_func)(const void *key),
    int (*key_equals)(const void *key1, const void *key2),
    void (*destroy_key)(void *key),
    void (*destroy_value)(void *value)
);

/**
 * ���ٹ�ϣ��
 * @param map ��ϣ��ָ��
 */
void hash_map_destroy(HashMap *map);

/**
 * �����ֵ��
 * @param map ��ϣ��ָ��
 * @param key ��
 * @param value ֵ
 * @return �ɹ�����0��������Ѵ������滻ֵ������1��ʧ�ܷ���-1
 */
int hash_map_put(HashMap *map, void *key, void *value);

/**
 * ��ȡָ������ֵ
 * @param map ��ϣ��ָ��
 * @param key ��
 * @return ��Ӧ��ֵ������������ڷ���NULL
 */
void *hash_map_get(const HashMap *map, const void *key);

/**
 * ɾ��ָ�����ļ�ֵ��
 * @param map ��ϣ��ָ��
 * @param key ��
 * @return �ɹ�����0���������ڷ���1��ʧ�ܷ���-1
 */
int hash_map_remove(HashMap *map, const void *key);

/**
 * �����Ƿ����
 * @param map ��ϣ��ָ��
 * @param key ��
 * @return ���ڷ���1�������ڷ���0
 */
int hash_map_contains_key(const HashMap *map, const void *key);

/**
 * ��ȡ��ϣ���С
 * @param map ��ϣ��ָ��
 * @return ��ϣ����Ԫ������
 */
size_t hash_map_size(const HashMap *map);

/**
 * ����ϣ���Ƿ�Ϊ��
 * @param map ��ϣ��ָ��
 * @return Ϊ�շ���1�����򷵻�0
 */
int hash_map_is_empty(const HashMap *map);

/**
 * ��չ�ϣ��
 * @param map ��ϣ��ָ��
 */
void hash_map_clear(HashMap *map);

/**
 * ������ϣ���С
 * @param map ��ϣ��ָ��
 * @param new_capacity �µ�Ͱ����
 * @return �ɹ�����0��ʧ�ܷ���-1
 */
int hash_map_resize(HashMap *map, size_t new_capacity);

// ͨ�ù�ϣ�������ַ�������
size_t hash_string(const void *key);

// ͨ�ü��ȽϺ������ַ�������
int equals_string(const void *key1, const void *key2);

// ͨ�ù�ϣ��������������
size_t hash_int(const void *key);

// ͨ�ü��ȽϺ�������������
int equals_int(const void *key1, const void *key2);

#endif // HASH_MAP_H