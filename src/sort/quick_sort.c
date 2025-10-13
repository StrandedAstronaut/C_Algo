/*
 * 快速排序算法实现
 * 快速排序是一种高效的分治排序算法，平均时间复杂度为O(n log n)
 * 本实现采用Lomuto分区方案，选择最右边元素作为基准
 */
#include "../../include/sort/quick_sort.h"

/**
 * @brief 交换两个整数的位置
 * 
 * @param a 指向第一个整数的指针
 * @param b 指向第二个整数的指针
 */
static void swap(int* a, int* b) {
    int temp = *a;    // 临时保存a的值
    *a = *b;          // 将b的值赋给a
    *b = temp;        // 将临时保存的a值赋给b
}

/**
 * @brief 快速排序的分区操作
 * 
 * 选择最右边的元素作为基准(pivot)，
 * 将小于等于基准的元素放在基准的左侧，
 * 将大于基准的元素放在基准的右侧。
 * 
 * @param arr 待分区的数组
 * @param low 分区的起始索引
 * @param high 分区的结束索引
 * @return int 基准元素的最终位置
 */
static int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选择最右边的元素作为基准
    int i = (low - 1);      // i表示小于等于基准区域的边界
    
    // 遍历整个分区（除了基准元素）
    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于等于基准
        if (arr[j] <= pivot) {
            i++;                      // 扩展小于等于基准的区域
            swap(&arr[i], &arr[j]);   // 将当前元素交换到小于等于基准的区域
        }
    }
    
    // 将基准元素放到其最终位置
    swap(&arr[i + 1], &arr[high]);
    
    // 返回基准元素的索引
    return (i + 1);
}

/**
 * @brief 快速排序主函数
 * 
 * 使用分治法递归地对数组进行排序。
 * 
 * @param arr 待排序的数组
 * @param low 排序的起始索引
 * @param high 排序的结束索引
 */
void quick_sort(int arr[], int low, int high) {
    // 基本情况：如果起始索引大于等于结束索引，则数组分区只有0个或1个元素，已排序
    if (low < high) {
        // 执行分区操作，获取基准元素的位置
        int pi = partition(arr, low, high);
        
        // 递归排序基准元素左侧的子数组
        quick_sort(arr, low, pi - 1);
        
        // 递归排序基准元素右侧的子数组
        quick_sort(arr, pi + 1, high);
    }
}
    