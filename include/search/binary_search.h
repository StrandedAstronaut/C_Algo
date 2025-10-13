#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

/**
 * @file binary_search.h
 * @brief 二分查找算法接口定义
 */

/**
 * @brief 二分查找算法
 * 
 * 二分查找是一种在有序数组中查找特定元素的高效算法，
 * 它通过反复将搜索区间划分为一半来减少搜索范围。
 * 时间复杂度为O(log n)，空间复杂度为O(1)。
 * 
 * @param arr 有序整数数组（升序排列）
 * @param n 数组长度
 * @param target 要查找的目标值
 * @return int 如果找到目标值，返回其索引；否则返回-1
 * 
 * @note 数组必须是升序排列的
 */
int binary_search(int arr[], int n, int target);

// 以下是尚未实现的搜索算法接口定义
// 后续可以根据需要实现这些功能

/**
 * @brief 线性查找算法
 * 
 * @param arr 整数数组
 * @param n 数组长度
 * @param target 要查找的目标值
 * @return int 如果找到目标值，返回其首次出现的索引；否则返回-1
 */
// int linear_search(int arr[], int n, int target);

/**
 * @brief 插值查找算法
 * 
 * @param arr 有序整数数组（升序排列）
 * @param n 数组长度
 * @param target 要查找的目标值
 * @return int 如果找到目标值，返回其索引；否则返回-1
 */
// int interpolation_search(int arr[], int n, int target);

/**
 * @brief 斐波那契查找算法
 * 
 * @param arr 有序整数数组（升序排列）
 * @param n 数组长度
 * @param target 要查找的目标值
 * @return int 如果找到目标值，返回其索引；否则返回-1
 */
// int fibonacci_search(int arr[], int n, int target);

/**
 * @brief 跳跃查找算法
 * 
 * @param arr 有序整数数组（升序排列）
 * @param n 数组长度
 * @param target 要查找的目标值
 * @return int 如果找到目标值，返回其索引；否则返回-1
 */
// int jump_search(int arr[], int n, int target);

/**
 * @brief 指数查找算法
 * 
 * @param arr 有序整数数组（升序排列）
 * @param n 数组长度
 * @param target 要查找的目标值
 * @return int 如果找到目标值，返回其索引；否则返回-1
 */
// int exponential_search(int arr[], int n, int target);

#endif // BINARY_SEARCH_H