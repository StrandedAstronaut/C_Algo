#ifndef QUICK_SORT_H
#define QUICK_SORT_H

/**
 * @file quick_sort.h
 * @brief ���������㷨�ӿڶ���
 */

/**
 * @brief ���������㷨
 * 
 * ����������һ�ָ�Ч�ıȽ������㷨�����÷��β��Զ������������
 * ��ʵ��ƽ��ʱ�临�Ӷ�ΪO(n log n)������ΪO(n�0�5)���ռ临�Ӷ�ΪO(log n)��
 * 
 * @param arr ���������������
 * @param low �������ʼ������ͨ��Ϊ0��
 * @param high ����Ľ���������ͨ��Ϊ���鳤�ȼ�1��
 * 
 * @note �ú�����ֱ���޸Ĵ�������飬ʹ�䰴��������
 * @warning ȷ��low��high���������鷶Χ�ڣ�������ܵ���δ������Ϊ
 */
void quick_sort(int arr[], int low, int high);

#endif // QUICK_SORT_H
    