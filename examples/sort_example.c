#include "../include/sort/sort.h"
#include <stdio.h>

/**
 * @brief 打印数组元素
 * 
 * @param arr 待打印的数组
 * @param n 数组长度
 */
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // 测试数组
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("原始数组: ");
    print_array(arr1, n);
    
    // 测试冒泡排序
    bubble_sort(arr1, n);
    printf("冒泡排序后: ");
    print_array(arr1, n);
    
    // 测试快速排序
    quick_sort(arr2, 0, n - 1);
    printf("快速排序后: ");
    print_array(arr2, n);
    
    return 0;
}