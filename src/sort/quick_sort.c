/*
 * ���������㷨ʵ��
 * ����������һ�ָ�Ч�ķ��������㷨��ƽ��ʱ�临�Ӷ�ΪO(n log n)
 * ��ʵ�ֲ���Lomuto����������ѡ�����ұ�Ԫ����Ϊ��׼
 */
#include "../../include/sort/quick_sort.h"

/**
 * @brief ��������������λ��
 * 
 * @param a ָ���һ��������ָ��
 * @param b ָ��ڶ���������ָ��
 */
static void swap(int* a, int* b) {
    int temp = *a;    // ��ʱ����a��ֵ
    *a = *b;          // ��b��ֵ����a
    *b = temp;        // ����ʱ�����aֵ����b
}

/**
 * @brief ��������ķ�������
 * 
 * ѡ�����ұߵ�Ԫ����Ϊ��׼(pivot)��
 * ��С�ڵ��ڻ�׼��Ԫ�ط��ڻ�׼����࣬
 * �����ڻ�׼��Ԫ�ط��ڻ�׼���Ҳࡣ
 * 
 * @param arr ������������
 * @param low ��������ʼ����
 * @param high �����Ľ�������
 * @return int ��׼Ԫ�ص�����λ��
 */
static int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // ѡ�����ұߵ�Ԫ����Ϊ��׼
    int i = (low - 1);      // i��ʾС�ڵ��ڻ�׼����ı߽�
    
    // �����������������˻�׼Ԫ�أ�
    for (int j = low; j <= high - 1; j++) {
        // �����ǰԪ��С�ڵ��ڻ�׼
        if (arr[j] <= pivot) {
            i++;                      // ��չС�ڵ��ڻ�׼������
            swap(&arr[i], &arr[j]);   // ����ǰԪ�ؽ�����С�ڵ��ڻ�׼������
        }
    }
    
    // ����׼Ԫ�طŵ�������λ��
    swap(&arr[i + 1], &arr[high]);
    
    // ���ػ�׼Ԫ�ص�����
    return (i + 1);
}

/**
 * @brief ��������������
 * 
 * ʹ�÷��η��ݹ�ض������������
 * 
 * @param arr �����������
 * @param low �������ʼ����
 * @param high ����Ľ�������
 */
void quick_sort(int arr[], int low, int high) {
    // ��������������ʼ�������ڵ��ڽ������������������ֻ��0����1��Ԫ�أ�������
    if (low < high) {
        // ִ�з�����������ȡ��׼Ԫ�ص�λ��
        int pi = partition(arr, low, high);
        
        // �ݹ������׼Ԫ������������
        quick_sort(arr, low, pi - 1);
        
        // �ݹ������׼Ԫ���Ҳ��������
        quick_sort(arr, pi + 1, high);
    }
}
    