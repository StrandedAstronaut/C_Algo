#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "math/math.h"

// 测试点数量
#define TEST_POINTS 100000
// 重复测试次数（用于性能测试）
#define TEST_ITERATIONS 1000

// 生成测试数据
void generate_test_data(double* data, int count) {
    for (int i = 0; i < count; i++) {
        // 生成0.1到10000之间的随机数
        data[i] = 0.1 + ((double)rand() / RAND_MAX) * 9999.9;
    }
}

// 测试log2函数的精度
void test_log2_precision(double* data, int count) {
    printf("\n=== log2函数精度测试 ===\n");
    printf("%-15s | %-20s | %-20s | %-20s | %-20s\n",
           "输入值", "custom_log2结果", "标准库log2结果", "绝对误差", "相对误差");
    printf("--------------------------------------------------------------------------------------------\n");
    
    double max_abs_error = 0.0;
    double max_rel_error = 0.0;
    double avg_abs_error = 0.0;
    double avg_rel_error = 0.0;
    
    // 只显示部分样本（每1000个选一个）
    for (int i = 0; i < count; i++) {
        double x = data[i];
        double custom_result = custom_log2(x);
        double std_result = log2(x);
        double abs_error = fabs(custom_result - std_result);
        double rel_error = std_result == 0 ? abs_error : abs_error / fabs(std_result);
        
        // 更新统计信息
        max_abs_error = fmax(max_abs_error, abs_error);
        max_rel_error = fmax(max_rel_error, rel_error);
        avg_abs_error += abs_error;
        avg_rel_error += rel_error;
        
        // 显示部分结果
        if (i % 10000 == 0) {
            printf("%.10lf | %.15lf | %.15lf | %.15lf | %.15lf\n",
                   x, custom_result, std_result, abs_error, rel_error);
        }
    }
    
    avg_abs_error /= count;
    avg_rel_error /= count;
    
    printf("\n精度统计：\n");
    printf("最大绝对误差: %.15lf\n", max_abs_error);
    printf("最大相对误差: %.15lf\n", max_rel_error);
    printf("平均绝对误差: %.15lf\n", avg_abs_error);
    printf("平均相对误差: %.15lf\n", avg_rel_error);
}

// 测试log10函数的精度
void test_log10_precision(double* data, int count) {
    printf("\n=== log10函数精度测试 ===\n");
    printf("%-15s | %-20s | %-20s | %-20s | %-20s\n",
           "输入值", "custom_log10结果", "标准库log10结果", "绝对误差", "相对误差");
    printf("--------------------------------------------------------------------------------------------\n");
    
    double max_abs_error = 0.0;
    double max_rel_error = 0.0;
    double avg_abs_error = 0.0;
    double avg_rel_error = 0.0;
    
    // 只显示部分样本（每1000个选一个）
    for (int i = 0; i < count; i++) {
        double x = data[i];
        double custom_result = custom_log10(x);
        double std_result = log10(x);
        double abs_error = fabs(custom_result - std_result);
        double rel_error = std_result == 0 ? abs_error : abs_error / fabs(std_result);
        
        // 更新统计信息
        max_abs_error = fmax(max_abs_error, abs_error);
        max_rel_error = fmax(max_rel_error, rel_error);
        avg_abs_error += abs_error;
        avg_rel_error += rel_error;
        
        // 显示部分结果
        if (i % 10000 == 0) {
            printf("%.10lf | %.15lf | %.15lf | %.15lf | %.15lf\n",
                   x, custom_result, std_result, abs_error, rel_error);
        }
    }
    
    avg_abs_error /= count;
    avg_rel_error /= count;
    
    printf("\n精度统计：\n");
    printf("最大绝对误差: %.15lf\n", max_abs_error);
    printf("最大相对误差: %.15lf\n", max_rel_error);
    printf("平均绝对误差: %.15lf\n", avg_abs_error);
    printf("平均相对误差: %.15lf\n", avg_rel_error);
}

// 测试log2函数的性能
void test_log2_performance(double* data, int count, int iterations) {
    printf("\n=== log2函数性能测试 ===\n");
    
    // 预热
    double sum1 = 0.0, sum2 = 0.0;
    for (int i = 0; i < count; i++) {
        sum1 += custom_log2(data[i]);
        sum2 += log2(data[i]);
    }
    
    // 测试自定义log2
    clock_t start = clock();
    double custom_sum = 0.0;
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < count; i++) {
            custom_sum += custom_log2(data[i]);
        }
    }
    clock_t end = clock();
    double custom_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    // 测试标准库log2
    start = clock();
    double std_sum = 0.0;
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < count; i++) {
            std_sum += log2(data[i]);
        }
    }
    end = clock();
    double std_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("自定义log2时间: %.6lf 秒\n", custom_time);
    printf("标准库log2时间: %.6lf 秒\n", std_time);
    printf("性能比: %.2lf倍 (数值越大表示标准库越快)\n", custom_time / std_time);
    
    // 防止编译器优化掉计算
    printf("\n计算结果校验 (防止优化):\n");
    printf("自定义log2总和: %.10lf\n", custom_sum);
    printf("标准库log2总和: %.10lf\n", std_sum);
}

// 测试log10函数的性能
void test_log10_performance(double* data, int count, int iterations) {
    printf("\n=== log10函数性能测试 ===\n");
    
    // 预热
    double sum1 = 0.0, sum2 = 0.0;
    for (int i = 0; i < count; i++) {
        sum1 += custom_log10(data[i]);
        sum2 += log10(data[i]);
    }
    
    // 测试自定义log10
    clock_t start = clock();
    double custom_sum = 0.0;
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < count; i++) {
            custom_sum += custom_log10(data[i]);
        }
    }
    clock_t end = clock();
    double custom_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    // 测试标准库log10
    start = clock();
    double std_sum = 0.0;
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < count; i++) {
            std_sum += log10(data[i]);
        }
    }
    end = clock();
    double std_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("自定义log10时间: %.6lf 秒\n", custom_time);
    printf("标准库log10时间: %.6lf 秒\n", std_time);
    printf("性能比: %.2lf倍 (数值越大表示标准库越快)\n", custom_time / std_time);
    
    // 防止编译器优化掉计算
    printf("\n计算结果校验 (防止优化):\n");
    printf("自定义log10总和: %.10lf\n", custom_sum);
    printf("标准库log10总和: %.10lf\n", std_sum);
}

int main() {
    printf("对数函数精度与性能测试\n");
    printf("========================\n");
    
    // 初始化随机数生成器
    srand((unsigned int)time(NULL));
    
    // 分配测试数据内存
    double* test_data = (double*)malloc(TEST_POINTS * sizeof(double));
    if (!test_data) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }
    
    // 生成测试数据
    generate_test_data(test_data, TEST_POINTS);
    
    // 精度测试
    test_log2_precision(test_data, TEST_POINTS);
    test_log10_precision(test_data, TEST_POINTS);
    
    // 性能测试（降低迭代次数以避免超时）
    test_log2_performance(test_data, TEST_POINTS, TEST_ITERATIONS / 10);
    test_log10_performance(test_data, TEST_POINTS, TEST_ITERATIONS / 10);
    
    // 释放内存
    free(test_data);
    
    printf("\n测试完成\n");
    return 0;
}