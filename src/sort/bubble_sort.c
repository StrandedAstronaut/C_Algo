/**
 * 冒泡排序算法实现
 * 冒泡排序是一种简单的排序算法，它重复地走访过要排序的数列，
 * 一次比较两个元素，如果它们的顺序错误就把它们交换过来。
 * 时间复杂度为O(n²)，空间复杂度为O(1)
 */
#include "../../include/sort/bubble_sort.h"

/**
 * @brief 交换两个整数的位置
 * 
 * @param a 指向第一个整数的指针
 * @param b 指向第二个整数的指针
 */
static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief 冒泡排序主函数
 * 
 * @param arr 待排序的整数数组
 * @param n 数组长度
 */
void bubble_sort(int arr[], int n) {
    int i, j;
    // 外层循环：每轮将最大元素冒泡到末尾
    for (i = 0; i < n - 1; i++) {
        // 内层循环：比较相邻元素并交换
        for (j = 0; j < n - i - 1; j++) {
            // 如果前一个元素大于后一个元素，则交换它们
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}