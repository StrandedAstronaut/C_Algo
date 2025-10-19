#include "../include/sort/sort.h"
#include <stdio.h>

/**
 * @brief ��ӡ����Ԫ��
 * 
 * @param arr ����ӡ������
 * @param n ���鳤��
 */
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // ��������
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("ԭʼ����: ");
    print_array(arr1, n);
    
    // ����ð������
    bubble_sort(arr1, n);
    printf("ð�������: ");
    print_array(arr1, n);
    
    // ���Կ�������
    quick_sort(arr2, 0, n - 1);
    printf("���������: ");
    print_array(arr2, n);
    
    return 0;
}