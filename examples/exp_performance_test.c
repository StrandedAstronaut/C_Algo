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
    
    printf("=== custom_exp �������Ⱥ����ܲ��� ===\n\n");
    
    // ���ɲ������ݲ����Ծ���
    double test_values[SAMPLE_COUNT] = {
        -5.0, -3.0, -1.0, -0.5, 0.0,
        0.5, 1.0, 2.0, 3.0, 5.0
    };
    
    printf("=== ���Ȳ������� ===\n");
    printf("����ֵ        | �Զ���exp���    | ��׼��exp���    | �������       | ������\n");
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
        
        // ����ͳ����Ϣ
        if (abs_error > max_abs_error) max_abs_error = abs_error;
        if (rel_error > max_rel_error) max_rel_error = rel_error;
        sum_abs_error += abs_error;
        sum_rel_error += rel_error;
        
        printf("%12.6f | %15.8f | %15.8f | %12.8f | %12.8f\n",
               x, custom_result, std_result, abs_error, rel_error);
    }
    
    printf("\n����ͳ�ƣ�\n");
    printf("���������: %f\n", max_abs_error);
    printf("���������: %f\n", max_rel_error);
    printf("ƽ���������: %f\n", sum_abs_error / SAMPLE_COUNT);
    printf("ƽ��������: %f\n\n", sum_rel_error / SAMPLE_COUNT);
    
    // ���ܲ���
    printf("=== custom_exp �������ܲ��� ===\n");
    
    // Ϊ���ܲ���׼������
    double *data = (double *)malloc(TEST_COUNT * sizeof(double));
    if (!data) {
        printf("�ڴ����ʧ��\n");
        return 1;
    }
    
    // ���ɲ������ݣ���Χ [-5.0, 5.0]
    for (int i = 0; i < TEST_COUNT; i++) {
        data[i] = ((double)rand() / RAND_MAX) * 10.0 - 5.0;
    }
    
    // �����Զ���exp��������
    clock_t start = clock();
    double custom_sum = 0.0;
    for (int i = 0; i < TEST_COUNT; i++) {
        custom_sum += custom_exp(data[i]);
    }
    clock_t end = clock();
    double custom_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    // ���Ա�׼��exp��������
    start = clock();
    double std_sum = 0.0;
    for (int i = 0; i < TEST_COUNT; i++) {
        std_sum += exp(data[i]);
    }
    end = clock();
    double std_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("�Զ���expʱ��: %f ��\n", custom_time);
    printf("��׼��expʱ��: %f ��\n", std_time);
    printf("���ܱ�: %.2f�� (��ֵԽ���ʾ��׼��Խ��)\n\n", custom_time / std_time);
    
    printf("������У�� (��ֹ�Ż�):\n");
    printf("�Զ���exp�ܺ�: %f\n", custom_sum);
    printf("��׼��exp�ܺ�: %f\n", std_sum);
    printf("�������: %f\n", fabs(custom_sum - std_sum));
    
    free(data);
    printf("\n�������\n");
    
    return 0;
}