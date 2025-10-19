#include "../include/sort/sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief ��ӡ��������
 * 
 * @param arr ����ӡ������
 * @param n ���鳤��
 */
void print_int_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief ��ӡ����������
 * 
 * @param arr ����ӡ������
 * @param n ���鳤��
 */
void print_double_array(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.4f ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief ��������
 * 
 * @param src Դ����
 * @param dest Ŀ������
 * @param n ���鳤��
 */
void copy_array(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    // �������������
    srand(time(NULL));
    
    // ���������С
    int n = 10;
    
    // ������������
    int arr_original[] = {64, 34, 25, 12, 22, 11, 90, 88, 77, 45};
    int arr_test[n];
    
    printf("=== �����㷨���� ===\n");
    printf("ԭʼ����: ");
    print_int_array(arr_original, n);
    printf("\n");
    
    // ����ð������
    copy_array(arr_original, arr_test, n);
    bubble_sort(arr_test, n);
    printf("1. ð������: ");
    print_int_array(arr_test, n);
    
    // ���Կ�������
    copy_array(arr_original, arr_test, n);
    quick_sort(arr_test, 0, n - 1);
    printf("2. ��������: ");
    print_int_array(arr_test, n);
    
    // ����ѡ������
    copy_array(arr_original, arr_test, n);
    selection_sort(arr_test, n);
    printf("3. ѡ������: ");
    print_int_array(arr_test, n);
    
    // ���Բ�������
    copy_array(arr_original, arr_test, n);
    insertion_sort(arr_test, n);
    printf("4. ��������: ");
    print_int_array(arr_test, n);
    
    // ���Թ鲢����
    copy_array(arr_original, arr_test, n);
    merge_sort(arr_test, 0, n - 1);
    printf("5. �鲢����: ");
    print_int_array(arr_test, n);
    
    // ���Զ�����
    copy_array(arr_original, arr_test, n);
    heap_sort(arr_test, n);
    printf("6. ������  : ");
    print_int_array(arr_test, n);
    
    // ����ϣ������
    copy_array(arr_original, arr_test, n);
    shell_sort(arr_test, n);
    printf("7. ϣ������: ");
    print_int_array(arr_test, n);
    
    // ���Լ�������
    copy_array(arr_original, arr_test, n);
    int max = 100; // �������ֵ������100
    int output[n];
    counting_sort(arr_test, n, output, max);
    printf("8. ��������: ");
    print_int_array(output, n);
    
    // ���Ի�������
    // ע�⣺��������Ҫ��Ԫ��Ϊ�Ǹ���
    copy_array(arr_original, arr_test, n);
    radix_sort(arr_test, n);
    printf("9. ��������: ");
    print_int_array(arr_test, n);
    
    // ����Ͱ����
    // ע�⣺Ͱ����Ҫ��Ԫ����[0, 1)��Χ��
    double bucket_arr[n];
    printf("\n=== Ͱ������ԣ�����[0,1)��Χ�ڵ��������===\n");
    printf("ԭʼ����: ");
    for (int i = 0; i < n; i++) {
        bucket_arr[i] = (double)rand() / (RAND_MAX + 1.0);
    }
    print_double_array(bucket_arr, n);
    
    bucket_sort(bucket_arr, n);
    printf("Ͱ�����: ");
    print_double_array(bucket_arr, n);
    
    printf("\n���������㷨������ɣ�\n");
    
    return 0;
}