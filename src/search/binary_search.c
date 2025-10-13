/**
 * ���ֲ����㷨ʵ��
 * ���ֲ�����һ�������������в����ض�Ԫ�صĸ�Ч�����㷨��
 * ͨ�����������������۰�������������Χ��ʱ�临�Ӷ�ΪO(log n)
 */
#include "../../include/search/binary_search.h"

/**
 * @brief ���ֲ���������
 * 
 * @param arr �����������飨�������У�
 * @param n ���鳤��
 * @param target Ҫ���ҵ�Ŀ��ֵ
 * @return int ����ҵ�Ŀ��ֵ�����������������򷵻�-1
 */
int binary_search(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    // ���������䲻Ϊ��ʱ��������
    while (left <= right) {
        // �����м��������������������д����
        int mid = left + (right - left) / 2;
        
        // ����м�Ԫ�ؾ���Ŀ��ֵ������������
        if (arr[mid] == target) {
            return mid;
        }
        
        // ���Ŀ��ֵ�����м�Ԫ�أ����Ұ벿�ּ�������
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // ���Ŀ��ֵС���м�Ԫ�أ�����벿�ּ�������
        else {
            right = mid - 1;
        }
    }
    
    // δ�ҵ�Ŀ��ֵ������-1
    return -1;
}