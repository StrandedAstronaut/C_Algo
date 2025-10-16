#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "math/math.h"

// ���Ե�����
#define TEST_POINTS 100000
// �ظ����Դ������������ܲ��ԣ�
#define TEST_ITERATIONS 1000

// ���ɲ�������
void generate_test_data(double* data, int count) {
    for (int i = 0; i < count; i++) {
        // ����0.1��10000֮��������
        data[i] = 0.1 + ((double)rand() / RAND_MAX) * 9999.9;
    }
}

// ����log2�����ľ���
void test_log2_precision(double* data, int count) {
    printf("\n=== log2�������Ȳ��� ===\n");
    printf("%-15s | %-20s | %-20s | %-20s | %-20s\n",
           "����ֵ", "custom_log2���", "��׼��log2���", "�������", "������");
    printf("--------------------------------------------------------------------------------------------\n");
    
    double max_abs_error = 0.0;
    double max_rel_error = 0.0;
    double avg_abs_error = 0.0;
    double avg_rel_error = 0.0;
    
    // ֻ��ʾ����������ÿ1000��ѡһ����
    for (int i = 0; i < count; i++) {
        double x = data[i];
        double custom_result = custom_log2(x);
        double std_result = log2(x);
        double abs_error = fabs(custom_result - std_result);
        double rel_error = std_result == 0 ? abs_error : abs_error / fabs(std_result);
        
        // ����ͳ����Ϣ
        max_abs_error = fmax(max_abs_error, abs_error);
        max_rel_error = fmax(max_rel_error, rel_error);
        avg_abs_error += abs_error;
        avg_rel_error += rel_error;
        
        // ��ʾ���ֽ��
        if (i % 10000 == 0) {
            printf("%.10lf | %.15lf | %.15lf | %.15lf | %.15lf\n",
                   x, custom_result, std_result, abs_error, rel_error);
        }
    }
    
    avg_abs_error /= count;
    avg_rel_error /= count;
    
    printf("\n����ͳ�ƣ�\n");
    printf("���������: %.15lf\n", max_abs_error);
    printf("���������: %.15lf\n", max_rel_error);
    printf("ƽ���������: %.15lf\n", avg_abs_error);
    printf("ƽ��������: %.15lf\n", avg_rel_error);
}

// ����log10�����ľ���
void test_log10_precision(double* data, int count) {
    printf("\n=== log10�������Ȳ��� ===\n");
    printf("%-15s | %-20s | %-20s | %-20s | %-20s\n",
           "����ֵ", "custom_log10���", "��׼��log10���", "�������", "������");
    printf("--------------------------------------------------------------------------------------------\n");
    
    double max_abs_error = 0.0;
    double max_rel_error = 0.0;
    double avg_abs_error = 0.0;
    double avg_rel_error = 0.0;
    
    // ֻ��ʾ����������ÿ1000��ѡһ����
    for (int i = 0; i < count; i++) {
        double x = data[i];
        double custom_result = custom_log10(x);
        double std_result = log10(x);
        double abs_error = fabs(custom_result - std_result);
        double rel_error = std_result == 0 ? abs_error : abs_error / fabs(std_result);
        
        // ����ͳ����Ϣ
        max_abs_error = fmax(max_abs_error, abs_error);
        max_rel_error = fmax(max_rel_error, rel_error);
        avg_abs_error += abs_error;
        avg_rel_error += rel_error;
        
        // ��ʾ���ֽ��
        if (i % 10000 == 0) {
            printf("%.10lf | %.15lf | %.15lf | %.15lf | %.15lf\n",
                   x, custom_result, std_result, abs_error, rel_error);
        }
    }
    
    avg_abs_error /= count;
    avg_rel_error /= count;
    
    printf("\n����ͳ�ƣ�\n");
    printf("���������: %.15lf\n", max_abs_error);
    printf("���������: %.15lf\n", max_rel_error);
    printf("ƽ���������: %.15lf\n", avg_abs_error);
    printf("ƽ��������: %.15lf\n", avg_rel_error);
}

// ����log2����������
void test_log2_performance(double* data, int count, int iterations) {
    printf("\n=== log2�������ܲ��� ===\n");
    
    // Ԥ��
    double sum1 = 0.0, sum2 = 0.0;
    for (int i = 0; i < count; i++) {
        sum1 += custom_log2(data[i]);
        sum2 += log2(data[i]);
    }
    
    // �����Զ���log2
    clock_t start = clock();
    double custom_sum = 0.0;
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < count; i++) {
            custom_sum += custom_log2(data[i]);
        }
    }
    clock_t end = clock();
    double custom_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    // ���Ա�׼��log2
    start = clock();
    double std_sum = 0.0;
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < count; i++) {
            std_sum += log2(data[i]);
        }
    }
    end = clock();
    double std_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("�Զ���log2ʱ��: %.6lf ��\n", custom_time);
    printf("��׼��log2ʱ��: %.6lf ��\n", std_time);
    printf("���ܱ�: %.2lf�� (��ֵԽ���ʾ��׼��Խ��)\n", custom_time / std_time);
    
    // ��ֹ�������Ż�������
    printf("\n������У�� (��ֹ�Ż�):\n");
    printf("�Զ���log2�ܺ�: %.10lf\n", custom_sum);
    printf("��׼��log2�ܺ�: %.10lf\n", std_sum);
}

// ����log10����������
void test_log10_performance(double* data, int count, int iterations) {
    printf("\n=== log10�������ܲ��� ===\n");
    
    // Ԥ��
    double sum1 = 0.0, sum2 = 0.0;
    for (int i = 0; i < count; i++) {
        sum1 += custom_log10(data[i]);
        sum2 += log10(data[i]);
    }
    
    // �����Զ���log10
    clock_t start = clock();
    double custom_sum = 0.0;
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < count; i++) {
            custom_sum += custom_log10(data[i]);
        }
    }
    clock_t end = clock();
    double custom_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    // ���Ա�׼��log10
    start = clock();
    double std_sum = 0.0;
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < count; i++) {
            std_sum += log10(data[i]);
        }
    }
    end = clock();
    double std_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("�Զ���log10ʱ��: %.6lf ��\n", custom_time);
    printf("��׼��log10ʱ��: %.6lf ��\n", std_time);
    printf("���ܱ�: %.2lf�� (��ֵԽ���ʾ��׼��Խ��)\n", custom_time / std_time);
    
    // ��ֹ�������Ż�������
    printf("\n������У�� (��ֹ�Ż�):\n");
    printf("�Զ���log10�ܺ�: %.10lf\n", custom_sum);
    printf("��׼��log10�ܺ�: %.10lf\n", std_sum);
}

int main() {
    printf("�����������������ܲ���\n");
    printf("========================\n");
    
    // ��ʼ�������������
    srand((unsigned int)time(NULL));
    
    // ������������ڴ�
    double* test_data = (double*)malloc(TEST_POINTS * sizeof(double));
    if (!test_data) {
        fprintf(stderr, "�ڴ����ʧ��\n");
        return 1;
    }
    
    // ���ɲ�������
    generate_test_data(test_data, TEST_POINTS);
    
    // ���Ȳ���
    test_log2_precision(test_data, TEST_POINTS);
    test_log10_precision(test_data, TEST_POINTS);
    
    // ���ܲ��ԣ����͵��������Ա��ⳬʱ��
    test_log2_performance(test_data, TEST_POINTS, TEST_ITERATIONS / 10);
    test_log10_performance(test_data, TEST_POINTS, TEST_ITERATIONS / 10);
    
    // �ͷ��ڴ�
    free(test_data);
    
    printf("\n�������\n");
    return 0;
}