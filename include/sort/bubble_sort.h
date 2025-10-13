#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

/**
 * @file bubble_sort.h
 * @brief 冒泡排序算法接口定义
 */

/**
 * @brief 冒泡排序算法
 * 
 * 冒泡排序是一种简单的比较排序算法，重复地走访过要排序的数列，
 * 一次比较两个元素，如果它们的顺序错误就把它们交换过来。
 * 时间复杂度为O(n²)，空间复杂度为O(1)。
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 * 
 * @note 该函数会直接修改传入的数组，使其按升序排列
 */
void bubble_sort(int arr[], int n);

// 以下是尚未实现的排序算法接口定义
// 后续可以根据需要实现这些功能

/**
 * @brief 选择排序算法
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 */
// void selection_sort(int arr[], int n);

/**
 * @brief 插入排序算法
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 */
// void insertion_sort(int arr[], int n);

/**
 * @brief 归并排序算法
 * 
 * @param arr 待排序的整数数组
 * @param left 起始索引
 * @param right 结束索引
 */
// void merge_sort(int arr[], int left, int right);

/**
 * @brief 堆排序算法
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 */
// void heap_sort(int arr[], int n);

/**
 * @brief 希尔排序算法
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 */
// void shell_sort(int arr[], int n);

/**
 * @brief 计数排序算法
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 * @param output 输出数组
 * @param max 数组中的最大值
 */
// void counting_sort(int arr[], int n, int output[], int max);

/**
 * @brief 桶排序算法
 * 
 * @param arr 待排序的浮点数数组
 * @param n 数组长度
 */
// void bucket_sort(double arr[], int n);

/**
 * @brief 基数排序算法
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 */
// void radix_sort(int arr[], int n);

#endif // BUBBLE_SORT_H