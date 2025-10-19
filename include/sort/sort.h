#ifndef SORT_H
#define SORT_H

/**
 * @file sort.h
 * @brief 排序算法库函数接口定义
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

/**
 * @brief 快速排序算法
 * 
 * 快速排序是一种高效的比较排序算法，采用分治策略对数组进行排序。
 * 本实现平均时间复杂度为O(n log n)，最坏情况为O(n²)，空间复杂度为O(log n)。
 * 
 * @param arr 待排序的整数数组
 * @param low 排序的起始索引（通常为0）
 * @param high 排序的结束索引（通常为数组长度减1）
 * 
 * @note 该函数会直接修改传入的数组，使其按升序排列
 * @warning 确保low和high参数在数组范围内，否则可能导致未定义行为
 */
void quick_sort(int arr[], int low, int high);

// 以下是常用排序算法接口定义

/**
 * @brief 选择排序算法
 * 
 * 选择排序是一种简单直观的排序算法，每次从未排序部分选择最小元素放到已排序部分的末尾。
 * 时间复杂度为O(n²)，空间复杂度为O(1)。
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 * 
 * @note 该函数会直接修改传入的数组，使其按升序排列
 */
void selection_sort(int arr[], int n);

/**
 * @brief 插入排序算法
 * 
 * 插入排序是一种简单直观的排序算法，它的工作原理是通过构建有序序列，
 * 对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
 * 时间复杂度为O(n²)，空间复杂度为O(1)。
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 * 
 * @note 该函数会直接修改传入的数组，使其按升序排列
 */
void insertion_sort(int arr[], int n);

/**
 * @brief 归并排序算法
 * 
 * 归并排序是一种分治算法，将数组分成两半，递归地排序每一半，然后合并两个有序数组。
 * 时间复杂度为O(n log n)，空间复杂度为O(n)。
 * 
 * @param arr 待排序的整数数组
 * @param left 起始索引
 * @param right 结束索引
 * 
 * @note 该函数会直接修改传入的数组，使其按升序排列
 */
void merge_sort(int arr[], int left, int right);

/**
 * @brief 堆排序算法
 * 
 * 堆排序是利用堆这种数据结构所设计的一种排序算法。堆是一个近似完全二叉树的结构，
 * 并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。
 * 时间复杂度为O(n log n)，空间复杂度为O(1)。
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 * 
 * @note 该函数会直接修改传入的数组，使其按升序排列
 */
void heap_sort(int arr[], int n);

/**
 * @brief 希尔排序算法
 * 
 * 希尔排序是插入排序的一种更高效的改进版本，它通过比较相距一定间隔的元素来进行排序。
 * 希尔排序的时间复杂度取决于增量序列，最坏情况下为O(n²)，平均情况下接近O(n log n)。
 * 空间复杂度为O(1)。
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 * 
 * @note 该函数会直接修改传入的数组，使其按升序排列
 */
void shell_sort(int arr[], int n);

/**
 * @brief 计数排序算法
 * 
 * 计数排序是一种非比较型整数排序算法，其时间复杂度为O(n+k)，其中k是整数的范围。
 * 它的核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 * @param output 输出数组
 * @param max 数组中的最大值
 * 
 * @note 输出结果将存储在output数组中，arr数组不会被修改
 */
void counting_sort(int arr[], int n, int output[], int max);

/**
 * @brief 桶排序算法
 * 
 * 桶排序是计数排序的升级版，它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
 * 时间复杂度为O(n+k)，其中k是桶的数量。
 * 
 * @param arr 待排序的浮点数数组
 * @param n 数组长度
 * 
 * @note 该函数会直接修改传入的数组，使其按升序排列
 * @note 要求数组元素在[0, 1)范围内
 */
void bucket_sort(double arr[], int n);

/**
 * @brief 基数排序算法
 * 
 * 基数排序是一种非比较型整数排序算法，其原理是将整数按位数切割成不同的数字，
 * 然后按每个位数分别比较。时间复杂度为O(n*k)，其中k是数字的位数。
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 * 
 * @note 该函数会直接修改传入的数组，使其按升序排列
 * @note 要求数组元素为非负数
 */
void radix_sort(int arr[], int n);

#endif // SORT_H