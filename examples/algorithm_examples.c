/**
 * C语言算法库 - 综合示例程序
 * 展示如何使用算法库中的多种算法：排序、滤波和搜索
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algorithm_lib.h"

// 打印整数数组
void print_int_array(int arr[], int n, const char* label) {
    printf("%s: ", label);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 打印浮点数数组
void print_double_array(double arr[], int n, const char* label) {
    printf("%s: ", label);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("===== C语言算法库 - 综合示例程序 =====\n\n");
    
    // ==========================
    // 1. 排序算法示例 - 冒泡排序
    // ==========================
    printf("1. 冒泡排序示例:\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    print_int_array(arr, n, "排序前");
    bubble_sort(arr, n);
    print_int_array(arr, n, "排序后");
    printf("\n");
    
    // ==========================
    // 2. 搜索算法示例 - 二分查找
    // ==========================
    printf("2. 二分查找示例:\n");
    int sorted_arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int sorted_n = sizeof(sorted_arr) / sizeof(sorted_arr[0]);
    int target = 25;
    
    print_int_array(sorted_arr, sorted_n, "有序数组");
    int index = binary_search(sorted_arr, sorted_n, target);
    
    if (index != -1) {
        printf("查找值 %d: 在索引 %d 处找到\n", target, index);
    } else {
        printf("查找值 %d: 未找到\n", target);
    }
    
    target = 22;  // 不在数组中的值
    index = binary_search(sorted_arr, sorted_n, target);
    if (index != -1) {
        printf("查找值 %d: 在索引 %d 处找到\n", target, index);
    } else {
        printf("查找值 %d: 未找到\n", target);
    }
    printf("\n");
    
    // ==========================
    // 3. 滤波算法示例 - 均值滤波
    // ==========================
    printf("3. 均值滤波示例:\n");
    // 创建一个带噪声的信号
    double noisy_signal[20];
    double filtered_signal[20];
    
    // 生成一个平滑的正弦波加上随机噪声
    srand(time(NULL));  // 初始化随机数生成器
    printf("原始信号: ");
    for (int i = 0; i < 20; i++) {
        // 生成0-10的正弦波值，加上-1到1之间的随机噪声
        noisy_signal[i] = 5 * (1 + sin(i * 0.5)) + ((double)rand() / RAND_MAX) * 2 - 1;
        printf("%.2f ", noisy_signal[i]);
    }
    printf("\n");
    
    // 应用均值滤波，窗口大小为3
    int window_size = 3;
    mean_filter_1d(noisy_signal, filtered_signal, 20, window_size);
    
    printf("滤波后信号 (窗口大小=%d): ", window_size);
    for (int i = 0; i < 20; i++) {
        printf("%.2f ", filtered_signal[i]);
    }
    printf("\n");
    
    // ==========================
    // 4. 数学库函数示例
    // ==========================
    printf("\n4. 数学库函数示例:\n");
    printf("绝对值: abs_int(-10) = %d\n", abs_int(-10));
    printf("最大值: max_int(5, 10) = %d\n", max_int(5, 10));
    printf("平方根: sqrt(16) = %.2f\n", sqrt(16));
    printf("幂运算: power(2, 3) = %.2f\n", power(2, 3));
    printf("素数判断: is_prime(97) = %s\n", is_prime(97) ? "是素数" : "不是素数");
    printf("最大公约数: gcd(48, 36) = %d\n", gcd(48, 36));
    printf("最小公倍数: lcm(48, 36) = %d\n", lcm(48, 36));
    
    printf("\n===== 示例程序结束 =====\n");
    return 0;
}