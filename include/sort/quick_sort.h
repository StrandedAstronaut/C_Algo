#ifndef QUICK_SORT_H
#define QUICK_SORT_H

/**
 * @file quick_sort.h
 * @brief 快速排序算法接口定义
 */

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

#endif // QUICK_SORT_H
    