/**
 * 二分查找算法实现
 * 二分查找是一种在有序数组中查找特定元素的高效搜索算法，
 * 通过反复将搜索区间折半来减少搜索范围，时间复杂度为O(log n)
 */
#include "../../include/search/binary_search.h"

/**
 * @brief 二分查找主函数
 * 
 * @param arr 有序整数数组（升序排列）
 * @param n 数组长度
 * @param target 要查找的目标值
 * @return int 如果找到目标值，返回其索引；否则返回-1
 */
int binary_search(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    // 当搜索区间不为空时继续查找
    while (left <= right) {
        // 计算中间索引（避免整数溢出的写法）
        int mid = left + (right - left) / 2;
        
        // 如果中间元素就是目标值，返回其索引
        if (arr[mid] == target) {
            return mid;
        }
        
        // 如果目标值大于中间元素，在右半部分继续查找
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // 如果目标值小于中间元素，在左半部分继续查找
        else {
            right = mid - 1;
        }
    }
    
    // 未找到目标值，返回-1
    return -1;
}