/**
 * 均值滤波算法实现
 * 均值滤波是一种简单的线性滤波方法，用于平滑信号和去除噪声
 * 该实现支持一维信号的均值滤波处理
 */
#include "../../include/filter/mean_filter.h"

/**
 * @brief 一维信号的均值滤波
 * 
 * @param input 输入信号数组
 * @param output 输出信号数组
 * @param length 信号长度
 * @param window_size 滤波窗口大小（奇数）
 */
void mean_filter_1d(double input[], double output[], int length, int window_size) {
    int half_window = window_size / 2;
    int i, j;
    
    // 处理信号的每一个点
    for (i = 0; i < length; i++) {
        double sum = 0.0;
        int count = 0;
        
        // 计算窗口内所有有效点的平均值
        for (j = -half_window; j <= half_window; j++) {
            int index = i + j;
            
            // 检查索引是否在有效范围内
            if (index >= 0 && index < length) {
                sum += input[index];
                count++;
            }
        }
        
        // 计算平均值
        if (count > 0) {
            output[i] = sum / count;
        } else {
            output[i] = input[i];  // 以防万一（正常情况下不会发生）
        }
    }
}