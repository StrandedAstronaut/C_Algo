#include "../include/sort/sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief 打印整数数组
 * 
 * @param arr 待打印的数组
 * @param n 数组长度
 */
void print_int_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief 打印浮点数数组
 * 
 * @param arr 待打印的数组
 * @param n 数组长度
 */
void print_double_array(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.4f ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief 复制数组
 * 
 * @param src 源数组
 * @param dest 目标数组
 * @param n 数组长度
 */
void copy_array(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    // 设置随机数种子
    srand(time(NULL));
    
    // 测试数组大小
    int n = 10;
    
    // 创建测试数组
    int arr_original[] = {64, 34, 25, 12, 22, 11, 90, 88, 77, 45};
    int arr_test[n];
    
    printf("=== 排序算法测试 ===\n");
    printf("原始数组: ");
    print_int_array(arr_original, n);
    printf("\n");
    
    // 测试冒泡排序
    copy_array(arr_original, arr_test, n);
    bubble_sort(arr_test, n);
    printf("1. 冒泡排序: ");
    print_int_array(arr_test, n);
    
    // 测试快速排序
    copy_array(arr_original, arr_test, n);
    quick_sort(arr_test, 0, n - 1);
    printf("2. 快速排序: ");
    print_int_array(arr_test, n);
    
    // 测试选择排序
    copy_array(arr_original, arr_test, n);
    selection_sort(arr_test, n);
    printf("3. 选择排序: ");
    print_int_array(arr_test, n);
    
    // 测试插入排序
    copy_array(arr_original, arr_test, n);
    insertion_sort(arr_test, n);
    printf("4. 插入排序: ");
    print_int_array(arr_test, n);
    
    // 测试归并排序
    copy_array(arr_original, arr_test, n);
    merge_sort(arr_test, 0, n - 1);
    printf("5. 归并排序: ");
    print_int_array(arr_test, n);
    
    // 测试堆排序
    copy_array(arr_original, arr_test, n);
    heap_sort(arr_test, n);
    printf("6. 堆排序  : ");
    print_int_array(arr_test, n);
    
    // 测试希尔排序
    copy_array(arr_original, arr_test, n);
    shell_sort(arr_test, n);
    printf("7. 希尔排序: ");
    print_int_array(arr_test, n);
    
    // 测试计数排序
    copy_array(arr_original, arr_test, n);
    int max = 100; // 假设最大值不超过100
    int output[n];
    counting_sort(arr_test, n, output, max);
    printf("8. 计数排序: ");
    print_int_array(output, n);
    
    // 测试基数排序
    // 注意：基数排序要求元素为非负数
    copy_array(arr_original, arr_test, n);
    radix_sort(arr_test, n);
    printf("9. 基数排序: ");
    print_int_array(arr_test, n);
    
    // 测试桶排序
    // 注意：桶排序要求元素在[0, 1)范围内
    double bucket_arr[n];
    printf("\n=== 桶排序测试（生成[0,1)范围内的随机数）===\n");
    printf("原始数组: ");
    for (int i = 0; i < n; i++) {
        bucket_arr[i] = (double)rand() / (RAND_MAX + 1.0);
    }
    print_double_array(bucket_arr, n);
    
    bucket_sort(bucket_arr, n);
    printf("桶排序后: ");
    print_double_array(bucket_arr, n);
    
    printf("\n所有排序算法测试完成！\n");
    
    return 0;
}