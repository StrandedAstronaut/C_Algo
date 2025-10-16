#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include "math/math.h"

#define TEST_COUNT 1000000
#define SAMPLE_COUNT 10

int main() {
    srand(time(NULL));
    
    printf("=== custom_exp 函数精度和性能测试 ===\n\n");
    
    // 生成测试数据并测试精度
    double test_values[SAMPLE_COUNT] = {
        -5.0, -3.0, -1.0, -0.5, 0.0,
        0.5, 1.0, 2.0, 3.0, 5.0
    };
    
    printf("=== 精度测试样本 ===\n");
    printf("输入值        | 自定义exp结果    | 标准库exp结果    | 绝对误差       | 相对误差\n");
    printf("----------------------------------------------------------------------------------\n");
    
    double max_abs_error = 0.0;
    double max_rel_error = 0.0;
    double sum_abs_error = 0.0;
    double sum_rel_error = 0.0;
    
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        double x = test_values[i];
        double custom_result = custom_exp(x);
        double std_result = exp(x);
        
        double abs_error = fabs(custom_result - std_result);
        double rel_error = 0.0;
        if (std_result != 0) {
            rel_error = abs_error / fabs(std_result);
        }
        
        // 更新统计信息
        if (abs_error > max_abs_error) max_abs_error = abs_error;
        if (rel_error > max_rel_error) max_rel_error = rel_error;
        sum_abs_error += abs_error;
        sum_rel_error += rel_error;
        
        printf("%12.6f | %15.8f | %15.8f | %12.8f | %12.8f\n",
               x, custom_result, std_result, abs_error, rel_error);
    }
    
    printf("\n精度统计：\n");
    printf("最大绝对误差: %f\n", max_abs_error);
    printf("最大相对误差: %f\n", max_rel_error);
    printf("平均绝对误差: %f\n", sum_abs_error / SAMPLE_COUNT);
    printf("平均相对误差: %f\n\n", sum_rel_error / SAMPLE_COUNT);
    
    // 性能测试
    printf("=== custom_exp 函数性能测试 ===\n");
    
    // 为性能测试准备数据
    double *data = (double *)malloc(TEST_COUNT * sizeof(double));
    if (!data) {
        printf("内存分配失败\n");
        return 1;
    }
    
    // 生成测试数据，范围 [-5.0, 5.0]
    for (int i = 0; i < TEST_COUNT; i++) {
        data[i] = ((double)rand() / RAND_MAX) * 10.0 - 5.0;
    }
    
    // 测试自定义exp函数性能
    clock_t start = clock();
    double custom_sum = 0.0;
    for (int i = 0; i < TEST_COUNT; i++) {
        custom_sum += custom_exp(data[i]);
    }
    clock_t end = clock();
    double custom_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    // 测试标准库exp函数性能
    start = clock();
    double std_sum = 0.0;
    for (int i = 0; i < TEST_COUNT; i++) {
        std_sum += exp(data[i]);
    }
    end = clock();
    double std_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("自定义exp时间: %f 秒\n", custom_time);
    printf("标准库exp时间: %f 秒\n", std_time);
    printf("性能比: %.2f倍 (数值越大表示标准库越快)\n\n", custom_time / std_time);
    
    printf("计算结果校验 (防止优化):\n");
    printf("自定义exp总和: %f\n", custom_sum);
    printf("标准库exp总和: %f\n", std_sum);
    printf("结果差异: %f\n", fabs(custom_sum - std_sum));
    
    free(data);
    printf("\n测试完成\n");
    
    return 0;
}