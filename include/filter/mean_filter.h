#ifndef MEAN_FILTER_H
#define MEAN_FILTER_H

/**
 * @file mean_filter.h
 * @brief 均值滤波算法接口定义
 */

/**
 * @brief 一维信号的均值滤波
 * 
 * 均值滤波是一种简单的线性滤波算法，它将每个采样点的值替换为其周围
 * 相邻采样点的平均值，用于消除噪声。
 * 
 * @param input 输入信号数组
 * @param output 输出信号数组
 * @param length 信号长度
 * @param window_size 滤波窗口大小（奇数）
 * 
 * @note 输入和输出数组可以是同一个数组，但最好使用不同的数组以避免数据覆盖
 * @warning 确保window_size为奇数，否则可能导致意外行为
 */
void mean_filter_1d(double input[], double output[], int length, int window_size);

// 以下是尚未实现的滤波算法接口定义
// 后续可以根据需要实现这些功能

/**
 * @brief 中值滤波算法
 * 
 * @param input 输入信号数组
 * @param output 输出信号数组
 * @param length 信号长度
 * @param window_size 滤波窗口大小（奇数）
 */
// void median_filter_1d(double input[], double output[], int length, int window_size);

/**
 * @brief 高斯滤波算法
 * 
 * @param input 输入信号数组
 * @param output 输出信号数组
 * @param length 信号长度
 * @param kernel_size 高斯核大小（奇数）
 * @param sigma 高斯分布的标准差
 */
// void gaussian_filter_1d(double input[], double output[], int length, int kernel_size, double sigma);

/**
 * @brief 低通滤波器
 * 
 * @param input 输入信号数组
 * @param output 输出信号数组
 * @param length 信号长度
 * @param cutoff_frequency 截止频率（0-1）
 */
// void low_pass_filter(double input[], double output[], int length, double cutoff_frequency);

/**
 * @brief 高通滤波器
 * 
 * @param input 输入信号数组
 * @param output 输出信号数组
 * @param length 信号长度
 * @param cutoff_frequency 截止频率（0-1）
 */
// void high_pass_filter(double input[], double output[], int length, double cutoff_frequency);

/**
 * @brief 带通滤波器
 * 
 * @param input 输入信号数组
 * @param output 输出信号数组
 * @param length 信号长度
 * @param low_cutoff 低截止频率（0-1）
 * @param high_cutoff 高截止频率（0-1）
 */
// void band_pass_filter(double input[], double output[], int length, double low_cutoff, double high_cutoff);

/**
 * @brief 巴特沃斯低通滤波器
 * 
 * @param input 输入信号数组
 * @param output 输出信号数组
 * @param length 信号长度
 * @param order 滤波器阶数
 * @param cutoff_frequency 截止频率（0-1）
 */
// void butterworth_low_pass(double input[], double output[], int length, int order, double cutoff_frequency);

#endif // MEAN_FILTER_H