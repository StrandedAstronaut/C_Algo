/*
 * 哈希表数据结构头文件
 */

#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdlib.h>

// 哈希表节点
typedef struct HashMapNode {
    void *key;               // 键
    void *value;             // 值
    struct HashMapNode *next; // 下一个节点（处理冲突）
} HashMapNode;

// 哈希表结构
typedef struct HashMap {
    HashMapNode **buckets;    // 桶数组
    size_t capacity;          // 桶的数量
    size_t size;              // 当前元素数量
    size_t (*hash_func)(const void *key); // 哈希函数
    int (*key_equals)(const void *key1, const void *key2); // 键比较函数
    void (*destroy_key)(void *key);    // 键销毁函数
    void (*destroy_value)(void *value); // 值销毁函数
}
HashMap;

// 函数声明

/**
 * 创建一个新的哈希表
 * @param initial_capacity 初始桶数量
 * @param hash_func 哈希函数
 * @param key_equals 键比较函数
 * @param destroy_key 键销毁函数，不需要则为NULL
 * @param destroy_value 值销毁函数，不需要则为NULL
 * @return 创建的哈希表指针
 */
HashMap *hash_map_create(
    size_t initial_capacity,
    size_t (*hash_func)(const void *key),
    int (*key_equals)(const void *key1, const void *key2),
    void (*destroy_key)(void *key),
    void (*destroy_value)(void *value)
);

/**
 * 销毁哈希表
 * @param map 哈希表指针
 */
void hash_map_destroy(HashMap *map);

/**
 * 插入键值对
 * @param map 哈希表指针
 * @param key 键
 * @param value 值
 * @return 成功返回0，如果键已存在则替换值并返回1，失败返回-1
 */
int hash_map_put(HashMap *map, void *key, void *value);

/**
 * 获取指定键的值
 * @param map 哈希表指针
 * @param key 键
 * @return 对应的值，如果键不存在返回NULL
 */
void *hash_map_get(const HashMap *map, const void *key);

/**
 * 删除指定键的键值对
 * @param map 哈希表指针
 * @param key 键
 * @return 成功返回0，键不存在返回1，失败返回-1
 */
int hash_map_remove(HashMap *map, const void *key);

/**
 * 检查键是否存在
 * @param map 哈希表指针
 * @param key 键
 * @return 存在返回1，不存在返回0
 */
int hash_map_contains_key(const HashMap *map, const void *key);

/**
 * 获取哈希表大小
 * @param map 哈希表指针
 * @return 哈希表中元素数量
 */
size_t hash_map_size(const HashMap *map);

/**
 * 检查哈希表是否为空
 * @param map 哈希表指针
 * @return 为空返回1，否则返回0
 */
int hash_map_is_empty(const HashMap *map);

/**
 * 清空哈希表
 * @param map 哈希表指针
 */
void hash_map_clear(HashMap *map);

/**
 * 调整哈希表大小
 * @param map 哈希表指针
 * @param new_capacity 新的桶数量
 * @return 成功返回0，失败返回-1
 */
int hash_map_resize(HashMap *map, size_t new_capacity);

// 通用哈希函数（字符串键）
size_t hash_string(const void *key);

// 通用键比较函数（字符串键）
int equals_string(const void *key1, const void *key2);

// 通用哈希函数（整数键）
size_t hash_int(const void *key);

// 通用键比较函数（整数键）
int equals_int(const void *key1, const void *key2);

#endif // HASH_MAP_H